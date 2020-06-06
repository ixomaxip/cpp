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
    
    vector<vector<string>> get_sccs();

    void remove_node(const string& node);
    Graph subgraph(vector<string> nodes) const;

    vector<string> get_nodes();
    vector<string> get_neighbours(const string& u);

    void print();
protected:
    map<string, vector<string>> _adj;
};



vector<vector<string>> Graph::get_cycles() const {
    vector<vector<string>> cycles;

    auto _unblock = []
    (const string curr_node, map<string, bool>& blocked, map<string, set<string>>& B) -> void {
        vector<string> stack;
        stack.push_back(curr_node);
        while (!stack.empty()) {
            string node = stack.back();
            stack.pop_back();
            if (blocked[node]) {
                blocked[node] = false;
                for (auto& u : B[node]) {
                    stack.push_back(u);
                }
                B[node] = {};
            }
        }
    };
    
    Graph g = *this;
    auto sccs = g.get_sccs();
    // main loop by strongly connected components
    while (!sccs.empty()) {
        auto scc = sccs.back();
        sccs.pop_back();

        map<string, bool> blocked; // blocked from search
        map<string, bool> closed; // already in a cycle
        map<string, set<string>> B;  // graph without elementary cycles
        // defaults
        for (const auto& u : scc) {
            blocked[u] = false;
            closed[u] = false;
            B[u] = {};
        }
        // getting start vertex
        string start = scc.back();
        scc.pop_back();
        blocked[start] = true;
        vector<string> stack;
        stack.push_back(start);
        vector<string> path;
        path.push_back(start);

        while (!stack.empty()) {            
            string curr_node = stack.back();
            stack.pop_back();
            vector<string> list = g.get_neighbours(curr_node);
            if (!list.empty()) {
                string next = list.back();
                list.pop_back();
                if (next == start) {
                    cycles.push_back(path);
                    for (const auto& p : path) {
                        closed[p] = true;
                    }
                } else if (!blocked[next]) {
                    path.push_back(next);
                    stack.push_back(next);
                    closed[next] = false;
                    blocked[next] = true;
                    continue;
                }
            }
            if (list.empty()) {
                if (closed[curr_node]) {
                    _unblock(curr_node, blocked, B);
                } else {
                    auto curr_neibs = g.get_neighbours(curr_node);
                    for (const auto& n : curr_neibs) {
                        if (B[n].find(curr_node) == B[n].end()) {
                            B[n].insert(curr_node);
                        }
                    }
                }
            }
        }
        g.remove_node(start);
        auto sub_g = g.subgraph(scc);
        auto sub_sccs = sub_g.get_sccs();
        for (auto& c : sub_sccs) {
            sccs.push_back(c);
        }
    }
    return cycles;
}

vector<vector<string>> Graph::get_sccs() {
    // find strongly connected components
    // Tarjan's algorithm O(V + E)

    vector<vector<string>> components;
    map<string, int> idx;
    map<string, int> low;
    int counter = 0;
    stack<string> st;
    map<string, bool> in_stack;

    for (const auto& u : this->get_nodes()) {
        in_stack[u] = false;
        idx[u] = -1;
        low[u] = -1;
    }


    function<void(const string& node)> _sccs;
    _sccs = [&] (const string& node) -> void {
        idx[node] = low[node] = counter;
        counter++;
        st.push(node);
        in_stack[node] = true;

        for (const auto& v : this->_adj[node]) {
            if (idx[v] == -1) {
               _sccs(v);
               low[node] = min(low[node], low[v]);
            }
            else if (in_stack[v]) {
                low[node] = min(low[node], idx[v]);
            }
        }

        if (low[node] == idx[node]) {
            vector<string> component;
            while (true) {
                auto w = st.top();
                st.pop();
                component.push_back(w);
                in_stack[w] = false;
                if (w == node)
                    break;
            }
            components.push_back(component);
        }
    };

    for (const auto node : this->get_nodes()) {
        if (idx[node] == -1) {
            _sccs(node);
        }
    }

    return components;
}

Graph Graph::subgraph(vector<string> nodes) const {
    Graph sub_g = *this;
    for (const auto& u : sub_g.get_nodes()) {
        if (find(nodes.begin(), nodes.end(), u) == nodes.end()) {
            sub_g.remove_node(u);
        }
    }

    return sub_g;
}

vector<string> Graph::get_nodes() {
    vector<string> nodes;
    for (const auto& [u, _] : this->_adj) {
        nodes.push_back(u);
    }
    return nodes;
}

vector<string> Graph::get_neighbours(const string& u) {
    if (this->_adj.find(u) == this->_adj.end()) {
        return vector<string>();
    } else {
        return this->_adj[u];
    }
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
    g.add_edge("B", "A"); g.add_edge("B", "C");
    g.add_edge("C", "A"); g.add_edge("C", "D");
    g.add_edge("D", "A"); g.add_edge("D", "B");
    g.add_edge("E", "E");

    // g.print();
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
    SECTION ("strongly connected components"){
        vector<vector<string>> cs = g.get_sccs();
        int cnt = 0;
        for (auto& c : cs) {
            cout << cnt++ << ":";
            for (auto& v : c) {
                cout << " " << v;
            }
            cout << endl;
        }
    }
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


