#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    map<int, int> mp;
    
    int max_h = 0;
    
    void dfs(TreeNode* u, int h){
        max_h = max(max_h, h);
        auto it = mp.find(h);
        if(it == mp.end()){
            mp[h] = u->val;
        }
        if(u->right != nullptr)
            dfs(u->right, h + 1);
        if(u->left != nullptr)
            dfs(u->left, h + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root != nullptr){
            dfs(root, 0);
            for(int h = 0; h <= max_h; h++)
                ans.push_back(mp[h]);
        }
        return ans;
    }
};