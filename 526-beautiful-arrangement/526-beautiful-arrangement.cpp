class Solution {
public:
    int count = 0;
    void countArrangementUtil(vector<bool> &numTaken, int idx, int n){
        if( idx>n){
            count++;
            return;
        }
        
        for( int i = 1; i<=n ;i++){
            if(!numTaken[i]  && (idx%i == 0 || i%idx==0)){
                numTaken[i] = true;
                countArrangementUtil(numTaken, idx + 1, n);
                numTaken[i] = false;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<bool> numTaken(n+1,false);
        countArrangementUtil(numTaken,1,n);
        return count;
    }
};