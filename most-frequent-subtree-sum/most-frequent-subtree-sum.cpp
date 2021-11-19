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
    unordered_map<int,int> sumFreq;
    int maxSum = INT_MIN;
    int formSubtreeSum(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        root->val = root->val + formSubtreeSum(root->left) + formSubtreeSum(root->right);
        int x = ++sumFreq[root->val];
        maxSum = std::max(x,maxSum);
        return root->val;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
    
        formSubtreeSum(root);
        vector<int> ans;
        for(auto x: sumFreq){
            //cout<<x.first<<"\t"<<x.second<<"\n";
            if(x.second == maxSum){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};