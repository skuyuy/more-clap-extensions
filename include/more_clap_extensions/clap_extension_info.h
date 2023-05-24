#pragma once
#include <clap/clap.h>

static CLAP_CONSTEXPR const char CLAP_EXT_EXTENSION_INFO[] = "skuyuy.extension-info";

/* extension_info
Use this extension to query information about supported extensions of a plugin or host. This can be used to e.g. conveniently load all extensions of a plugin.

Usage example:

// assume get_plugin() returns a valid <const clap_plugin*>
const clap_plugin* plugin = get_plugin();
const plugin_extension_info* plugin_ext_info = (plugin_extension_info*) plugin->get_extension(plugin, "skuyuy.extension-info");

extension_info info {};
bool result = plugin_ext_info_handle->get(plugin, &info);

// get all extensions and add them with a function register_extension_handle. Assume this does whatever it needs to do
if(result)
{
    for(uint32_t i = 0; i < info.count; i++)
    {
        const char* id = info.ids[i];
        const void* extension = plugin->get_extension(plugin, id);

        register_extension_handle(id, extension);
    }
}

*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief A structure containing information about extensions
*/
typedef struct extension_info
{
    /**
     * @brief The amount of extensions supported by the plugin / host. Also corresponds to the size for <ids>
    */
    uint32_t count;
    /**
     * @brief The identifiers of supported extensions.
    */
    const char* const* ids;
} extension_info_t;

/**
 * @brief Handle for the plugin-side extension
*/
typedef struct plugin_extension_info
{
    /**
     * @brief Used to query information about a plugins extensions. The implementor has to fill the extension_info struct with the necessary data
    */
    bool(CLAP_ABI *get)(const clap_plugin_t* plugin, extension_info_t* info);
    /**
     * @brief Used to query if a extension is supported by a plugin.
    */
    bool(CLAP_ABI *is_extension_supported)(const clap_plugin_t* plugin, const char* id);
} plugin_extension_info_t;

/**
 * @brief Handle for the host-side extension
*/
typedef struct host_extension_info
{
    /**
     * @brief Used to query information about a hosts extensions. The implementor has to fill the extension_info struct with the necessary data
    */
    bool(CLAP_ABI *get)(const clap_host_t* plugin, extension_info_t* info);
    /**
     * @brief Used to query if a extension is supported by a host.
    */
    bool(CLAP_ABI *is_extension_supported)(const clap_host_t* plugin, const char* id);
} host_extension_info_t;

#ifdef __cplusplus
}
#endif