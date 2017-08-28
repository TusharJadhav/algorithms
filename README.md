Welcome to the world of Algorithms and Data structures!

This repository contains implementation of various algorithms and data structures popularly known in the field of computer science. I have implemented these programs using my favourite programming language C++. Most of them are covered in the Princeton online open course and you can find more about them [here](https://online.princeton.edu/course/algorithms-part-i) and [here](https://online.princeton.edu/course/algorithms-part-ii). I would like to thank [Robert Sedgewick](https://www.cs.princeton.edu/people/profile/rs) and [Kevin Wayne](https://www.cs.princeton.edu/people/profile/wayne) for creating the contents of this beautiful course in an easy to understand language. I may also occasionally implement other interesting algorithms and data structures that I come across as I continue my journey in the field of algorithms and data structures.

# Features
* Implemented in C++ programming language as a shared library using modern C++ constructs
* Uses Standard Template Library (STL) wherever applicable
* Designed closely by following STL design
* Unit tests provided
* Cross Platform
* Highly performant

# Platforms
* Linux
* MacOS
* Windows

All the algorithms and data structures have been implemented as a shared library, popularly known as Shared Object (.so) files on linux/ MacOS platform and Dynamic Link Library (.DLL) on windows platform. Since all the programs have been written in C++ then should be usuable on Linux, MacOS and Windows platform. I have provided a CMakeLists receipe for generating the build files on your favourite operating system. Additionally there are unit tests written for all the programs using [Google C++ unit testing framework](https://github.com/google/googletest) which is cross platform as well. The CMakeLists receipe will automatically download and build the Google C++ testing framework. That way the test executable and the testing framework are built with the same compiler/ linker and use the same C++ runtime setting thus avoiding those weird bugs that we might encounted if we did not do so. So it is required for you to install [CMake](https://cmake.org/).

# Requirement

## Linux Requirements

* At least C++11-standard-compliant compiler
* GNU-compatible Make or gmake
* [CMake](https://cmake.org/) v2.6.4 or newer

## Windows Requirements

* Microsoft Visual C++ 2015 or newer
* [CMake](https://cmake.org/) v2.6.4 or newer

## Mac OS X Requirements

* Mac OS X Lion or newer
* Xcode Developer Tools
* [CMake](https://cmake.org/) v2.6.4 or newer

## Issues
Please feel free to [create an issue](https://github.com/TusharJadhav/algorithms/issues/new) in order to request any particular feature and/ or algorithm/ data structure that you wish was implemented.

## Contributing Code
Patches are welcome. Please feel free to submit a pull request and I will review it as soon as I can. The only requirement is that all existing unit tests should be running successfully with your patch. So please run them before submitting the patch.



