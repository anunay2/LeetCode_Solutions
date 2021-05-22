class Solution {
public:
    int threeSumMulti(vector<int>& A, int target){
        long long int sum=0,x=1000000007;
        int freq[101];
       // set<int> s1;
        memset(freq,0,sizeof(freq));
        int max1=INT_MIN;
        for(int i =0;i<A.size();i++){
            max1 = max(max1,A[i]);
            freq[A[i]]++;
           // s1.inset(A[i]);
        }   
        long long int temp=0;
        for(int i=0;i<=max1;i++){
            for(int j=i;j<=max1;j++){
                for(int k=j;k<=max1;k++){
                    
                    if(i+j+k==target && freq[i] && freq[j] && freq[k]){
                        temp=0;
                        if(i==j && j==k){
                            if(freq[i]>=3){
                                temp = (((freq[i]-1)%x)*((freq[i]-2)%x)*                                                                     (freq[i]%x))/6;   
                            }
                        }
                        else if(i==j && freq[i]>=2 && freq[k]){
                            temp = ((freq[i]-1)*freq[i]*freq[k])/2;
                        }
                        else if(j==k&& freq[k]>=2 && freq[i]){
                            temp = (freq[i]*freq[k]*(freq[k]-1))/2;          
                        }
                        else if(i==k&& freq[k]>=2 && freq[j]){
                            temp = (freq[i]*freq[j]*(freq[i]-1))/2;          
                        }
                        else if(i!=j && j!=k && freq[i]&& freq[j]&&freq[k]){
                            temp=freq[i]*freq[j]*freq[k];
                        }
                        cout<<i<<"\t"<<j<<"\t"<<k<<"\t"<<temp<<"\t"<<sum<<"\n";
                        sum =(sum+temp%x);
                        sum =sum%x;
                    }
                }
            }
        }
        return (int)sum;
        
    }
};