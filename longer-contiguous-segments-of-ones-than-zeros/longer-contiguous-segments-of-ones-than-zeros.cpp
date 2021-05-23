class Solution {
public:
    bool checkZeroOnes(string s) {
        int run1=0,max1=0,run0=0,max0=0;
        for(char x: s){
            if(x=='1'){
                run1++;
                max1=max(run1,max1);
            }
            else{
                run1=0;
            }
            if(x=='0'){
                run0++;
                max0=max(run0,max0);
            }
            else{
                run0=0;
            }
        }
        return max1>max0;
    }
};