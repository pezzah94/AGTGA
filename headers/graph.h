#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
//Implementation of directed unweighted graph


using Node = std::string;

class Graph
{
public:
  Graph();
  Graph(const std::vector<std::pair<Node, Node>> &edges);
  void add_edge(const Node &n1, const Node &n2);
  void print_graph(std::ostream & out);
  unsigned number_of_nodes();
  void delete_node(const Node & n);
  void delete_edge(const Node & n1,const Node & n2);
private:
  std::map <Node, std::vector<Node>> _nodes;
  unsigned N, V;
};

#endif // GRAPH_H
