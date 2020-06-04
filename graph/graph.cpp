#include <bits/stdc++.h>
#include <string>
#include <map>
#include <string>




using namespace std;


class Graph {
public:
    void add_node(const string& node_name){
        this->_adj[node_name] = {};
    }
    void add_edge(const string& from, const string& to) {
        this->_adj[from].push_back(to);
    }
    vector<string> get_path(const string& from, const string& to ) {
        vector<string> res;
        return res;
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


