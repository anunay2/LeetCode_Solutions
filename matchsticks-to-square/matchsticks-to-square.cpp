class Solution {
public:
    bool recMakeSquare(vector<int> &match, vector<bool> visited, int i, int k, int target,int subsum){
        if(k == 1){
            return true;
        }
        if(subsum == target){
            return recMakeSquare(match, visited, 0, k-1,target,0);
        }
        for(int j = i; j<match.size(); j++){
            if(visited[j] || subsum + match[j] > target)
                continue;
            visited[j]=true;
            if(recMakeSquare(match, visited, j+1, k,target,subsum+match[j] )){
                return true;
            }
            visited[j]=false;
        }
        
        return false;
    }
    bool makesquare(vector<int>& match) {
        int sum =0;
        for(auto x : match){
            sum+=x;
        }
        if(sum%4!=0 || match.size()<4){
            return false;
        }
        vector<bool> visited(match.size(),false);
        return recMakeSquare(match, visited, 0, 4, sum/4,0);
    }
};