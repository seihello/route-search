// server/Dijkstra.cpp
#include "Dijkstra.h"
#include <climits>

Dijkstra::Dijkstra(const std::shared_ptr<Graph> graph) : graph(graph)
{
}

int Dijkstra::calculateShortestPath(const std::string startNodeId, const std::string endNodeId)
{
  // TODO: Clear dynamic values

  this->graph->nodes[startNodeId]->currentDistance = 0;

  while (true)
  {
    int minDistance = INT_MAX;
    std::shared_ptr<Node> minNode;
    for (const std::pair<std::string, std::shared_ptr<Node>> pair : this->graph->nodes)
    {
      std::shared_ptr<Node> node = pair.second;
      if (node->isConfirmed)
        continue;
      if (node->currentDistance < minDistance)
      {
        minDistance = node->currentDistance;
        minNode = node;
      }
    }

    // End if all the nodes are confirmed
    if(minNode == nullptr) {
      break;
    }

    minNode->isConfirmed = true;

    for (const std::shared_ptr<Edge> connectedEdge : minNode->edges)
    {
      const std::shared_ptr<Node> connectedNode = connectedEdge->nodes.first->id == minNode->id ? connectedEdge->nodes.second : connectedEdge->nodes.first;

      if (connectedNode->isConfirmed)
        continue;
      const int distanceViaMinNode = minNode->currentDistance + connectedEdge->distance;
      if (distanceViaMinNode < connectedNode->currentDistance) {
        connectedNode->currentDistance = distanceViaMinNode;
      }
    }
  }

  return this->graph->nodes.at(endNodeId)->currentDistance;
}