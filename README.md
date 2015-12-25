# ProjectEuler
My [Project Euler](https://projecteuler.net/) struggles in C/C++.

All problems are contained within their own main.cpp files and are usually a nice mashup of C and C++ (I'm in the process of learning C++). It seems some functionallity (e.g. primality tests, factorization tests, etc...) could be happily split out into common files or a library at some point...

Build Instructions
-------------------

To build, just go into any problem's directory, e.g.

``cd p1``

and compile with

``g++ -o out main.cpp``

then run with

``./out``

*Note some problems require an argument, specific usage will be printed when incorrect args are suppled.*

This should be much the same on all operating systems. For Windows, install mingw!
