class Solution {
public:
    bool isOdd(int x){
        return (x%2 == 1);
    }
    int minCostToMoveChips(vector<int>& position) {
        int numOfCoinsAtOddPosition = 0,numOfCoinsAtEvenPosition = 0;
        for(auto p : position){
            if(isOdd(p)){
                numOfCoinsAtOddPosition++;
            }
            else{
                numOfCoinsAtEvenPosition++;
            }
        }
        return min(numOfCoinsAtEvenPosition, numOfCoinsAtOddPosition);
    }
};