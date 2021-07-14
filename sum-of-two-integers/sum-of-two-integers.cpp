class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0,c =0;
        for(int i =0;i<=31;i++){
         
            int x = (1<<i) & a;
            int y = (1<<i) & b;
            c = c<<1;
            int s = x ^ y ^ c;
            
            c = x&y | c&(x^y);
     
            sum = sum | s;
            // bitset<4> b1(sum);
            // bitset<4> b2(s);
            // cout<<b1<<"\t"<<b2<<"\n";
        }
        return sum;
    }
};