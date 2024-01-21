/*
https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/
*/

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> buttonMap;
        int numOfTimesButtonPressed = 1, ans = 0;
        for(char ch : word){
            if ( buttonMap.count(ch)){
                ans += buttonMap[ch];
            }
            else{
                buttonMap[ch] = numOfTimesButtonPressed;
                ans += numOfTimesButtonPressed;
            }
            if( buttonMap.size()==8 || buttonMap.size()==16 ||  buttonMap.size() ==24 ){
                numOfTimesButtonPressed++;
            }
        }
        return ans;

    }
};
