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
    int ans;
    set<TreeNode*> covered;
    int minCameraCover(TreeNode* root) {
        ans=0;
        covered.insert(NULL);
        DFS(root,NULL);
        return ans;
    }
    void DFS(TreeNode* node,TreeNode *parent){
        if(node==NULL){
            return;
        }
            DFS(node->left,node);
            DFS(node->right,node);
        
        
        if((parent==NULL && covered.find(node)==covered.end())||
           covered.find(node->left)==covered.end()
           ||covered.find(node->right)==covered.end()){
            ans++;
            covered.insert(parent);
            covered.insert(node);
            covered.insert(node->left);
            covered.insert(node->right);
        }
          
    }
};