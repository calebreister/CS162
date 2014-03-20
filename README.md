CS162
=====

This is all of my work in CS162. I have extended my capabilities greatly.

libjson (aka JSON++) can be found at https://bitbucket.org/tunnuz/json/src
I used a tool called git-hg to import it as a Git repo and set it as a submodule.

This game runs on SFML 2.1 (http://sfml-dev.org/).

Built under Ubuntu 13.10 64 bit.

**Build instructions**

My files are Eclipse projects, meaning that the Debug build is already preconfigured for Linux.
Both JSON++ (libjson) and SFML can be built using cmake.

On Linux, if you install the extra libraries necessary for SFML, make sure you run "sudo /sbin/ldconfig" to update the dynamic library cache.

To install the dependencies on a Debian-based system, see https://gist.github.com/calebreister/9531018. These names may be useful on other systems as well.

**NOTE: I may have used some C++11 features. If you want to build SFML with C++11, add 
set(CMAKE_CXX_FLAGS "-std=c++11")
to line 26 of the CMakeLists file.**
