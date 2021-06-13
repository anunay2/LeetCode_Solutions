class Solution {
public:
    
    int chalkReplacer(vector<int>& chalk, int k) {
        unsigned long long int sum=0;
        for(int x: chalk){
            sum+=x;
        }
        if(k>sum){
            k=k% (int)sum; 
        }
       
        for(int i=0;i<chalk.size();i++){
            k=k-chalk[i];
            if(k<0){
                return i;
            }
        }
        return 0;
    }
};