#include <iostream>
#include <memory>
#include "Node.h"
#include "Edge.h"

std::shared_ptr<Node> makeNode(std::string id)
{
    return std::make_shared<Node>(id);
}

std::shared_ptr<Edge> makeEdge(std::string id, int distance)
{
    return std::make_shared<Edge>(id, distance);
}

int main()
{
    std::vector<std::shared_ptr<Node>> nodes = {};
    nodes.push_back(makeNode("A"));
    nodes.push_back(makeNode("B"));
    nodes.push_back(makeNode("C"));
    nodes.push_back(makeNode("D"));
    nodes.push_back(makeNode("E"));

    std::vector<std::shared_ptr<Edge>> edges;
    edges.push_back(makeEdge("a", 8));
    edges.push_back(makeEdge("b", 9));
    edges.push_back(makeEdge("c", 4));
    edges.push_back(makeEdge("d", 5));
    edges.push_back(makeEdge("e", 1));
    edges.push_back(makeEdge("f", 6));
    edges.push_back(makeEdge("g", 4));
    edges.push_back(makeEdge("h", 2));
    edges.push_back(makeEdge("i", 6));
    edges.push_back(makeEdge("j", 9));
    edges.push_back(makeEdge("k", 3));

    for (std::shared_ptr<Node> node : nodes)
    {
        std::cout << node->id << std::endl;
    }

    for (std::shared_ptr<Edge> edge : edges)
    {
        std::cout << edge->id << " " << edge->distance << std::endl;
    }
}
