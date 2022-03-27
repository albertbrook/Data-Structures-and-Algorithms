#include <iostream>
#include <map>

using namespace std;

string findLowestCostNode(map<string, int> &costs, map<string, bool> &checked) {
    int lowestCost = INT_MAX;
    string lowestCostNode;
    for (auto &item : costs)
        if (!checked[item.first] && item.second < lowestCost) {
            lowestCost = item.second;
            lowestCostNode = item.first;
        }
    return lowestCostNode;
}

int main() {
    map<string, map<string, int>> graph = {
            {"start", {{"a", 6}, {"b", 2}}},
            {"a", {{"finish", 1}}},
            {"b", {{"a", 3}, {"finish", 5}}}
    };
    map<string, int> costs = {
            {"a", INT_MAX},
            {"b", INT_MAX},
            {"finish", INT_MAX}
    };
    map<string, string> parents;
    map<string, bool> checked;
    string node;

    node = "start";
    while (!node.empty()) {
        for (auto &item : graph[node])
            if (costs[node] + item.second < costs[item.first]) {
                costs[item.first] = costs[node] + item.second;
                parents[item.first] = node;
            }
        checked[node] = true;
        node = findLowestCostNode(costs, checked);
    }

    node = "finish";
    while (node != "start") {
        cout << node << "(" << costs[node] << ") <- ";
        node = parents[node];
    }
    cout << node << "(0)" << endl;
    return 0;
}