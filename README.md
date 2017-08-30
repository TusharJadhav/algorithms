Welcome to the world of Algorithms and Data structures!

This repository contains implementation of various algorithms and data structures popularly known in the field of computer science. These programs are implemented in C++ and are covered in the Princeton online open course. You can find more about them [here](https://online.princeton.edu/course/algorithms-part-i) and [here](https://online.princeton.edu/course/algorithms-part-ii). I would also like to thank [Robert Sedgewick](https://www.cs.princeton.edu/people/profile/rs) and [Kevin Wayne](https://www.cs.princeton.edu/people/profile/wayne) for creating the contents of this beautiful course in an easy to understand language. I may also occasionally implement other interesting algorithms and data structures, that I come across, as I continue my journey in the field of algorithms and data structures.

# Features
* Implemented as a shared library using modern C++ so that it can be easily integrated into production code if needed
* No depedencies on any 3rd party library
* Unit tests provided to reason for correctness
* Cross Platform since it is written in C++
* Highly efficient and well performing code

# Platforms officially tested on
* Linux
* MacOS
* Windows

All the algorithms and data structures have been implemented as a shared library, popularly known as Shared Object (.so) files on Linux/ MacOS platform and Dynamic Link Library (.DLL) on Windows platform. Since all the programs have been written in C++ then are usuable on all 3 major platforms Linux, MacOS and Windows platform. I have provided a CMake receipe for generating the build files on your favourite operating system for your favourite build system supported by [CMake](https://cmake.org/). Additionally there are unit tests written for all the programs using [Google C++ unit testing framework](https://github.com/google/googletest) which is cross platform as well. The CMake receipe will automatically download and build the Google C++ testing framework. That way the algorithms library, test executable and testing framework will be built with the same compiler/ linker and use the same C++ runtime setting thus avoiding those weird bugs that we might encounted if we did not do so.

# Requirement

## Linux Requirements

* At least C++11-standard-compliant version of gcc compiler
* [CMake](https://cmake.org/) v2.6.4 or newer

## Windows Requirements

* Microsoft Visual C++ 2015 or newer
* [CMake](https://cmake.org/) v2.6.4 or newer

## Mac OS X Requirements

* Mac OS X Lion or newer
* Xcode Developer Tools or gcc compiler supporting at least C++11 standard.
* [CMake](https://cmake.org/) v2.6.4 or newer

## Issues
Please feel free to [create an issue](https://github.com/TusharJadhav/algorithms/issues/new) in order to submit a bug or request any particular feature and/ or algorithm/ data structure that you to be implemented.

## Contributing Code
Patches are welcome. Please feel free to submit a pull request and I will review it as soon as I can. The only requirement is that all existing unit tests should be running successfully with your patch. So please run them before submitting the patch.

## Note for Windows build
Since most of the machine these days are 64 bit, pass -DCMAKE_GENERATOR_PLATFORM=x64 parameter to CMake in order to generate Visual Studio projects with 64 bit configuration pre-defined.
