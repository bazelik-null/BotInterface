project('BotInterface', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++20'])

# Dependency setup for gtkmm
gtkmm_dep = dependency('gtkmm-4.0', required: true)
libsigcpp = dependency('sigc++-3.0', required: true)

# Create the executable
BotInterface = executable(  'BotInterface',
                            'src/main.cpp',
                            'src/shared.cpp',
                            'src/ui/mainWindow.cpp',
                            'src/ui/pageControl.cpp',
                            'src/ui/pageSettings.cpp',
                            'src/ui/pageStats.cpp',
                            install: true,
                            dependencies: [gtkmm_dep, libsigcpp]
                         )
