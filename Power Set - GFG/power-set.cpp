//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void generateAllPossibleSubseq(int i,string &s, vector<string> &allPossibleString, string &sub){
	           if( i==s.size()){
	                allPossibleString.push_back(sub);
	                return;
	            }
	           sub.push_back(s[i]);
	           generateAllPossibleSubseq(i+1, s, allPossibleString, sub);
	           sub.pop_back();
	           generateAllPossibleSubseq(i+1, s, allPossibleString, sub);
	           
	    }   
	    
		vector<string> AllPossibleStrings(string s){
		    vector<string> allPossibleString;
		    string sub = "";
		    generateAllPossibleSubseq(0, s, allPossibleString, sub);
		    sort(allPossibleString.begin(), allPossibleString.end());
		    allPossibleString.erase(allPossibleString.begin());
		    return allPossibleString;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends