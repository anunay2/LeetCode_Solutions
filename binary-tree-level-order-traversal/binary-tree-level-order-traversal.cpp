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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q1;
        q1.push(root);
        int num_nodes=1;
        while(!q1.empty()){
            vector<int> temp;
            int x=0;
            for(int i=0;i<num_nodes;i++){
                TreeNode* node=q1.front();
                temp.push_back(node->val);
                q1.pop();
                if(node->left){
                    x++;
                    q1.push(node->left);
                }
                if(node->right){
                    x++;
                    q1.push(node->right);
                }
            }
            num_nodes=x;
            ans.push_back(temp);
          
             
        }
        return ans;
    }
};