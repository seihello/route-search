#include <iostream>
#include <memory>
#include <map>

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
}
