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
    int sumNumbers(TreeNode* root) {
        queue<pair<TreeNode*,int>> q1;
        q1.push({root,root->val});
        int sum = 0;
       // TreeNode *prev = q1.front().first;
       // int prevVal = q1.front().second;
        while(!q1.empty()){
            int prev = q1.front().second;
            TreeNode *prevNode = q1.front().first;
            q1.pop();
            //if the prevNode is leaf
            if(prevNode->left==NULL && prevNode->right==NULL){
                //cout<<prevNode->val<<"\t"<<prev<<"\n";
                sum = sum + prev;
            }
            else{
                if(prevNode->left!=NULL){
                    q1.push({prevNode->left,prev*10+prevNode->left->val});
                }
                if(prevNode->right!=NULL){
                    q1.push({prevNode->right,prev*10+prevNode->right->val});
                }
            }
          
        }
        return sum;
    }
};