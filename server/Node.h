#include <climits>
#include <vector>
#include <Edge.h>

struct Node
{
  int id;
  int distance = INT_MAX;
  std::vector<Edge> edges;

  Node(int id) : id(id)
  {
  }
};