class Solution {
public:
    int minSetSize(vector<int>& arr) {
       vector<int> freq(100001,0);
        for(int x : arr){
            freq[x]++;
        }
        sort(freq.begin(),freq.end());
        int sum = 0,count=0;
        for(int i = freq.size()-1;i>=0;i--){
            sum = sum + freq[i];
            count++;
            if(sum>=arr.size()/2){
                return count;
            }
        }
        return -1;
        
    }
};