//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> maxSum(n,0);
	    maxSum[0] = arr[0];
	    int ans = arr[0];
	    for(int i = 1; i<n; i++){
	        maxSum[i] = arr[i];
	        ans = max(maxSum[i], ans);
	        for( int j = 0; j<i; j++){
	            if( arr[i] > arr[j] && maxSum[j] + arr[i] > maxSum[i]){
	               maxSum[i] = maxSum[j] + arr[i];
	               ans = max(maxSum[i],ans);
	            }
	        }
	        //cout<<maxSum[i]<<"\t";
	    }
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends