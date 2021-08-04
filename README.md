# how_to_build_concorde

This repository presents a brief instruction on how to build [Concorde](http://www.math.uwaterloo.ca/tsp/concorde/) in Linux environment, also using the linear programming solver [QSopt](https://www.math.uwaterloo.ca/~bico/qsopt/) with a simple TSP example. 

### Build and Run

```sh
mkdir build && cd build
cmake ..
make -j4
./concordeTest
```

### Technical Notes
You can build the Concorde library yourself by following bellow:
1. Build Concorde
    ```sh
    cd lib/concorde
    ./configure --with-qsopt=DIR
    make
    ```
    `DIR` is a full path to the `/lib/qsopt` directory of the current repository. This will create `concorde.h` and `concorde.a` file.


2. Fix `concorde.h` file
   
    The file contains some identifiers named *new* and *class*, which are reserved names in C++. Fix the names to different ones, such as *new_* and *class_*. Be careful not to *find & replace* all occurrences, as it might get you in trouble.  


### References
- Concorde solver installation and use ([link](https://www.researchgate.net/publication/324485167_Concorde_solver_installation_and_use))
- concorde-easy-builde ([link](https://github.com/alberto-santini/concorde-easy-build))
