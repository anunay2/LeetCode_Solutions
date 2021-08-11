class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    int minFlipsMonoIncr(string s) {
        vector<int> left0(s.size(),0);
        vector<int> right1(s.size(),0);
        int ans;
        left0[0]=s[0]=='0'?0:1;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                left0[i] =left0[i-1]+1; 
            }
            else{
                left0[i] = left0[i-1];
            }
        }
        right1[s.size()-1] = s.back()=='1'?0:1;
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]=='0'){
                 right1[i] = right1[i+1] +1;
            }
            else{
                right1[i] = right1[i+1];
            }
        }
        ans = min(left0.back(),right1[0]);
        for(int i=0;i<s.size()-1;i++){
            ans = min(ans,left0[i]+right1[i+1]);
        }
        return ans;
    
        
        
    }
};