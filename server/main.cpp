#include <iostream>
#include <memory>
#include <map>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
#include "Dijkstra.h"

std::string getEdgeId(const std::string &nodeId1, const std::string &nodeId2)
{
    return nodeId1 <= nodeId2 ? nodeId1 + nodeId2 : nodeId2 + nodeId1;
}

int main()
{
    // const std::map<std::string, std::map<std::string, int>> graph = {
    //     {"A", {{"B", 8}, {"C", 9}, {"D", 4}}},
    //     {"B", {{"A", 8}, {"C", 5}, {"E", 6}}},
    //     {"C", {{"A", 9}, {"B", 5}, {"D", 1}, {"E", 4}, {"F", 2}}},
    //     {"D", {{"A", 4}, {"C", 1}, {"F", 6}}},
    //     {"E", {{"B", 6}, {"C", 4}, {"G", 9}}},
    //     {"F", {{"C", 2}, {"D", 6}, {"G", 3}}},
    //     {"G", {{"E", 9}, {"F", 3}}}};

    const std::vector<std::string> nodeIds = {"A", "B", "C", "D", "E", "F", "G"};
    const std::map<std::pair<std::string, std::string>, int> connections = {
        {{"A", "B"}, 8}, {{"A", "C"}, 9}, {{"A", "D"}, 4}, {{"B", "C"}, 5}, {{"B", "E"}, 6}, {{"C", "D"}, 1}, {{"C", "E"}, 4}, {{"C", "F"}, 2}, {{"D", "F"}, 6}, {{"E", "G"}, 9}, {{"F", "G"}, 3}};

    const std::shared_ptr<Graph> graph = std::make_shared<Graph>();
    for (const std::string nodeId : nodeIds)
    {
        graph->nodes[nodeId] = std::make_shared<Node>(nodeId);
    }

    for (const std::pair<std::pair<std::string, std::string>, int> connection : connections)
    {
        const std::string nodeId1 = connection.first.first;
        const std::string nodeId2 = connection.first.second;
        const int distance = connection.second;

        const std::string edgeId = getEdgeId(nodeId1, nodeId2);
        graph->edges[edgeId] = std::make_shared<Edge>(edgeId, distance);
        graph->edges[edgeId]->nodes = std::make_pair(graph->nodes[nodeId1], graph->nodes[nodeId2]);

        graph->nodes[nodeId1]->edges.push_back(graph->edges[edgeId]);
        graph->nodes[nodeId2]->edges.push_back(graph->edges[edgeId]);
    }

    // Print the created nodes and edges
    std::cout << "Nodes" << std::endl;
    for (const std::pair<std::string, std::shared_ptr<Node>> pair : graph->nodes)
    {
        const std::shared_ptr<Node> node = pair.second;
        std::cout << node->id << ", ";
        for (const std::shared_ptr<Edge> edge : node->edges)
        {
            std::cout << edge->id << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << "Edges" << std::endl;
    for (const std::pair<std::string, std::shared_ptr<Edge>> pair : graph->edges)
    {
        const std::shared_ptr<Edge> edge = pair.second;
        std::cout << edge->id << ", " << edge->distance << ", " << edge->nodes.first->id << ", " << edge->nodes.second->id << std::endl;
    }

    const std::shared_ptr<Dijkstra> dijkstra = std::make_shared<Dijkstra>();
    dijkstra->calculateShortestPath(graph);
}
