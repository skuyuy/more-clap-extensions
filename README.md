# more-clap-extensions
Collection of handy extensions for the CLAP plugin format.

## extension_info (ID: `'skuyuy.extension-info'`)
Use `extension_info` to query information about a plugins / hosts supported extensions
### `struct extension_support_info`
Structure containing information about extensions.
- `uint32_t count`: The count of supported extensions which also corresponds to the size of `ids`.
- `const char* const* ids`: An array of strings of supported extension ids.
### `struct plugin_extension_info`
#### `bool get(const clap_plugin_t* plugin, extension_support_info* info)`
Query a plugin to fill `info`. Returns `true` if `info` has been successfully filled, otherwise returns `false`.
#### `bool is_extension_supported(const clap_plugin_t* plugin, const char* id)`
Returns wether a plugin supports an extension.
### `struct host_extension_info`
#### `bool get(const clap_host_t* host, extension_support_info* info)`
Query a host to fill `info`. Returns `true` if `info` has been successfully filled, otherwise returns `false`.
#### `bool is_extension_supported(const clap_host_t* host, const char* id)`
Returns wether a host supports an extension.
