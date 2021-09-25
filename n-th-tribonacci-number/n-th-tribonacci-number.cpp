class Solution {
public:
    int tribonacci(int n) {
        vector<int> trib(n+1,1);
        trib[0] = 0;
        if(n<=2){
            return trib[n];
        }
        for(int i=3;i<=n;i++){
            trib[i] = trib[i-1] + trib[i-2] + trib[i-3];
        }
        return trib[n];
        
    }
};