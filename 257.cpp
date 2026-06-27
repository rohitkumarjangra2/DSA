#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition of Tree Node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void solve(TreeNode* root, string path, vector<string>& ans) {

    if (root == NULL)
        return;

    if (path == "")
        path = to_string(root->val);
    else
        path += "->" + to_string(root->val);

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(path);
        return;
    }

    solve(root->left, path, ans);
    solve(root->right, path, ans);
}

vector<string> binaryTreePaths(TreeNode* root) {

    vector<string> ans;
    solve(root, "", ans);
    return ans;
}

int main() {

    // Creating the tree
    //
    //        1
    //       / \
    //      2   3
    //       \
    //        5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> ans = binaryTreePaths(root);

    cout << "Root to Leaf Paths:\n";

    for (string s : ans)
        cout << s << endl;

    return 0;
}