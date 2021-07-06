class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
    int max_sum =0;
    int maxLength(vector<string>& arr1) {
        int n = 1<<arr1.size();
        int ans = 0;
        for(int i=1;i<n;i++){
            int arr[26] = {0};
            bool flag = true;
            int sum = 0;
            for(int j =0;j<min(16,arr1.size());j++){
                if(1<<j & i){
                    for(auto ch:arr1[j]){
                        arr[ch -'a']++;
                        sum++;
                        if(arr[ch -'a']>1){
                            flag = false; 
                            break;
                        }
                    }
                    if(flag == false){
                        continue;
                    }
                    else{
                        max_sum = max(max_sum,sum);
                    }
                }
            }
        }
        return max_sum;
    }
};