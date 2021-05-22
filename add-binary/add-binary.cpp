class Solution {
public:
    string addBinary(string a, string b){
        string ans="";
        int ai=a.size()-1,bi=b.size()-1;
        char c='0';
        while(ai>=0 || bi>=0){
            char x=ai>=0?a[ai]:'0',y=bi>=0?b[bi]:'0';
            ai--;
            bi--;
            if(x=='0' && y=='0' && c=='0'){
                ans='0'+ans;
                c='0';
            }
            else if(x=='0' && y=='0' && c=='1'){
                ans='1'+ans;
                c='0';
            }
            else if(x=='1' && y=='0' && c=='0'){
                ans='1'+ans;
                c='0';
            }
            else if(x=='1' && y=='0' && c=='1'){
                ans='0'+ans;
                c='1';
            }
            else if(x=='0' && y=='1' && c=='0'){
                ans='1'+ans;
                c='0';
            }
            else if(x=='0' && y=='1' && c=='1'){
                ans='0'+ans;
                c='1';
            }
            else if(x=='1' && y=='1' && c=='0'){
                ans='0'+ans;
                c='1';
            }
            else if(x=='1' && y=='1' && c=='1'){
                ans='1'+ans;
                c='1';
            }
            
        }
        if(c=='1'){
            ans='1'+ans;
        }
        return ans;
    }
};