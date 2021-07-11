class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> freq(26);
        for(int i =0;i<s.size(); i++){
            char x = s[i];
            freq[x-'a'].push_back(i);
        }
        int count = 0;
        for(int i=0;i<26;i++){
            if(freq[i].size()<2){
                continue;
            }
            vector<int> temp = freq[i];
            int l = temp.front();
            int h = temp.back();
          //  cout<<l<<"\t"<<h<<"\n";
            for(int j =0;j<26;j++){
                vector<int> find = freq[j];
            
                auto itr = upper_bound(find.begin(),find.end(),l);
                if(itr!=find.end()){
                   // int index = itr - find.begin();
                    if(*itr<h){
                        // cout<<i;
                        // cout<<j;
                        // cout<<i ;
                        // cout<<"\n";
                        count++;
                    }
                }
            }
        }
        return count;
        
    }
};