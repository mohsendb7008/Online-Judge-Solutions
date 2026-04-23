#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Node {
public:
    long value1 = 0;
    long value2 = 0;
    bool terminal = false;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};

class Tree {
public:
    long mod1 = 1000000007;
    long mod2 = 1000000009;
    vector<long> p1 {1};
    vector<long> p2 {1};
    Node* iterator = new Node();

    explicit Tree(const int n) {
        for (int i = 1; i < n; i++) {
            p1.push_back(p1.back() * 100003 % mod1);
            p2.push_back(p2.back() * 100153 % mod2);
        }
    }

    void moveLeft() {
        if (iterator->left == nullptr) {
            iterator->left = new Node();
            iterator->left->parent = iterator;
        }
        iterator = iterator->left;
    }

    void moveRight() {
        if (iterator->right == nullptr) {
            iterator->right = new Node();
            iterator->right->parent = iterator;
        }
        iterator = iterator->right;
    }

    void moveUp() {
        iterator = iterator->parent;
    }

    void setValue(const long value) const {
        iterator->value1 = p1[value - 1];
        iterator->value2 = p2[value - 1];
        iterator->terminal = true;
    }

    pair<long, long> getValue(Node* u, set<long>& all) {
        if (!u->terminal) {
            const auto left = getValue(u->left, all);
            const auto right = getValue(u->right, all);
            u->value1 = (left.first + right.first) % mod1;
            u->value2 = (left.second + right.second) % mod2;
        }
        all.insert(u->value1 * mod1 + u->value2);
        return make_pair(u->value1, u->value2);
    }

    void propagateValues(set<long> &all) {
        getValue(iterator, all);
    }
};

void buildTree(const string &str, Tree* tree) {
    long value = 0;
    for (const char c : str) {
        if (value && (c == '(' || c == ')' || c == ',')) {
            tree->setValue(value);
            value = 0;
        }
        if (c == '(') {
            tree->moveLeft();
        }
        else if (c == ')') {
            tree->moveUp();
        }
        else if (c == ',') {
            tree->moveUp();
            tree->moveRight();
        } else {
            value = 10 * value + c - '0';
        }
    }
}

int main() {
    int n ;
    string a, b;
    set<long> av, bv, cv;
    cin >> n >> a >> b;
    const auto alice = new Tree(n);
    const auto bob = new Tree(n);
    buildTree(a, alice);
    buildTree(b, bob);
    alice->propagateValues(av);
    bob->propagateValues(bv);
    set_intersection(av.begin(), av.end(), bv.begin(), bv.end(), inserter(cv, cv.begin()));
    cout << cv.size() << endl;
    delete alice;
    delete bob;
}