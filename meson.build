project(
    'neutron',
    'c',
    version : '1.0.0',
    license : 'GPLv3',
    default_options : [
      'c_std=c99',
      'buildtype=release',
      'default_library=shared',
      'optimization=3',
      'b_lto=false',
    ]
)

cflags = '-Wall'
macros = '-DVERSION="1.0.0"'
inc = include_directories('include')

executable( 
    meson.project_name(),

    'src/main.c',
    'src/cli.c',
    'src/preprocessor.c',
    'src/interpreter.c',
    'src/tokens.c',
    'src/util.c',
    
    c_args: [cflags, macros],
    # dependencies: ,
    include_directories: inc
)

executable(
    'spec',

    'spec/main.c',

    'src/cli.c',
    'src/preprocessor.c',
    'src/interpreter.c',
    'src/tokens.c',
    'src/util.c',

    include_directories: inc
)