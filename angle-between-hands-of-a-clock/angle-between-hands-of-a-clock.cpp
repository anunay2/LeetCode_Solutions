class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minute_angle=minutes*6;
        if(hour==12){
            hour=0;
        }
        double hour_angle=(hour)*30+(1.0/12)*minutes*6;
        double dif=(hour_angle-minute_angle);
        dif=dif<0?dif*-1:dif;
        return min(dif,360-dif);
    }
};