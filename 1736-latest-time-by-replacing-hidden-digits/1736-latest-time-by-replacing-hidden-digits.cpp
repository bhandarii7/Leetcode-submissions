class Solution {
public:
    string maximumTime(string time) {
        
        int n = time.size();
        
        if(time[n-1]=='?')
            time[n-1] = '9';
        
        if(time[n-2]=='?')
            time[n-2] = '5';
        
        if(time[0]=='?')
        {
            if(time[1]<='3'|| time[1]=='?')
            time[0] = '2';
            else
            time[0] = '1';       
        }
        
        if(time[1]=='?')
        {
            if(time[0]=='2' || time[0]=='?')
            time[1] = '3';
            else
            time[1] = '9';    
        }
        
        
        
        return time;
                
        
    }
};