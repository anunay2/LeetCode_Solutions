class Solution {
public:
    TreeNode* form(vector<int> &inorder,int is,int ie, vector<int> &preorder, int ps, int pe, unordered_map<int,int> &inordr){
        if(is>ie || ps>pe){
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[ps]);
        int index = inordr[preorder[ps]];
        int lsize = index-is;
        int rsize = ie-index;
        node->left = form(inorder, is, index-1, preorder, ps+1, 
                          ps+lsize, inordr);
        node->right = form(inorder, index+1, ie, preorder, ps+lsize+1,pe,inordr);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if(inorder.size()==0){
                return NULL;
            }
            unordered_map<int,int> inordr;
            for(int i=0;i<inorder.size();i++){
                inordr[inorder[i]]=i;
            }
            return form(inorder,0, inorder.size()-1, preorder,0,preorder.size()-1,inordr);
    }
};