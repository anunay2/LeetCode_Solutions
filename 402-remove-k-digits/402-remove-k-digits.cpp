class Solution {
public:
    string removeKdigits(string num, int k) {
        if( k >= num.size()){
            return "0";
        }
        deque<char> incDigits;
        int i = 0;
        while( i < num.size()){
            if(incDigits.size() == 0 || incDigits.back() <= num[i] || k==0){
                incDigits.push_back(num[i]);
                i++;
            }
            else{
                incDigits.pop_back();
                k--;
            }  
        }
        string ans = "";
        //remove leading zeros
        while(!incDigits.empty() && k){
            incDigits.pop_back();
            k--;
        }
        while( !incDigits.empty() && incDigits.front()=='0'){
            incDigits.pop_front();
        }
        while(!incDigits.empty()){
            ans.push_back(incDigits.front());
            incDigits.pop_front();
        }
        return ans==""?"0":ans;
   }
};