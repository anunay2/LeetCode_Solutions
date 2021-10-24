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
public:
    int count=0;
    void traverse(TreeNode *root){
        if(root==NULL){
            return;
        }
        traverse(root->left);
        count++;
        traverse(root->right);
    }
    int countNodes(TreeNode* root){
        count=0;
        traverse(root);
        return count;
    }
};