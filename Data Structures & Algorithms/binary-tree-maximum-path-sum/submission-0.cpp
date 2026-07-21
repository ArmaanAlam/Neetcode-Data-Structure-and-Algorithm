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

    int path(TreeNode* root, int &maxSum){
        if(root == NULL) return 0;

        int left = path(root->left, maxSum);
        left = max(0, left);
        int right = path(root->right, maxSum);
        right = max(0, right);

        maxSum = max(maxSum, left + right + root->val);

        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        path(root, maxSum);
        return maxSum;
    }
};
