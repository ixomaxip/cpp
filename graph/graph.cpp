#include <bits/stdc++.h>
#include <string>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <functional>


using namespace std;

//tests
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

class Graph {
public:
    void add_node(const string& node_name);
    void add_edge(const string& from, const string& to);
    vector<string> get_path(const string& from, const string& to );
    vector<vector<string>> get_cycles() const;
    
    void print();
    void remove_node(const string& node);
    Graph subgraph(vector<string> nodes) const;

    vector<string> get_nodes() const;

protected:
    map<string, vector<string>> _adj;
};

Graph Graph::subgraph(vector<string> nodes) const {
    Graph sub_g = *this;
    for (const auto& u : sub_g.get_nodes()) {
        if (find(nodes.begin(), nodes.end(), u) == nodes.end()) {
            sub_g.remove_node(u);
        }
    }

    return sub_g;
}

vector<string> Graph::get_nodes() const {
    vector<string> nodes;
    for (const auto& [u, _] : this->_adj) {
        nodes.push_back(u);
    }
    return nodes;
}


void Graph::remove_node(const string& node) {
    this->_adj.erase(this->_adj.find(node));

    for (auto& [u, list] : this->_adj) {
        list.erase(remove(list.begin(), list.end(), node), list.end());
    }
}

void Graph::add_node(const string& node_name){
    this->_adj[node_name] = {};
}

void Graph::add_edge(const string& from, const string& to) {
    this->_adj[from].push_back(to);
    if (this->_adj.find(to) == this->_adj.end()) {
        this->add_node(to);
    }
}

vector<string> Graph::get_path(const string& from, const string& to ) {
    
    queue<string> Q;
    map<string, string> predecessor;
    map<string, int> distance;
    map<string, bool> visited;
    // initialize the values
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

    //construct path
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

    // cout << "path: " << distance[to] << endl;

    return path;
}

void Graph::print() {
    for (const auto& [u, list] : this->_adj) {
        if (list.empty())
            cout << u << endl;
        for (const auto& v : list) {
            cout << u << " -> " << v << endl;
        }
    }
};


TEST_CASE ("misc") {

    Graph g;
    g.add_edge("A", "D");
    g.add_edge("B", "A");
    g.add_edge("C", "A"); g.add_edge("C", "D");
    g.add_edge("D", "A"); g.add_edge("D", "B");
    g.print();
    cout << endl;

    SECTION ("subgraph"){
        cout << "Subgraph" << endl;
        Graph sg = g.subgraph({"B", "D", "A"});
        sg.print();
        cout << endl;
    }
    SECTION ("remove node"){
        cout << "Remove" << endl;
        g.remove_node("A");
        g.print();
        cout << endl;
    }

    // REQUIRE((g == g.get_transposed().get_transposed()) == true);
}
TEST_CASE ("Shortest path") {
    vector<string> req;
    SECTION ("empty path") {
        Graph g;
        g.add_node("A");
        g.add_node("B");
        req = {};
        REQUIRE(g.get_path("A", "B") == req);
        g.add_edge("A", "B");
        g.add_edge("A", "C");
        g.add_edge("D", "C");
        g.add_edge("D", "A");
        REQUIRE(g.get_path("A", "D") == req);
        
    };
    SECTION ("one node with the simplest cyrcle") {
        Graph g;
        g.add_node("A");
        g.add_edge("A", "A");
        req = {"A"};
        REQUIRE(g.get_path("A", "A") == req);
    };
    SECTION ("list") {
        Graph g;
        g.add_edge("A", "B");
        g.add_edge("B", "C");
        g.add_edge("C", "D");

        req = {"A", "B", "C"};
        REQUIRE(g.get_path("A", "C") == req);
    };
    SECTION ("first with last") {
        Graph g;        
        g.add_edge("A", "B");
        g.add_edge("A", "D");
        g.add_edge("B", "C");
        g.add_edge("C", "D");

        req = {"A", "D"};
        REQUIRE(g.get_path("A", "D") == req);
        req = {"A", "B", "C"};
        REQUIRE(g.get_path("A", "C") == req);
    };
    SECTION ("cyrcles") {
        Graph g;
        g.add_edge("A", "B");
        g.add_edge("B", "C");
        g.add_edge("C", "D");
        g.add_edge("D", "E");
        g.add_edge("E", "A");

        req = {"A", "B", "C", "D", "E"};
        REQUIRE(g.get_path("A", "E") == req);

        g.add_edge("D", "A");
        REQUIRE(g.get_path("A", "E") == req);

        g.add_edge("A", "D");
        req = {"A", "D", "E"};
        REQUIRE(g.get_path("A", "E") == req);
    };


};

// int main() {

//     Graph g;
//     g.add_edge("A", "B");
//     g.add_edge("A", "C");
//     g.add_edge("D", "A");
//     g.add_edge("E", "F");


//     g.print();

//     return 0;
// }


