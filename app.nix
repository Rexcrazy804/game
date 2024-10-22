{
  stdenv,
  pkg-config,
  meson,
  ninja,
  makeWrapper,
  sfml,
}:
stdenv.mkDerivation rec {
  pname = "pink-pong";
  version = "0.2.2";
  src = ./.;

  nativeBuildInputs = [
    meson
    ninja
    pkg-config
    makeWrapper
  ];

  buildInputs = [
    sfml
  ];

  postFixup = ''
    wrapProgram $out/bin/${pname} --chdir $out/share/${pname}
  '';
}
