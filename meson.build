project('BotInterface', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++20'])

# Dependency setup for gtkmm
gtkmm_dep = dependency('gtkmm-4.0', required: true)
libsigcpp = dependency('sigc++-3.0', required: true)

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
                            'src/ui/mainWindow.cpp',
                            'src/ui/pageControl.cpp',
                            'src/ui/pageSettings.cpp',
                            'src/ui/pageStats.cpp',
                            install: true,
                            dependencies: [gtkmm_dep, libsigcpp],
                            win_subsystem : 'windows'
                         )
