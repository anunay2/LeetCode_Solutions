class Solution {
public:
    string maxValue(string n, int x) {
        //positive case -> 583 2 = 5832 
        //greater than greatest digit -> 95832
        //mid    583 4 ={5483,5843,5834}
        
        //negative case -> -583 2 = -2583
        //greater than greatest digit -> -5839
        //mid -583 4 = {-4583,-5483, -5843,-5834 }
        

        if(n[0]=='-'){
                for(int i=1;i<n.size();i++){
                    int d=n[i]-'0';
                    if(d>x){
                       return n.substr(0,i) + to_string(x) + n.substr(i);
                        
                    }
                }
                return n + to_string(x);
        }
            
        else{
            for(int i=0;i<n.size();i++){
                int d=n[i]-'0';
                if(x>d){
                    return n.substr(0,i) + to_string(x) + n.substr(i);
                }
            }
            return n+to_string(x);
        }
        return "-1";
        
    }
};