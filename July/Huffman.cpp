#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

class Node {
public:
	int a;
	char c;
	Node* left, * right;
	Node() {}

	Node(Node* L, Node* R)
	{
		left = L;
		right = R;
		a = L->a + R->a;
	}
};

struct NodeCompare {
	bool operator() (Node* l, Node* r) const {
		return l->a < r->a;
	}
};

vector<bool>code;
map<char, vector<bool> > table;

void BuildTable(Node* root) {
	if (root->left != NULL) {
		code.push_back(0);
		BuildTable(root->left);
	}
	if (root->right != NULL) {
		code.push_back(1);
		BuildTable(root->right);
	}
	if (root->left == NULL && root->right == NULL) table[root->c] = code;
	if (!code.empty())
		code.pop_back();
}

string make_code(vector<bool> code) {
	string result;
	for (const auto& i : code) {
		if (i)
			result += "1";
		else
			result += "0";
	}
	return result;
}

int main() {

	cout << "Enter a string: " << endl;
	string s;
	getline(cin, s);
	// string s = "qwee";

	map<char, int>m;
	for (const auto & c : s)
		m[c]++;

	list<Node*> t;
	for (auto it = m.begin(); it != m.end(); ++it) {
		Node* p = new Node;
		p->c = it->first;
		p->a = it->second;
		t.push_back(p);
	}

	t.sort(NodeCompare());
	cout << "Freqs:" << endl;
	for (const auto & i: t)
		cout << i->c << " " << i->a << endl;

	while (t.size() != 1) {
		Node* SonL = t.front();
		t.pop_front();
		Node* SonR = t.front();
		t.pop_front();

		Node* parent = new Node(SonL, SonR);
		t.push_back(parent);
	}
	Node* root = t.front();

	BuildTable(root);

	cout << "Decoded line: " << s << endl;
	cout << "Encoded line: ";
	for (const auto & c : s)
		cout << make_code(table[c]);
	cout << endl;

	for (const auto & [key, val] : table)
		cout << key << " " << make_code(val) << endl;

	return 0;
}
