class Solution {
public:
    int memo[1<<16][16];
    int N;
    int dfs(int bm,int pl){
        if(memo[bm][pl]!=-1){
            return memo[bm][pl];
        }
        if(pl==0){
            return 1;
        }
        int S=0;
        for(int i=0;i<N;i++){
            if( !(bm & 1<<i) && ((i+1)%pl==0 || pl%(i+1)==0 ) ){
                
                S = S + dfs( bm ^(1<<i),pl-1 );
                
            }
        }
        memo[bm][pl]=S;
        return S;
        
    }
    int countArrangement(int n) {
        N=n;
        memset(memo, -1, sizeof(memo[0][0]) * (1<<16) * 16);
        //cout<<memo[1][0];

        return dfs(0,n);
        
        
    }
};