{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: let 
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system;};

    program = let 
      desktopItem = pkgs.makeDesktopItem {
        name = "pink-pong";
        exec = "pink-pong";
        comment = "A simple pong clone written in C++ using sfml library";
        desktopName = "Pink Pong";
        categories = ["Game"];
        icon = ./assets/icon.png;
      };
    in pkgs.stdenv.mkDerivation rec {
      pname = "pink-pong";
      version = "0.2.0";
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

        mkdir -p $out/share/applications
        cp ${desktopItem}/share/applications/* $out/share/applications
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
