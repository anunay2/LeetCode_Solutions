class Solution {
public:
    int maxPower(string s) {
        int run = 1,maxRun = 1;
        for(int i=1;i<s.size();i++){
            if(s[i] == s[i-1]){
                run++;
                maxRun = max(maxRun, run);
            }
            else{
                run = 1;
            }
        }
        return maxRun;
    }
};