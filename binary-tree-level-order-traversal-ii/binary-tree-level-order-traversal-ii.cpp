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
    int find_depth(TreeNode* temp){
        if(temp==NULL){
            return 0;
        }
        return max(find_depth(temp->left),find_depth(temp->right)) +1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int t=find_depth(root);
    if(t==0){
        vector<vector<int>> tem;
        return tem;
    }
    vector<vector<int>> ans(t);
    queue<pair<TreeNode*,int>> q1;
    q1.push({root,t});
    while(!q1.empty()){
                
        auto temp=q1.front();
        q1.pop();
        TreeNode *node=temp.first;
        int level=temp.second;
        //cout<<node->val<<"\t"<<level<<"\n";
        ans[level-1].push_back(node->val);
        if(node->left!=NULL){
            q1.push({node->left,level-1});
        }
        if(node->right!=NULL){
            q1.push({node->right,level-1});
        }
        
    }
        return ans;
        
    }
};