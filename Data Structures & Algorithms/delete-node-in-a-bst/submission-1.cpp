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

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;

        TreeNode* leftchild = root->left;
        TreeNode* rightchild = root->right;
        TreeNode* right_left = find(rightchild);
        right_left->left = leftchild;
        return rightchild;
    }

    TreeNode* find(TreeNode* root){
        if(root->left == NULL) return root;
        return find(root->left);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key) return helper(root);


        TreeNode* node = root;
        while(node){
            if(node->val > key){
                if(node->left && node->left->val == key){
                    node->left = helper(node->left);
                    break;
                }
                else{
                    node = node->left;
                }
            }
            else{
                if(node->right && node->right->val == key){
                    node->right = helper(node->right);
                    break;
                }
                else{
                    node = node->right;
                }
            }
        }

        return root;
    }
};