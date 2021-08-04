# how_to_build_concorde

This repository presents a brief instruction on how to build [Concorde](http://www.math.uwaterloo.ca/tsp/concorde/) in Linux environment, also using the linear programming solver [QSopt](https://www.math.uwaterloo.ca/~bico/qsopt/) with a simple TSP example. 

## Build and Run

1. Build Concorde
    ```sh
    cd lib/concorde
    ./configure --with-qsopt=DIR
    make -j4
    ```
    `DIR` is a full path to the `/lib/qsopt` directory of the current repository. This will create `concorde.h` and `concorde.a` file.


2. Build and run the project 

   ```sh
   cd ../..
   mkdir build && cd build
   cmake ..
   make -j4
   ./concordeTest
   ```

## Technical Notes

The source of Concorde contained in `/lib/concorde` directory differs from the original source. The original source code contains some identifiers named `new` and `class`, which are the reserved names in C++. Please keep in mind that you need to fix them if you wish to build from the original source by yourself. 

### References
- Concorde solver installation and use ([link](https://www.researchgate.net/publication/324485167_Concorde_solver_installation_and_use))
- concorde-easy-builde ([link](https://github.com/alberto-santini/concorde-easy-build))
