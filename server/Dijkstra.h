#ifndef _H_DIJKSTRA_
#define _H_DIJKSTRA_

#include <limits>
#include "Graph.h"

class Dijkstra
{
public:
  Dijkstra(const std::shared_ptr<Graph> graph);
  int calculateShortestPath(const std::string startNodeId, const std::string endNodeId);

private:
  std::shared_ptr<Graph> graph;
  std::vector<std::string> shortestPaths;
};

#endif