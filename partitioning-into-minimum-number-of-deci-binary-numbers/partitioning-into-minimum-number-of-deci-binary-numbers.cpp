class Solution {
public:
    int minPartitions(string n) {
        int x=-1;
        for(char num:n){
            int d = num-'0';
            x = max(d,x);
        }
        return x;
    
    }
};