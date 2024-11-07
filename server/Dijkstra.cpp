// server/Dijkstra.cpp
#include "Dijkstra.h"

Dijkstra::Dijkstra(const std::shared_ptr<Graph> graph): graph(graph)
{
}

int Dijkstra::calculateShortestPath(const std::string startNodeId, const std::string endNodeId)
{
  // TODO: Clear dynamic values

  this->graph->nodes[startNodeId]->currentDistance = 0;
  return 100;
}