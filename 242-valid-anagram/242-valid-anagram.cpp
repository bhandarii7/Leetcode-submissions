class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s==t) return true;
        
        if(s.size()!=t.size()) return false;
        
        map<char,int>m;
        
        for(int i=0;i<s.size();i++)
        {
                m[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++)
        {
          if(m[t[i]]<0) return false;
            
                m[t[i]]--;
            
        }
        
       for(auto it:m) if(it.second) return false;
            return true;
    
    }
};