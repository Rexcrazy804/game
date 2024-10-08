{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: let 
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system;};

    program = pkgs.stdenv.mkDerivation rec {
      pname = "paddle-game";
      version = "0.1.69";
      src = ./.;

      nativeBuildInputs = [
        pkgs.makeWrapper
      ];

      buildInputs = [
        pkgs.sfml
      ];

      buildPhase = ''
        g++ \
          -c $src/src/*.cpp \
          -I${pkgs.lib.makeIncludePath buildInputs}

        g++ \
          *.o -o ${pname} \
          -L${pkgs.lib.makeLibraryPath buildInputs} \
          -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio \
      '';

      installPhase = ''
        mkdir -p $out/bin
        cp ${pname} $out/bin

        mkdir -p $out/share
        cp -r $src/assets/ $out/share/assets
        runHook postInstall
      '';

      postInstall = ''
        wrapProgram $out/bin/${pname} --chdir $out/share/
      '';
    };
  in {
    packages.x86_64-linux.default = program;
    devShell.${system} = pkgs.mkShell {
      buildInputs = [
        pkgs.sfml
      ];
    };
  };
}
