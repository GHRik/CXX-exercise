# CXX-exercises

## Table of contents
1. [ Description ](#repo)
2. [ Technology ](#tech)
3. [ Sylabus ](#syl)
4. [ Results ](#res)


<a name="repo"></a>
## Description

This repo was created to improve my C++ experiance(and maybe a small part of cmake). If you want to get knownleadge from my task which will be done on this repo you should have small C++ programing knownledge. The task will be some more difficult than "start c++ programing course", but not rocket science.

<a name="tech"></a>
## Technology

[Modern C++(11/14/17)](https://en.cppreference.com/w/) - like smart pointers, STL, template, optional etc.<br />
[Google test](https://github.com/google/googletest) - to write unit test<br />
[CppCheck](https://cppcheck.sourceforge.io/) - to static code analysis<br />
[Doxygen](https://www.doxygen.nl/index.html) - to create documentation<br />
[CMake](https://cmake.org/) - to properly build sources and know how to write cmake files.<br />
[Twitter API](https://developer.twitter.com/en/docs/tools-and-libraries#cplusplus) - to write some bot or something like this.<br />

<a name="syl"></a>
## Sylabus
Get knownledge of:
1. Polymorphism and lifce cycle of object
2. Using [try-catch](https://en.cppreference.com/w/cpp/language/try_catch) blocks
3. Using [smart pointers](https://en.cppreference.com/book/intro/smart_pointers)
4. Using thing from C++17 like [optional](https://en.cppreference.com/w/cpp/utility/optional)
5. Using class and function [templates](https://en.cppreference.com/w/cpp/language/templates)
6. Using google test to write unit tests.
7. Using [TDD](https://en.wikipedia.org/wiki/Test-driven_development)
8. Using static code check
9. Using doxygen to genereta documentation 
10. Using external API to figure how to using authentication and using documentation.

<a name="res"></a>
## Result

All of the folders in this repo have his own README. In README you will see:

1. Description of the project
2. design assumptions

Projects:<br />
- Hello-world - First app with one method print hello-world and tested by gtest <br /> 
- Exercise-1 - App to present how a smart pointers work <br />
- Exercise-2 - Implementation one-way linked-list using smart pointers <br />

All test in projects is created before implements methods(TDD).<br />
All of project have own github workflows to properly deployed test(gtest) and app(cmake)<br />.

