class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long int low=1,high=2;
        if(m==0){
            return 0;
        }
        if(m==n){
            return m;
        }
        while(high<LONG_MAX && high>0){
            //cout<<low<<"\t"<<high<<"\n";
            if(m>=low && n<=high){
                long long int ans=m;
                for(long long int i=m+1;i<=n;i++){
                    ans=ans&i;
                }
                return (int)ans;
            }
            low=low<<1;
            high=high<<1;
        }
        return 0;
    }
};