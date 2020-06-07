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
            auto list = g.get_neighbours(curr_node);
            if (!list.empty()) {
                string next = list.back();
                list.pop_back();
                if (next == start) {
                    // yeah! i've got a cycle
                    cycles.push_back(path);
                    for (const auto& p : path) {
                        closed[p] = true;
                    }
                } else if (!blocked[next]) {
                    // first visit
                    path.push_back(next);
                    stack.push_back(next);
                    closed[next] = false;
                    blocked[next] = true;
                    continue;
                }
            }
            if (list.empty()) {
                // backtrack
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
    vector<string> stack;
    map<string, bool> in_stack;

    for (const auto& u : this->get_nodes()) {
        in_stack[u] = false;
        idx[u] = -1;
        low[u] = -1;
    }


    function<void(const string& node)> _sccs;
    _sccs = [&] (const string& node) -> void {
        // cout << node << endl;
        idx[node] = low[node] = counter;
        counter++;
        stack.push_back(node);
        in_stack[node] = true;

        auto nbs = this->get_neighbours(node);
        // for (auto& n : nbs) {
        //     cout << " " << n;
        // }
        // cout <<endl;
        for (const auto& v : nbs) {
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
                auto w = stack.back();
                stack.pop_back();
                in_stack[w] = false;
                component.push_back(w);
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
    vector<string> nbs = {};
    if (this->_adj.find(u) != this->_adj.end()) {
        for (auto& v : this->_adj[u])
        nbs.push_back(v);
        // sort(nbs.begin(), nbs.end());
        // reverse(nbs.begin(), nbs.end());
    }
    return nbs;
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
    cout << "[";
    bool first = true;
    for (const auto& [u, list] : this->_adj) {
        if (!first) {
            cout << ", ";
        }
        cout << u << ": [";
        first = true;
        // if (list.empty())
            // cout << u << ": [";
        for (const auto& v : list) {
            if (!first)
                cout << ", ";
            cout << v;
            first = false;
        }
        cout << "]";
        first = false;
    }
    cout << "]" << endl;
};

void print(const vector<vector<string>>& cs) {
    cout << "[";
    bool first = true;
    for (const auto& c : cs) {
        if (!first) {
            cout << ", ";
        }
        cout << "[";
        first = true;
        for (const auto& v : c) {
            if (!first)
                cout << ", ";
            cout << v;
            first = false;
        }
        cout << "]";
        first = false;

    }
    cout << "]" << endl;
}

bool compare(vector<vector<string>> v1, vector<vector<string>> v2, bool do_sort = false) {
    if (v1.size() != v2.size()) {
        return false;
    }
    if (do_sort) {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (auto& v : v1) {
            sort(v.begin(), v.end());
        }
        for (auto& v : v2) {
            sort(v.begin(), v.end());
        }
    }
    for (size_t i = 0; i < v1.size(); i++) {
        if (v1[i].size() != v2[i].size()) {
            return false;
        }
        for (size_t j = 0; i < v1.size(); i++) {
            if (v1[i][j] != v2[i][j]) {
                return false;
            }
        }
    }

    return true;
}

TEST_CASE ("cycles") {
    // SECTION ("one vertex (& self loop vertices)") {
    //     Graph g;
    //     g.add_node("A");
    //     REQUIRE(compare(g.get_cycles(), {}));
    //     g.add_edge("A", "A");
    //     REQUIRE(compare(g.get_cycles(), {{"A"}}));
    //     g.add_edge("B", "B");
    //     REQUIRE(compare(g.get_cycles(), {{"B"}, {"A"}}));
    // }
    // SECTION ("linked list (&with a loop at the end)") {
    //     Graph g;
    //     g.add_edge("A", "B");
    //     g.add_edge("B", "C");
    //     g.add_edge("C", "D");
    //     g.add_edge("D", "E");
    //     REQUIRE(compare(g.get_cycles(), {}));
    //     g.add_edge("E", "C");
    //     REQUIRE(compare(g.get_cycles(), {{"C", "D", "E"}}));
    // }
    // SECTION ("circle") {
    //     Graph g;
    //     g.add_edge("A", "B");
    //     g.add_edge("B", "C");
    //     g.add_edge("C", "D");
    //     g.add_edge("D", "A");
    //     REQUIRE(compare(g.get_cycles(), {{"A", "B", "C", "D"}}));
    // }
    SECTION ("fully connected square") {
        Graph g;
        g.add_edge("0", "1"); g.add_edge("0", "2"); g.add_edge("0", "3");
        g.add_edge("1", "0"); g.add_edge("1", "2"); g.add_edge("1", "3");
        g.add_edge("2", "0"); g.add_edge("2", "1"); g.add_edge("2", "3");
        g.add_edge("3", "0"); g.add_edge("3", "1"); g.add_edge("3", "2");
        auto result = g.get_cycles();
        cout << "Result:" << endl;
        print(result);
    }
    // SECTION ("A worst example for Tarjan's algorithm (from article)") {
    //     cout << "A worst example for Tarjan's algorithm" << endl;
    //     Graph g;
    //     g.add_edge("1", "2"); g.add_edge("1", "3"); g.add_edge("1", "4");
    //     g.add_edge("2", "5");
    //     g.add_edge("3", "5");
    //     g.add_edge("4", "5");
    //     g.add_edge("5", "6"); g.add_edge("5", "8");
    //     g.add_edge("6", "7"); g.add_edge("6", "8");
    //     g.add_edge("7", "1"); g.add_edge("7", "8");
    //     g.add_edge("8", "9"); g.add_edge("8", "10"); g.add_edge("8", "11");
    //     g.add_edge("9", "5"); g.add_edge("9", "12");
    //     g.add_edge("10", "12");
    //     g.add_edge("11", "12");
    //     g.add_edge("12", "8");

    //     Graph g4;
    //     g4.add_edge("0","1");g4.add_edge("0","3");
    //     g4.add_edge("1","2");g4.add_edge("1","4"); 
    //     g4.add_edge("2","0");g4.add_edge("2","6"); 
    //     g4.add_edge("3","2"); 
    //     g4.add_edge("4","5");g4.add_edge("4","6"); 
    //     g4.add_edge("5","6");g4.add_edge("5","7");g4.add_edge("5","8");g4.add_edge("5","9"); 
    //     g4.add_edge("6","4"); 
    //     g4.add_edge("7","9"); 
    //     g4.add_edge("8","9"); 
    //     g4.add_edge("9","8");
    //     g4.add_node("10");
    //     auto result = g4.get_sccs();
    //     print(result);
    //     REQUIRE(compare(result, {{"8", "9"}, {"7"}, {"5", "4", "6"}, {"3", "2", "1"}, {"10"}}));
    //     // [[1, 4, 5, 6, 7], [1, 3, 5, 6, 7], [1, 2, 5, 6, 7], [5, 6, 7, 8, 9], [5, 6, 8, 9], [8, 11, 12], [8, 10, 12], [8, 9, 12]]
    // }
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
TEST_CASE ("misc") {

    Graph g;
    g.add_edge("A", "D");
    g.add_edge("B", "A"); g.add_edge("B", "C");
    g.add_edge("C", "A"); g.add_edge("C", "D");
    g.add_edge("D", "A"); g.add_edge("D", "B");
    g.add_edge("E", "E");

    // g.print();
    // cout << endl;

    SECTION ("subgraph"){
        // cout << "Subgraph" << endl;
        // Graph sg = g.subgraph({"B", "D", "A"});
        // sg.print();
        // cout << endl;
    }
    SECTION ("remove node"){
        // cout << "Remove" << endl;
        // g.remove_node("A");
        // g.print();
        // cout << endl;
    }
    SECTION ("strongly connected components"){
        vector<vector<string>> cs = g.get_sccs();
        vector<vector<string>> req = {{"C", "B", "D", "A"}, {"E"}};
        REQUIRE (g.get_sccs() == req);

        Graph g4;
        g4.add_edge("0","1");g4.add_edge("0","3");
        g4.add_edge("1","2");g4.add_edge("1","4"); 
        g4.add_edge("2","0");g4.add_edge("2","6"); 
        g4.add_edge("3","2"); 
        g4.add_edge("4","5");g4.add_edge("4","6"); 
        g4.add_edge("5","6");g4.add_edge("5","7");g4.add_edge("5","8");g4.add_edge("5","9"); 
        g4.add_edge("6","4"); 
        g4.add_edge("7","9"); 
        g4.add_edge("8","9"); 
        g4.add_edge("9","8");
        g4.add_node("10");
        auto result = g4.get_sccs();
        // print(result);
        REQUIRE(compare(result, {{"8", "9"}, {"7"}, {"5", "4", "6"}, {"3", "2", "1"}, {"10"}}));
    }
}
// int main() {

//     Graph g;
//     g.add_edge("A", "B");
//     g.add_edge("A", "C");
//     g.add_edge("D", "A");
//     g.add_edge("E", "F");


//     g.print();

//     return 0;
// }


