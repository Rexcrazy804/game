{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system;};

    program = pkgs.callPackage ./app.nix {};
  in {
    packages.x86_64-linux.default = program;
    devShell.${system} = pkgs.mkShell {
      buildInputs = [pkgs.sfml];
    };
  };
}
