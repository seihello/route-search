#ifndef _H_EDGE_
#define _H_EDGE_

#include <limits>
#include <iostream>
#include <memory>
#include "Node.h"

struct Edge
{
  std::string id;
  int distance;
  std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>> nodes;

  Edge(std::string id, int distance)
      : id(id), distance(distance)
  {
  }
};

#endif