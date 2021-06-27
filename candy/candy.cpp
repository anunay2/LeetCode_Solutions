class Solution {
public:
    bool static comp(pair<int,int> p1,pair<int,int> p2){
        return p1.second<p2.second;
    }
    int candy(vector<int>& ratings) {
        vector<pair<int,int>> rates;
        for(int i = 0;i<ratings.size();i++){
            rates.push_back(make_pair(i,ratings[i]));
        }
        sort(rates.begin(),rates.end(),comp);
        vector<int> ans(ratings.size(),0);
        int sum=0;
        for(auto x:rates){
            int i = x.first;
            int r = x.second;
            int t1 = 0, t2 = 0;
            if(i-1>=0 && ratings[i-1]<r){
                t1 = ans[i-1];
            }
            if(i+1<ans.size() && ratings[i+1]<r){
                t2 = ans[i+1];
            }
            ans[i] = max(t1,t2)+1;
            //cout<<t1<<"\t"<<t2<<"\t"<<i<<"\t"<<ans[i]<<"\n";
            sum+=ans[i];
            
            
        }
        return sum;
    
    }
};