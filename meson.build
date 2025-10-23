project('BotInterface', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++20'])

# Dependency setup
gtkmm_dep = dependency('gtkmm-4.0', required: true)
libsigcpp_dep = dependency('sigc++-3.0', required: true)
json_dep = dependency('nlohmann_json', required: true)
libsodium_dep = dependency('libsodium', required: true)

# Download cpp-httplib.h start
lib_dir = 'lib'

httplib_url = 'https://raw.githubusercontent.com/yhirose/cpp-httplib/refs/heads/master/httplib.h'
httplib_file = join_paths(lib_dir, 'httplib.h')
download_httplib = run_command('curl', '-L', httplib_url, '-o', httplib_file)

if download_httplib.returncode() != 0
    error('Failed to download httplib.h')
endif

inc = include_directories(lib_dir)
# Download cpp-httplib.h end

# Create the executable
BotInterface = executable(  'BotInterface',
                            'src/main.cpp',
                            'src/shared.cpp',
                            'src/io/jsonio.cpp',
                            'src/encryption/crypto.cpp',
                            'src/ui/mainWindow.cpp',
                            'src/ui/pageControl.cpp',
                            'src/ui/pageSettings.cpp',
                            'src/ui/pageStats.cpp',
                            'src/ui/pageLogin.cpp',
                            install: true,
                            dependencies: [gtkmm_dep, libsigcpp_dep, json_dep, libsodium_dep],
                            win_subsystem : 'windows'
                         )
