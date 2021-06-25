# WordWrap
Solution to the Word Wrap problem using dynamic programming.

# Build
## Introdução
Install [vcpkg](https://docs.microsoft.com/pt-br/cpp/build/vcpkg),
cpp package manager for Linux, Windows and macOS and download
the argtable3 package. Here we will cover how to install for Debian
without root and sudo only.

## Prerequisites
 - git
 - g++
 - argtable3 - v3.1.5

## Step by step
```
cd ~
sudo apt-get install git
sudo apt-get install g++
git clone https://github.com/Microsoft/vcpkg
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg install argtable3
sudo rm --recursive ./vcpkg
git clone https://github.com/barbaradarques/WordWrap
cd WordWrap
make
./build/wrapper --help
./build/wrapper --len 20 "Ready, code working and here is your first wrap text."
```

# TroubleShooting
 - if you need, you can install argtable3 directly from the official [repository](https://github.com/argtable/argtable3).
 - you should see [WordWrap_py](https://github.com/AlexandroGonSan/WordWrap_py)
