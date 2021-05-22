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
   
    int maxpath(TreeNode *A,int &res){
    if(A==NULL)
        return 0;
    int L=maxpath(A->left,res);
    int R=maxpath(A->right,res);
    int max3=(L+R)+A->val;
    int max4=L+A->val;
    int max5=R+A->val;
    int max6=A->val;
    //max3=max3>max2?max3:max2;
    //max3=max3>max1?max3:max1;
    max3=max3>max4?max3:max4;
    max3=max3>max5?max3:max5;
    max3=max3>max6?max3:max6;
        //cout<<A->val<<"\t"<<max1<<"\t"<<max2<<"\t"<<max4<<"\t"<<max5<<"\t"<<max6<<"\t"<<max3<<"\n";
    res=res>max3?res:max3;
    return max(max(L,R)+max6,max6);
   
   
    }
    int maxPathSum(TreeNode* root){
        int res=INT_MIN;
        maxpath(root,res);
        return res;    
    }
};