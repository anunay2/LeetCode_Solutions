class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour){
    
        int low=1,high=1e7,mid;
        int ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            double req_time=0;
            for(int d:dist){
                double temp=d/(mid*1.0);
                req_time=ceil(req_time)+temp;
            }
            if(req_time<=hour){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};