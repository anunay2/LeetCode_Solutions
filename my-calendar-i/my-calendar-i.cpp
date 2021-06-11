class MyCalendar {
public:
    vector<pair<int,int>> calender;
    MyCalendar() {
    }
    
    int collides(int start1, int end1, int start2, int end2){
        if(end1<start2 || end2<start1){
            return 1;
        }
        if(end2==start1){
            return 2;
        }
        if(end1==start2){
            return 3;
        }
        return 0;
    }
    bool book(int start, int end) {
        for(int i=0;i<calender.size();i++){
            int start1=calender[i].first;
            int end1=calender[i].second;
            int temp = collides(start1,end1,start,end);
            //cout<<start1<<"\t"<<end1<<"\t"<<start<<"\t"<<end<<"\t"<<temp<<"\n";
            if(temp==0){
                return false;
            }
        }
        calender.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */