//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int max3( int a, int b, int c){
        return std::max(std::max(a,b), c);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> maxValue(n + 1, vector<int>(W + 1,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=W; j++){
              if(j-wt[i]>=0){
                  if( i-1>=0){
                    maxValue[i][j] = max(maxValue[i-1][j-wt[i]] + val[i], maxValue[i-1][j] );
                  }
                else{
                    maxValue[i][j] = val[i];    
                }
              }
              else if( i-1>=0){
                  maxValue[i][j] = maxValue[i-1][j];
              }
            }
        }
        return maxValue[n-1][W];
       // Your code here
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends