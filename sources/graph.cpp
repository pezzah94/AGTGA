#include "../headers/graph.h"

Graph::Graph()
{

}

Graph::Graph(const std::vector<std::pair<Node, Node> > &edges)
{
  for(const std::pair<Node,Node> & edge : edges){
      this->add_edge(edge.first, edge.second);
    }
}



void Graph::add_edge(const Node &n1, const Node &n2)
{

  _nodes[n1].emplace_back(n2);
  _nodes[n2];
  V++;

}

void Graph::print_graph(std::ostream &out)
{
  for (const auto &entry : _nodes){

      out << entry.first;
      out << "-->";

      for(unsigned i=0;i<entry.second.size();i++){
          out << entry.second[i] << ' ';
        }
      out << '\n';
    }
}

unsigned Graph::number_of_nodes()
{
  return std::distance(_nodes.begin(), _nodes.end());
}

void Graph::delete_node(const Node &n)
{
  auto nodeit = _nodes.find(n);
  if(nodeit!=_nodes.end())
    _nodes.erase(nodeit);

  //brisemo svako pojavljivanje n u grafu

  for(auto &pn: _nodes){
      pn.second.erase(std::remove(pn.second.begin(),
                                  pn.second.end(), n),
                                  pn.second.end());
    }
}

void Graph::delete_edge(const Node &n1, const Node &n2)
{
  auto nodeit = _nodes.find(n1);
  if(nodeit!=_nodes.end()){
     nodeit->second.erase(std::remove(nodeit->second.begin(), nodeit->second.end(), n2), nodeit->second.end());
    }
}




