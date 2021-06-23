class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        vector<int> index[26];
        //unordered_map<char,vector<int>> index;
        
        for(int i=0;i<s.size();i++){
            index[s[i]-'a'].push_back(i);
        }
        
        for(auto word : words){
            int min_index=-1,flag=-1;
            for(int i=0;i<word.size();i++){
                //vector<int> temp = index[word[i]-'a'];
                auto it = upper_bound( index[word[i]-'a'].begin(), index[word[i]-'a'].end(), min_index);
               // cout<<min_index<<"\t";
                if(it!=index[word[i]-'a'].end()){
                    min_index = *it;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag!=1){
                //cout<<word<<"\t";
                ans++;
            }
            
        }
        
        return ans;
    }
};