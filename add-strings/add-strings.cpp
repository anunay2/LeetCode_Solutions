class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    string addStrings(string num1, string num2) {
        int x = num1.size()-1,y= num2.size()-1;
        string res;
        int carry =0,sum;
        while(x>=0 && y>=0){
            int sum = num1[x]-'0' + num2[y]-'0' + carry;
            carry = sum/10;
            sum = sum%10;
            res.push_back(sum+'0'); 
            x--;
            y--;
        }
        int index = x==0?y:x;
        while(x>=0){
            int sum = num1[x]-'0'+ carry;
            carry = sum/10;
            sum = sum%10;
            res.push_back(sum+'0'); 
            x--;
        }
        while(y>=0){
            int sum = num2[y]-'0' + carry;
            carry = sum/10;
            sum = sum%10;
            res.push_back(sum+'0'); 
            y--;
        }
        if(carry>0){
            res.push_back('1');
        }     
        reverse(res.begin(), res.end());
        return res;
    }
};