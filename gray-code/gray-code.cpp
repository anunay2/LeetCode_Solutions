class Solution {
public:
    int binaryToGray(int bin){
        //check which is the most significant bit that is set
        int i;
        for(i=15;i>=0;i--){
            if(1<<i & bin){
                break;
            }
        }
        int gray=1<<i;
        while(i>=1){
            int bin1 = bin & (1<<i);
            int bin2 = bin & (1<<(i-1));
            bin1 = bin1>>1;
            
            gray = gray | (bin1 ^ bin2);
            
            i--;
        }
        
       return gray; 
    }
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i < 1<<n ; i++ ){
            ans.push_back(binaryToGray(i));
            
            
        }
        return ans;
    }
};