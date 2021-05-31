class Solution {
public:
    int convertToInt(string str){
        int n1=0;
        for(int i=0;i<str.size();i++){
            int d=str[i]-'a';
            n1=n1*10+d;
        }
        return n1;
    } 
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return (convertToInt(firstWord)+convertToInt(secondWord))==convertToInt(targetWord);
    }
};