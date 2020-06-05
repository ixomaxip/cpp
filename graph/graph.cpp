#include <bits/stdc++.h>
#include <string>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;




class Graph {
public:
    void add_node(const string& node_name){
        this->_adj[node_name] = {};
    }

    void add_edge(const string& from, const string& to) {
        this->_adj[from].push_back(to);
        if (this->_adj.find(to) == this->_adj.end()) {
            this->add_node(to);
        }
    }
    
    vector<string> get_path(const string& from, const string& to ) {
        
        queue<string> Q;
        map<string, string> predecessor;
        map<string, int> distance;
        map<string, bool> visited;
        // fill initials
        for (const auto& [u, _] : this->_adj) {
            predecessor[u] = "";
            distance[u] = INT_MAX;
            visited[u] = false;
        }

        visited[from] = true;
        distance[from] = 0;
        Q.push(from);
        
        //breadth-first search
        bool found = false;
        while (!Q.empty()) {
            string u = Q.front();
            Q.pop();
            for (const auto& v : this->_adj[u]) {
                if (visited[v] == false) {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    predecessor[v] = u;
                    Q.push(v);
                }
                if (v == to) {
                    found = true;
                    break;
                }
            }
        }

        //constructing path
        vector<string> path;
        if (!found) {
            return path;
        }
        
        string curr_node = to;
        path.push_back(curr_node);
        while (predecessor[curr_node] != "") {
            path.push_back(predecessor[curr_node]);
            curr_node = predecessor[curr_node];
        }

        reverse(path.begin(), path.end());

        cout << "path: " << distance[to] << endl;

        return path;
    }
    vector<vector<string>> get_cycles() const {
        vector<vector<string>> res;
        return res;
    }

    void print() {
        for (const auto& [u, list] : this->_adj) {
            if (list.empty())
                cout << u << endl;
            for (const auto& v : list) {
                cout << u << " -> " << v << endl;
            }
        }
    };

private:
    map<string, vector<string>> _adj;
};


int main() {

    Graph g;
    g.add_node("A");
    g.add_node("B");
    g.add_node("C");
    g.add_node("D");

    g.add_edge("A", "B");
    g.add_edge("A", "C");
    g.add_edge("D", "A");
    g.add_edge("E", "C");


    g.print();

    return 0;
}


