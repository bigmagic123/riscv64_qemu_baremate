project('virt_test', 'c')

sources = []
inc     = []

inc += include_directories('configs')

subdir( 'application' )
subdir( 'driver' )
subdir( 'src' )

add_project_arguments('-O2', '-march=rv64gcv_zba_zbb_zbc_zbs' ,'-mabi=lp64d','-fno-omit-frame-pointer', '-nostartfiles', '-MD', '-mcmodel=medany', '-ffreestanding', '-fno-common' ,'-nostdlib', '-mno-relax', language: 'c')

linker_script = join_paths(meson.current_source_dir(), 'link.ld')
linker_script_board = join_paths(meson.current_source_dir(), 'configs/link_board.lds')

add_project_link_arguments('-T', linker_script_board, '-T', linker_script ,'-nostdlib', '-nostartfiles', language: 'c')

exe = executable('virt_test.elf', sources, include_directories:[inc])

hex = custom_target('demo.bin',
  build_by_default: true,
  input : exe,
  output : 'demo.bin',
  command : [meson.get_external_property('objcopy'), '-O', 'binary','@INPUT@','@OUTPUT@'],
)

dump = custom_target('demo.dump',
  capture          : true,
  build_by_default: true,
  input : exe,
  output : 'demo.dump',
  command : [meson.get_external_property('objdump'), '-D', '-S', '-t', '@INPUT@'],
)