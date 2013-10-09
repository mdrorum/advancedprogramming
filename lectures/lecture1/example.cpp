/*
 * compile gcc & g++
 * talk about compilers
 * compile without stdc++
 * compile with it
 * compile without m
 * compile with it
 * library path
 * include path
 * write makefile: http://www.gnu.org/software/make/manual/make.html
 * write cmake: http://www.cmake.org/cmake/help/cmake_tutorial.html
 *
 * indent it (use several indentations!)
 * vim & emacs
 * ctags & etags
 * doxygen: http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
 * - doxygen -g
 * - edit doxygen file
 *
 * man
 * APIs
 * search internet
 *
 * build with optimizations
 * build with debugging symbols (check size)
 *
 * explain git: http://git-scm.com/docs/gittutorial
 * create a github account
 * upload code
 * create a branch
 * check it out
 * merge branches
 * go up and down in history
 * make them contribute
 *
 * make all projects be available on github
 *
 * practical: 
 * - upload a project to github
 * - must include a makefile
 * - must include a cmake file
 * - must be automatically indented
 * - must be well documented
 * - cmake + make must build everything including documentation
 * - they must find out how to tell cmake create doxygen documentation
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

/**
 * PI constant
 */
const double PI = 3.14159265;

/**
 * Main function
 */
int main() {

    cout << "hi, advanced programmers!" << endl;

    double degrees = 125;
    double radians = degrees * 180 / PI;

    cout << cos(radians) << endl;
    return 0;
}

