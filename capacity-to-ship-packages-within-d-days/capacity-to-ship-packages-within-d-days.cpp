class Solution {
public:
    bool possible(vector<int> &weights,int cap,int D){
        int li=0;        
        for(int i=0;i<D;i++){
            int sum=0;
            while(li<weights.size()){
                if(sum+weights[li]<=cap){
                    sum+=weights[li];
                    li++;
                }
                else{
                    break;
                }
            }
            //cout<<sum<<"\n";
        }
        if(li==weights.size())
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int sum=0;
        for(auto x:weights){
            sum+=x;
        }
        int low=(int)sum/D,high=sum,ans;
        while(low<=high){
            int mid=(low+high)/2;
            //cout<<low<<"\t"<<mid<<"\t"<<high<<"\n";
            if(possible(weights,mid,D)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};