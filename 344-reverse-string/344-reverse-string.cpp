class Solution {
public:
    
    void turn(int i,int n,vector<char>&s)
    {
        if(i>n)
            return;
        swap(s[i++],s[n--]);
        turn(i,n,s);
    }
    void reverseString(vector<char>& s) {
        int i = 0;
        int n = s.size()-1;
        
        turn(i,n,s);
    }
};