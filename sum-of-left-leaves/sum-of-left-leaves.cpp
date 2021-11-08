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
    int sum = 0;
    void sumOfLeftLeavesUtil(TreeNode *presNode, TreeNode *parentNode){
        if(presNode ==NULL){
            return;
        }
        sumOfLeftLeavesUtil(presNode->left,presNode);
        if(presNode->left==NULL && presNode->right==NULL && parentNode->left==presNode){
            sum+=presNode->val;
        }
        sumOfLeftLeavesUtil(presNode->right,presNode);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        //What is the identification of the left LEAVE.
        //It has a left child of it's parent
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        sumOfLeftLeavesUtil(root,NULL);
        return sum;
    }
};