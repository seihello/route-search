#ifndef _H_NODE_
#define _H_NODE_

#include <climits>
#include <vector>
// #include "Edge.h"
struct Edge;

struct Node
{
  std::string id;
  int currentDistance = INT_MAX;
  bool isConfirmed = false;
  std::vector<std::shared_ptr<Edge>> edges;

  Node(std::string id) : id(id)
  {
  }
};

#endif