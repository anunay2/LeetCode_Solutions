class Solution {
public:
    bool equal(vector<vector<int>> &mat, vector<vector<int>> &target){
        int n=mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]!=target[i][j]){
                    return false;
                }
            }
        }
        return true;
        
    }
    void rotate(vector<vector<int>> &mat){
        vector<vector<int>> mat1;
        int n=mat.size();
        for(int col=0; col<n; col++){
            vector<int> temp;
            for(int row = n-1; row>=0 ; row--){
                temp.push_back(mat[row][col]);
            }
            mat1.push_back(temp);
        }
        mat=mat1;;
        
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        for(int i=0;i<4;i++){
            rotate(mat);
            if(equal(mat,target)){
                return true;
            }
        }
        return false;
        
    }
};