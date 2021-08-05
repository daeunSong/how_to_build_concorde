//This file solves a TSP using concorde given a symmetric 2D distance matrix

//Info about concorde functions: www.math.uwaterloo.ca/tsp/concorde/DOC/concorde_org.html
#include "tsp.h"
#include <iostream>
#include <vector>
extern "C" {
#include <concorde.h>
}

using namespace std;

//Receive a symmetric 2D distance matrix (dist) and create a TSP optimal tour (tour)
void solving_tsp_concorde(vector<int> * tour){

  TSP::TSPSolver m_TSPSolver;
  //Creating a sequential tour
  for(int i = 0; i < tour->size(); i++)
    tour->at(i) = i;
  int rval = 0; //Concorde functions return 1 if something fails
  double szeit; //Measure cpu time

  CCrandstate rstate;
  int seed = rand();
  CCutil_sprand(seed, &rstate); //Initialize the portable random number generator
  m_TSPSolver.ncount = tour->size(); //Number of nodes (cities)

  m_TSPSolver.out_tour = CC_SAFE_MALLOC (m_TSPSolver.ncount, int);
  m_TSPSolver.name = "/home/daeun/devel/how_to_build_concorde/src/berlin52.tsp";
  CCdatagroup dat;

  //Initialize a CCdatagroup
  CCutil_init_datagroup (&dat);
  CCutil_gettsplib (m_TSPSolver.name, &m_TSPSolver.ncount, &dat);

  //Solves the TSP over the graph specified in the datagroup
  rval = CCtsp_solve_dat (m_TSPSolver.ncount, &dat, m_TSPSolver.in_tour, m_TSPSolver.out_tour,
                              m_TSPSolver.in_val, &m_TSPSolver.optval, &m_TSPSolver.success,
                              &m_TSPSolver.foundtour, m_TSPSolver.name, m_TSPSolver.timebound,
                              &m_TSPSolver.hit_timebound, m_TSPSolver.silent, &rstate);
  for (int i = 0; i < m_TSPSolver.ncount; i++) {
    tour->at(i) = m_TSPSolver.out_tour[i];
  }

  szeit = CCutil_zeit();
  CC_IFFREE (m_TSPSolver.out_tour, int);
//  CC_IFFREE (m_TSPSolver.name, char);
}

int main(){

  //Tour stores the optimal tour
  vector<int> * tour = new vector<int>(52, 0);

  //Solve TSP
  solving_tsp_concorde(tour);

  //Print solution
  for(int i = 0; i < tour->size(); i++)
    cout<<tour->at(i)+1<<"_";
  cout << endl;
  return 0;
}

