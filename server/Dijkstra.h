#ifndef _H_DIJKSTRA_
#define _H_DIJKSTRA_

#include <limits>
#include "Graph.h"

class Dijkstra
{
public:
  void calculateShortestPath(const std::shared_ptr<Graph> graph);

private:
  std::vector<std::string> shortestPaths;
};

#endif