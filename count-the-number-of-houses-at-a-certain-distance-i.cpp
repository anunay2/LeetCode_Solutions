/*

https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/



*/

class Solution {
public:
    int mod(int x){
        return x<0 ?-x : x;
    }
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> distPairs(n);
        for( int i = 1; i<=n ; i++){
            for(int j = 1; j <=n; j++){
                if( i!= j){
                    int d1 = mod(i-j);
                    int d2 = mod(x-i) + 1 + mod(j-y);
                    int d3 = mod(y-i) + 1 + mod(x-j);
                    int minDist = min(d1, d2);
                    minDist = min(minDist, d3);
                    distPairs[minDist-1]++;
                }
            }
        }
        return distPairs;
    }
};
