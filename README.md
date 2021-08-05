# how_to_build_concorde

This repository presents a brief instruction on how to build [Concorde](http://www.math.uwaterloo.ca/tsp/concorde/) in Linux environment, also using the linear programming solver [QSopt](https://www.math.uwaterloo.ca/~bico/qsopt/) with a simple TSP example. 

## Build and Run
1. Clone the repository in your workspace
   ```sh
   git clone https://github.com/daeunSong/how_to_build_concorde.git
   cd how_to_build_concorde 
   export DIR=$(pwd)
   ```
   Save your repository path in `DIR`, which will be used for the next steps.


2. Build Concorde
    ```sh
    cd lib/concorde
    ./configure --with-qsopt=$DIR/lib/qsopt
    make -j4
    ```
    This will create the files `concorde.h` and `concorde.a`.


3. Build and run the project 

   ```sh
   cd $DIR
   mkdir build && cd build
   cmake ..
   make -j4
   ./concordeTest
   ```

## Technical Notes

The source of Concorde contained in `/lib/concorde` directory differs from the original source. The original source code contains some identifiers named `new` and `class`, which are the reserved names in C++. Please keep in mind that you need to fix them if you wish to build from the original source by yourself. 

### References
- Concorde solver installation and use ([link](https://www.researchgate.net/publication/324485167_Concorde_solver_installation_and_use))
- concorde-easy-build ([link](https://github.com/alberto-santini/concorde-easy-build))
