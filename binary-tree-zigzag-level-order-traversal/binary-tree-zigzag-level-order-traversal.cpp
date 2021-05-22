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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q1;
        int num_nodes_prev_level=1;
        if(root==NULL)
            return ans;
        q1.push(root);
        int k=0;
        while(!q1.empty()){
            vector<int> temp;
            
            int num_nodes_next_level=0;
            for(int i=0;i<num_nodes_prev_level;i++){
                TreeNode *node=q1.front();
                temp.push_back(node->val);
                if(node->left!=NULL){
                    q1.push(node->left);
                    num_nodes_next_level++;
                }
                if(node->right!=NULL){
                    q1.push(node->right);
                    num_nodes_next_level++;
                }
                q1.pop();
            }
            num_nodes_prev_level=num_nodes_next_level;
            if(k%2==1){
                reverse(temp.begin(),temp.end());                
            }
            k++;
            ans.push_back(temp);
        }
        return ans;
    }
};