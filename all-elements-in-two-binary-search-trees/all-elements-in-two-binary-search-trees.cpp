/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(vector<int> &temp,TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(temp,root->left);
        temp.push_back(root->val);
        inorder(temp,root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       vector<int> tree1;
        vector<int> tree2;
        inorder(tree1,root1);
        inorder(tree2,root2);
        int pt1=0,pt2=0;
        vector<int> ans;
        while(pt1<tree1.size() && pt2<tree2.size()){
            if(tree1[pt1]<=tree2[pt2]){
                ans.push_back(tree1[pt1]);
                pt1++;
            }
            else{
                ans.push_back(tree2[pt2]);
                pt2++;
            }
        }
        while(pt1<tree1.size()){
            ans.push_back(tree1[pt1]);
            pt1++;
        }
        while(pt2<tree2.size()){
            ans.push_back(tree2[pt2]);
            pt2++;
        }
        return ans;
    }
};