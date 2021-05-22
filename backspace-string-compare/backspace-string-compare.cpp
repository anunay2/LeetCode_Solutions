class Solution {
public:

    bool backspaceCompare(string S, string T) {
        stack<char> s1,s2;
        for(int i=0;i<S.size();i++){
            if(S[i]=='#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(S[i]);
            }
        }
        
         for(int i=0;i<T.size();i++){
            if(T[i]=='#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }
            else{
                s2.push(T[i]);
            }
        }
        
        //check if
        while(!s1.empty() && !s2.empty()){
            char c1=s1.top();
            s1.pop();
            char c2=s2.top();
            s2.pop();
            if(c1!=c2){
                return false;
            }
        }
        
        return (s1.empty()==s2.empty());
        
        
        
    }
};