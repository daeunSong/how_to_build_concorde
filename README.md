# how_to_build_concorde

This repository presents a brief instruction on how to build [Concorde](http://www.math.uwaterloo.ca/tsp/concorde/) in Linux environment, also using the linear programming solver [QSopt](https://www.math.uwaterloo.ca/~bico/qsopt/) with a simple TSP example. 

### Build and Run

```sh
mkdir build && cd build
cmake ..
make -j4
./concordeTest
```

### References
- Concorde solver installation and use ([link](https://www.researchgate.net/publication/324485167_Concorde_solver_installation_and_use))
- concorde-easy-builde ([link](https://github.com/alberto-santini/concorde-easy-build))
