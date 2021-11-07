class Solution {
public:
    string add(string num1, string num2){
        int i =  num1.size() - 1, j = num2.size() - 1;
        string add="";
        int carry =0 , sum =0;
        while( i>=0 || j>=0){
            int x = i>=0? (num1[i--] -'0') : 0;
            int y = j>=0?  (num2[j--]-'0') : 0;
            sum = x + y + carry;
            carry = sum/10;
            sum = sum%10;
            add.push_back((char)(sum +'0'));
           // cout<<sum<<"\t"<<add<<"\n";
        }
        if(carry){
            add.push_back((char)(carry+'0'));
        }
        reverse(add.begin(),add.end());
        return add;
    }
    string multiply(string num1, string num2) {
        // cout<<add("434","300400")<<"\t"<<434+300400<<"\n";
        // cout<<add("9","9")<<"\t"<<"\t"<<18<<"\n";
        // cout<<add("100","323124")<<"\t"<<100+323125<<"\n";
        if(num1=="0" || num2=="0"){
            return "0";
        }
        vector<string> addLines;
        for(int i=num1.size()-1,k=0;i>=0;i--,k++){
            
            string addLine = "";
            
            for(int m=1;m<=k;m++){
                addLine.push_back('0');
            }
            int sum = 0,carry = 0;
            for(int j=num2.size()-1;j>=0;j--){
                sum = ((num1[i]-'0')*(num2[j]-'0')) + carry;
                carry = sum/10;
                sum = sum%10;
                addLine.push_back(sum+'0');
            }
            if(carry){
                addLine.push_back(carry+'0');
            }
            reverse(addLine.begin(),addLine.end());
            addLines.push_back(addLine);
        }
        string cum_sum = addLines[0];
        for(int i=1;i<addLines.size();i++){
            cum_sum = add(cum_sum,addLines[i]);
        }
        return cum_sum;        
    }
};