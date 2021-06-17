class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int left,right;
        unordered_map<string,int> wordSet;
        vector<vector<int>> ans;
        for(int i=0;i<words.size();i++){
            wordSet[words[i]]=i;     
        }
        if(wordSet.find("")!=wordSet.end()){
            for(int j=0; j<words.size() ; j++){
                string word = words[j];
                int l=0;
                int r =word.size()-1;
                
                while(l<word.size()  && r>=0 && word[l]==word[r]){
                    l++;
                    r--;
                }
                
                if(word!="" && r==-1){
                    ans.push_back({wordSet[""],j});
                    ans.push_back({j,wordSet[""]});    
                }
            }
            
            
        }
    
        for(int j=0;j<words.size();j++){
            string word = words[j];
            cout<<word<<"\n";
            for(int i=0;i<word.size();i++){
                int n=word.size();
                left = i-1;
                right = i;
                while(left>=0 && right<n && word[left]==word[right]){
                    left--;
                    right++;
                }
                if(left==-1 && right!=n){
                    string temp = word.substr(right);
                    reverse(temp.begin(),temp.end());
                    if(wordSet.find(temp)!=wordSet.end() && wordSet[temp]!=j){
                        cout<<"1.1"<<"\t"<<i<<"\t"<<temp<<"\n";
                        ans.push_back({wordSet[temp],j});
                    }
                }
                if(right==n && left!=-1){
                    string temp = word.substr(0,left+1);
                    reverse(temp.begin(),temp.end());
                    if(wordSet.find(temp)!=wordSet.end() && wordSet[temp]!=j){
                        cout<<"1.2"<<"\t"<<i<<"\t"<<temp<<"\n";
                        ans.push_back({j,wordSet[temp]});
                    }
                }
                left=i-1;
                right=i+1;
                while(left>=0 && right<n && word[left]==word[right]){
                    left--;
                    right++;
                }
                if(left==-1 && right!=n){
                    string temp = word.substr(right);
                    reverse(temp.begin(),temp.end());
                    if(wordSet.find(temp)!=wordSet.end() && wordSet[temp]!=j ){
                        cout<<"2.1"<<"\t"<<i<<"\t"<<temp<<"\n";
                        ans.push_back({wordSet[temp],j});
                    }
                }
                if(right==n && left!=-1){
                    string temp = word.substr(0,left+1);
                    reverse(temp.begin(),temp.end());
                 
                    if(wordSet.find(temp)!=wordSet.end() && wordSet[temp]!=j ){
                        cout<<"2.2"<<"\t"<<i<<"\t"<<temp<<"\n";
                        ans.push_back({j,wordSet[temp]});
                    }
                }
            }
            
        }
        return ans;
        
    }
};