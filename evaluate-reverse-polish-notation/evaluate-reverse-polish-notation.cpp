class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;
        int op1,op2;
        for(auto s:tokens){ 
           if(s=="+"){
                   op1=s1.top();
                   s1.pop();
                   op2=s1.top();
                   s1.pop();
                   s1.push(op1+op2);
           }
            else if(s=="-"){   
                    op1=s1.top();
                   s1.pop();
                   op2=s1.top();
                   s1.pop();
                   s1.push(op2-op1);
            }
            else if(s=="/"){
                   op1=s1.top();
                   s1.pop();
                   op2=s1.top();
                   s1.pop();
                   s1.push(op2/op1);
            }
            else if(s=="*"){
                    op1=s1.top();
                   s1.pop();
                   op2=s1.top();
                   s1.pop();
                   s1.push(op1*op2);
            }
             else
                   s1.push(stoi(s));
           }
        
        return s1.top();
    }
};