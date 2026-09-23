amdhip_src = [
  'amdhip64_main.c'
]

thread_dep = dependency('threads')

amdhip_dep = meson.get_compiler('c').find_library('amdhip64', dirs: ['/opt/rocm/lib'])

shared_library(
  'amdhip_7.dll',
  amdhip_src,
  name_prefix: '',
  dependencies: [ amdhip_dep, thread_dep, lib_dl],
  include_directories : [ include_path, '/opt/rocm/include' ],
  link_depends: ['amdhip64.spec'],
  link_args: [meson.current_source_dir() / 'amdhip64.spec'],
  install: true,
  install_dir: install_dir_unix,
  c_args              : [ '-D__HIP_PLATFORM_AMD__' ],
)