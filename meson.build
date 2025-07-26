project('mshio', 'cpp',
  version : '0.0.1',
  default_options : ['warning_level=3', 'cpp_std=c++26'])


headers = [
'include/mshio/MshSpec.h',
'include/mshio/MshSpecExt.h',
'include/mshio/exception.h',
'include/mshio/mshio.h']




sources = [
'src/element_utils.h',
'src/io_utils.h',
'src/load_msh_curves.h',
'src/load_msh_data.h',
'src/load_msh_elements.h',
'src/load_msh_entities.h',
'src/load_msh_format.h',
'src/load_msh_nanospline_format.h',
'src/load_msh_nodes.h',
'src/load_msh_patches.h',
'src/load_msh_physical_groups.h',
'src/load_msh_post_process.h',
'src/save_msh_curves.h',
'src/save_msh_data.h',
'src/save_msh_elements.h',
'src/save_msh_entities.h',
'src/save_msh_format.h',
'src/save_msh_nanospline_format.h',
'src/save_msh_nodes.h',
'src/save_msh_patches.h',
'src/save_msh_physical_groups.h',
'src/element_utils.cpp',
'src/io_utils.cpp',
'src/load_msh.cpp',
'src/load_msh_curves.cpp',
'src/load_msh_data.cpp',
'src/load_msh_elements.cpp',
'src/load_msh_entities.cpp',
'src/load_msh_format.cpp',
'src/load_msh_nodes.cpp',
'src/load_msh_patches.cpp',
'src/load_msh_physical_groups.cpp',
'src/load_msh_post_process.cpp',
'src/save_msh.cpp',
'src/save_msh_curves.cpp',
'src/save_msh_data.cpp',
'src/save_msh_elements.cpp',
'src/save_msh_entities.cpp',
'src/save_msh_format.cpp',
'src/save_msh_nodes.cpp',
'src/save_msh_patches.cpp',
'src/save_msh_physical_groups.cpp',
'src/validate_spec.cpp',
]


include_dirs = [include_directories('include')]

zipper_proj = subproject('zipper')
zipper_dep = zipper_proj.get_variable('zipper_dep')

#assert(!get_option('nanospline'), 'meson can\'t do nanobind yet')
cpp_defines = []
if get_option('nanospline')
  cpp_defines += ['-DMSHIO_EXT_NANOSPLINE']
endif

assert(not get_option('python'), 'meson can\'t do nanobind yet')

mshio_lib = library('mshio', sources + headers, include_directories: include_dirs, cpp_args: cpp_defines, dependencies: [zipper_dep])

mshio_dep = declare_dependency(link_with: mshio_lib, dependencies: [zipper_dep], include_directories: include_dirs)



if get_option('examples')
  msh_inspect_bin = executable('mesh_inspect', sources: ['examples/msh_inspect.cpp'], dependencies: [mshio_dep])
endif

if get_option('testing')
  # catch2__dep = dependency('catch2')
  catch2_with_main_dep = dependency('catch2-with-main')
  
  
  test_defines = {'MSHIO_DATA_DIR':'${PROJECT_SOURCE_DIR}/data'}
  test_sources = glob('{}tests/*.cpp')
  
  # TODO: replace my_lib with the own lib
  test_mshio = executable('test_mshio', dependencies: [my_lib_dep, catch2_with_main_dep], cpp_defines: test_defines)
  
  test('mshio', test_hello_world)
  #if(NOT MSVC)
  #    target_compile_options(test_MshIO PRIVATE -Wconversion -Wall -Werror)
  #else()
  #    target_compile_options(test_MshIO PRIVATE "/MP")
  #endif()

  #if (SANITIZE_ADDRESS OR
  #        SANITIZE_LINK_STATIC OR
  #        SANITIZE_MEMORY OR
  #        SANITIZE_THREAD OR
  #        SANITIZE_UNDEFINED)
  #    add_sanitizers(test_MshIO)
  #endif()
endif



