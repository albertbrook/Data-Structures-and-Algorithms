#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main() {
    map<string, vector<string>> graph = {
            {"you", {"alice", "bob", "claire"}},
            {"alice", {"peggy"}},
            {"bob", {"anuj",  "peggy"}},
            {"claire", {"thom",  "jonny"}}
    };
    map<string, string> checked;
    queue<string> queues;

    queues.push("you");
    while (!queues.empty()) {
        for (string &neighbor : graph[queues.front()])
            if (checked[neighbor].empty()) {
                checked[neighbor] = queues.front();
                queues.push(neighbor);
                if (neighbor == "thom") {
                    string node = queues.back();
                    while (node != "you") {
                        cout << node << " <- ";
                        node = checked[node];
                    }
                    cout << node << endl;
                    return 0;
                }
            }
        queues.pop();
    }
    cout << "not found" << endl;
    return 0;
}