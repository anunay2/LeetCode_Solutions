class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int freq[1001];
        memset(freq,0,sizeof(freq));
        for(auto box : boxTypes){
            freq[box[1]]+=box[0];
        }
        int maxUnits=0;
        for(int i=1000;i>=0;i--){
            maxUnits+=min(truckSize,freq[i])*i;
            truckSize=max(0,truckSize-freq[i]);
        }
        return maxUnits;
    }
};