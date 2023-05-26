#pragma once
#include <clap/clap.h>

static CLAP_CONSTEXPR const char CLAP_EXT_HEALTH_CHECK[] = "skuyuy.health-check";

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the possible outcomes of a healthcheck
*/
enum {
    HEALTHCHECK_PASSED = 0,
    HEALTHCHECK_IGNORED,
    HEALTHCHECK_FAILED,
};
typedef int32_t healthcheck_result;

/**
 * @brief A structure containing information about a health check
*/
typedef struct healthcheck_info
{
    /**
     * @brief Result of the health check
    */
    healthcheck_result result;
    /**
     * @brief Timestamp of the health check
    */
    time_t timestamp;
    /**
     * @brief Additional text to send back with the result
     * Can be ignored e.g. on success
    */
    const char* reason;
} healthcheck_info_t;

/**
 * @brief Handle for the plugin extension
*/
typedef struct plugin_health_check
{
    /**
     * @brief Runs a health check on the entire plugin
    */
    void(CLAP_ABI* check_plugin)(const clap_plugin_t* plugin, healthcheck_info_t* info);
    /**
     * @brief Runs a health check on a specific extension
    */
    void(CLAP_ABI* check_extension)(const clap_plugin_t* plugin, const char* id, healthcheck_info_t* info);
} plugin_health_check_t;

#ifdef __cplusplus
}
#endif // __cplusplus