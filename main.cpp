#include "headers/graph.h"
#include "headers/aristotle.h"


#include <iostream>


int main(int argc, const char **argv) {

    
  //kreiramo klasu Aristotle za kreiranje grafa kontrole toka 
  Aristotle a(argc, argv);

  Graph g = a.get_graph();
  
  g.print_graph(std::cout);
  
  return 0;
}
