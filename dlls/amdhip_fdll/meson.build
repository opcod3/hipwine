amdhip_res = custom_target(
  'amdhip.res',
  output: 'amdhip64.res',
  input: 'amdhip64.rc',
  command: [
    wrc,
    '-I', meson.project_source_root() + '/include',
    '-o', '@OUTPUT@',
    '@INPUT@',
  ],
  install: false,
)

amdhip_def = custom_target(
  'amdhip.def',
  output: 'amdhip.def',
  input: '../amdhip/amdhip64.spec',
  command: [winebuild, target_arch, '-w', '--def', '-o', '@OUTPUT@', '-E', '@INPUT@'],
  install: false,
)

custom_target(
  'amdhip64.dll',
  output: 'amdhip64.dll',
  input: [amdhip_def, amdhip_res],
  command: [
    winebuild,
    target_arch,
    '--dll',
    '--fake-module',
    '-o', '@OUTPUT@',
    '-E', '@INPUT@',
  ],
  install: true,
  install_dir: install_dir_windows,
)
