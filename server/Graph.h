#ifndef _H_GRAPH_
#define _H_GRAPH_

#include <limits>
#include <map>
#include "Node.h"
#include "Edge.h"

struct Graph
{
  std::map<std::string, std::shared_ptr<Node>> nodes = {};
  std::map<std::string, std::shared_ptr<Edge>> edges = {};
};

#endif