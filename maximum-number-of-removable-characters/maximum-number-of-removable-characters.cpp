class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int low=0,high=rem.size();
        vector<int> m(s.size(),INT_MAX);
        for(int i=0;i<rem.size();i++){
            m[rem[i]] = i;
        }
        while(low<high){
            int mid = (low+high+1)/2, j =0;
            for(int i=0; i<s.size() && j<p.size(); i++){
                if(m[i]>=mid && s[i]==p[j]){
                    j++;
                }
            }
            if(j==p.size()){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};