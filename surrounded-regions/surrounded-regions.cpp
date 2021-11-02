class Solution {
public:
    bool withinLimits(int R,int C,int i,int j){
    return (i>=0 && j>=0 && i<R && j<C);
}
void dfs(int i,int j,vector<vector<char>> &A,int R,int C){
    //cout<<i<<"\t"<<j<<"\t"<<A[i][j]<<"\n";
    A[i][j]='o';
    if(withinLimits(R,C,i+1,j) && A[i+1][j]=='O'){
        dfs(i+1,j,A,R,C);
    }
    if(withinLimits(R,C,i-1,j) && A[i-1][j]=='O'){
          dfs(i-1,j,A,R,C);
    }

    if(withinLimits(R,C,i,j+1) && A[i][j+1]=='O'){
          dfs(i,j+1,A,R,C);
    }

    if(withinLimits(R,C,i,j-1) && A[i][j-1]=='O'){
          dfs(i,j-1,A,R,C);
    }
    return;
}
    void solve(vector<vector<char>>& A) {
        int R=A.size();
        if(R==0){
            return;
        }
        int C=A[0].size();
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if((i==R-1 || j==C-1 || i==0 || j==0) && A[i][j]=='O')
                    dfs(i,j,A,R,C);
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(A[i][j]=='o'){
                    A[i][j]='O';
                }
                else{
                    A[i][j]='X';
                }
            }
        }
    }
};