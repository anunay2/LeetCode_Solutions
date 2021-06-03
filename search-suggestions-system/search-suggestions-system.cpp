class Solution {
public:
    bool static comp(string s1,string s2){
        int i=0;
        int s=min(s1.size(),s2.size());
        while(i<s && s1[i]==s2[i]){
            i++;
        }
        if(i==s1.size()){
            return true;
        }
       else if(i==s2.size()){
            return false;
        }
        return (s1[i]-s2[i])<0?true:false;
    }
    int compare(string prefix,string word){
        int i=0;
        int s=min(prefix.size(),word.size());
        while(i<s && prefix[i]==word[i]){
            i++;
        }
        if(i==prefix.size()){
            return 0;
        }
        else if(i==word.size()){
            return 1;
        }
        return prefix[i]-word[i];
        
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end(),comp);
       
//         //returns the lexicograpically first string that matches with the first word
//         for(auto str : products){
//             cout<<str<<"\t";
//         }
        
        //cout<<"\n";
        vector<vector<string>> dixt;
        string prefix="";
        
        for(int i=0;i<searchWord.size();i++){
            int low=0,high=products.size()-1;
            int ans=-1;
            prefix=prefix+searchWord[i];
            while(low<=high){
                int mid=(low+high)/2;
                int x=compare(prefix,products[mid]);
                //cout<<prefix<<"\t"<<mid<<"\n";
                if(x>0){
                    //search right as searchWord must be present
                    low=mid+1;
                }
                else if(x<0){
                    //search left
                    high=mid-1;
                }
                else{
                    high=mid-1;
                    ans=mid;   
                }
            }
            int j=ans,k=0;
            vector<string> temp;
            //cout<<"index:"<<ans<<"\t";
            while(j!=-1 && j<products.size() && k<3){
                if(compare(prefix,products[j])==0){
                    temp.push_back(products[j]);
                    j++;
                    k++;
                }
                else{
                    break;
                }
            }
            
            dixt.push_back(temp);
        }
        return dixt;

    }
};