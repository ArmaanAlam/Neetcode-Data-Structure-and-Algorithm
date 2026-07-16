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

    int diameter(TreeNode* root, int &max_diameter){
        if(root == NULL){
            return 0;
        }

        int left = diameter(root->left, max_diameter);
        int right = diameter(root->right, max_diameter);

        max_diameter = max(max_diameter, left + right);

        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        diameter(root, max_diameter);
        return max_diameter;
    }
};
