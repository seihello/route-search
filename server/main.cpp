#include <iostream>
#include <memory>
#include <map>
#include "Node.h"
#include "Edge.h"

int main()
{
    const std::map<std::string, std::map<std::string, int>> graph = {
        {"A", {{"B", 8}, {"C", 9}, {"D", 4}}},
        {"B", {{"A", 8}, {"C", 5}, {"E", 6}}},
        {"C", {{"A", 9}, {"B", 5}, {"D", 1}, {"E", 4}, {"F", 2}}},
        {"D", {{"A", 4}, {"C", 1}, {"F", 6}}},
        {"E", {{"B", 6}, {"C", 4}, {"G", 9}}},
        {"F", {{"C", 2}, {"D", 6}, {"G", 3}}},
        {"G", {{"E", 9}, {"F", 3}}}};

    bool isValid = true;
    for (const std::pair<std::string, std::map<std::string, int>> &pair : graph)
    {
        const std::string &nodeId = pair.first;
        const std::map<std::string, int> &connections = pair.second;
        for (const std::pair<std::string, int> &connection : connections)
        {
            if (graph.count(connection.first) == 1)
            {
                if (graph.at(connection.first).count(nodeId) == 1)
                {
                    if (graph.at(connection.first).at(nodeId) != connection.second)
                    {
                        isValid = false;
                    }
                }
                else
                {
                    isValid = false;
                }
            }
            else
            {
                isValid = false;
            }
        }
    }

    std::cout << isValid << std::endl;

    std::map<std::string, std::shared_ptr<Node>> nodes = {};
    std::map<std::string, std::shared_ptr<Edge>> edges = {};
    for (const std::pair<std::string, std::map<std::string, int>> &pair : graph)
    {
        const std::string &nodeId = pair.first;
        const std::map<std::string, int> &connections = pair.second;

        std::shared_ptr<Node> node;
        if (nodes.count(nodeId) == 0)
        {
            node = std::make_shared<Node>(nodeId);
        }
        else
        {
            node = nodes.at(nodeId);
        }
        for (const std::pair<std::string, int> &connection : connections)
        {
            // Create a new edge for the connection
            if (nodes.count(connection.first) == 0)
            {
                const std::shared_ptr<Node> connectedNode = std::make_shared<Node>(connection.first);
                const std::shared_ptr<Edge> connectedEdge = std::make_shared<Edge>(std::to_string(edges.size() + 1), connection.second);

                // Set the connected edge to this node
                node->edges.push_back(connectedEdge);
                connectedNode->edges.push_back(connectedEdge);

                // Set this node to the connected edge
                connectedEdge->nodes.first = node;
                connectedEdge->nodes.second = connectedNode;

                // Register the edge
                edges[std::to_string(edges.size() + 1)] = connectedEdge;
            }
        }
        nodes[nodeId] = node;
    }

    // Print the created nodes and edges
    std::cout << "Nodes" << std::endl;
    for (const std::pair<std::string, std::shared_ptr<Node>> pair : nodes)
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
    for (const std::pair<std::string, std::shared_ptr<Edge>> pair : edges)
    {
        const std::shared_ptr<Edge> edge = pair.second;
        std::cout << edge->id << ", " << edge->distance << ", " << edge->nodes.first->id << ", " << edge->nodes.second->id << std::endl;
    }
}
