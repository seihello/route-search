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
    std::vector<std::shared_ptr<Node>> nodes;
    std::vector<std::shared_ptr<Edge>> edges;

    std::shared_ptr<Node> startNode = makeNode("A");

    std::vector<std::shared_ptr<Edge>> startToFirstEdges;
    startToFirstEdges.push_back(makeEdge("a", 8));
    startToFirstEdges.push_back(makeEdge("b", 9));
    startToFirstEdges.push_back(makeEdge("c", 4));

    std::vector<std::shared_ptr<Node>> firstNodes;
    firstNodes.push_back(makeNode("B"));
    firstNodes.push_back(makeNode("C"));
    firstNodes.push_back(makeNode("D"));

    std::vector<std::shared_ptr<Edge>> firstEdges;
    firstEdges.push_back(makeEdge("d", 5));
    firstEdges.push_back(makeEdge("e", 1));

    std::vector<std::shared_ptr<Edge>> firstToSecondEdges;
    firstToSecondEdges.push_back(makeEdge("f", 6));
    firstToSecondEdges.push_back(makeEdge("g", 4));
    firstToSecondEdges.push_back(makeEdge("h", 2));
    firstToSecondEdges.push_back(makeEdge("i", 6));

    std::vector<std::shared_ptr<Node>> secondNodes;
    secondNodes.push_back(makeNode("E"));
    secondNodes.push_back(makeNode("F"));

    std::vector<std::shared_ptr<Edge>> secondToEndEdges;
    secondToEndEdges.push_back(makeEdge("j", 9));
    secondToEndEdges.push_back(makeEdge("k", 3));

    std::shared_ptr<Node> endNode = makeNode("G");

    for (std::shared_ptr<Node> node : nodes)
    {
        std::cout << node->id << std::endl;
    }

    for (std::shared_ptr<Edge> edge : edges)
    {
        std::cout << edge->id << " " << edge->distance << std::endl;
    }
}
