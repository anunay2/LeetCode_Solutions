class Solution {
public:
    int addDigits(int num) {
        if(num==0)
            return 0;
        int m=num%9;
        if(m==0){
            return 9;
        }
        else
            return m;
    }
};