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
    TreeNode* form(vector<int> &inorder,int is,int ie,vector<int> &postorder,int ps,int pe,unordered_map<int,int> &um){
        if(is>ie || ps>pe){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pe]);
        int index=um[root->val];
        int ltsize=(index-is);
        int rtsize=(ie-index);
        root->left=form(inorder,is,index-1,postorder,ps,ps+ltsize-1,um);
        root->right=form(inorder,index+1,ie,postorder,pe-rtsize,pe-1,um);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0){
            return NULL;
        }
        unordered_map<int,int> inodr;
        for(int i=0;i<inorder.size();i++){
            inodr[inorder[i]]=i;
        }
        return form(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inodr);
    }
};