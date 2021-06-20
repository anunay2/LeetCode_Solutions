class Solution {
public:
    int to_integer(string s){
        int temp=0;
        for(char c:s){
            temp =  temp*10 +(c-'0');
        }
        return temp;
    }
    int parse(string s){
        string HH="";
        int i=0;
        while(s[i]!=':'){
            HH = HH + s[i];
            i++;
        }
        i++;
        string MM="";
        while(i<s.size()){
            MM = MM + s[i];
            i++;
        }
        return to_integer(HH)*100+to_integer(MM);
    }
    int countRounds(vector<int> &time,int sTime, int fTime){
        int count=0;
        for(int t=0;t<time.size()-1;t++){
            int x=time[t];
            int y = time[t+1];
            if(sTime<=x && fTime>=y){
                count++;
            }
        }
        return count;
    }
    int numberOfRounds(string startTime, string finishTime) {
        vector<int> HH = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
        vector<int> MM ={0,15,30,45};
        vector<int> time;
        for(int h:HH){
            for(int m:MM){
                time.push_back(h*100+m);
                //cout<<time.back()<<"\t";
            }
        }
        
        int sTime = parse(startTime);
        int fTime = parse(finishTime);
        //cout<<sTime<<"\t"<<fTime<<"\n";
        if(fTime>sTime){
            return countRounds(time,sTime,fTime);
        }
        
        if(fTime<sTime){
            if(sTime>2345){
                return countRounds(time,sTime,2359)+countRounds(time,0,fTime);
            }
            return countRounds(time,sTime,2359)+countRounds(time,0,fTime)+1;
        }
        
        return -1;
        
        
    }
};