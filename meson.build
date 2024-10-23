project(
  'pink-pong', 
  'cpp',
  version: '0.2.3', 
  license: 'Unlicense', 
  license_files: ['UNLICENSE'])

sources = files(
  'src/main.cpp',
  'src/Square.cpp',
  'src/Paddle.cpp')

sfmldeps = [
  dependency('sfml-graphics'),
  dependency('sfml-window'),
  dependency('sfml-system'),
  dependency('sfml-audio')]

executable(
  'pink-pong', 
  sources, 
  dependencies: sfmldeps, 
  install: true)

install_subdir(
  'assets', 
  install_dir: get_option('datadir') / 'pink-pong')

install_data(
  'desktopAssets/icon.svg', 
  install_dir: get_option('datadir') / 'icons/hicolor/scalable/apps', 
  rename: 'pink-pong')

install_data(
  'desktopAssets/pink-pong.desktop', 
  install_dir: get_option('datadir') / 'applications')
