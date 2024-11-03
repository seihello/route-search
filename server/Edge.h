#include <limits>
#include <Node.h>

struct Edge
{
  int id;
  int distance;
  std::pair<Node, Node> nodes;

  Edge(int id, int distance, const Node &node1, const Node &node2)
      : id(id), distance(distance), nodes(node1, node2)
  {
  }
};