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

    int height(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }

    int diameter(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        int leftDiameter = diameter(root->left);
        int rightDiameter = diameter(root->right);

        int tree = left + right;
        int subtree = max(leftDiameter, rightDiameter);

        return max(subtree, tree);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans = diameter(root);

        return ans;
    }
};
