#include <iostream>

#include "graph.h"
using namespace std;

int main()
{
  Graph g;

  g.add_edge("0", "1");
  g.add_edge("1", "2");
  g.add_edge("2", "0");
  g.add_edge("2", "1");
  g.add_edge("3", "2");
  g.add_edge("4", "5");
  g.add_edge("5", "4");

  g.print_graph(cout); std::cout << '\n';

  g.delete_node("2");

  g.print_graph(cout);


  return 0;
}
