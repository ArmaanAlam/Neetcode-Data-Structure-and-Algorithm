/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    void traversal(TreeNode* node, vector<int> &postorder){
        if(node == NULL) return;
        postorder.push_back(node->val);
        traversal(node->left, postorder);
        traversal(node->right, postorder);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>postorder;
        if(root == NULL) return postorder;
        traversal(root, postorder);
        return postorder;
    }
};