project('BotInterface', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++20'])

# Dependency setup for gtkmm
gtkmm_dep = dependency('gtkmm-4.0', required: true)

# Create the executable
BotInterface = executable('BotInterface', 'headers/mainWindow.h', 'src/mainWindow.cpp', 'src/main.cpp', install : true, dependencies : gtkmm_dep)

# Add a test for the executable
test('test', BotInterface)
