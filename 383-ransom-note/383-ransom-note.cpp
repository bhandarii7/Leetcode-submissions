class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m1,m2;
        
        int n = ransomNote.size();
        int m = magazine.size();
        
        for(int i=0;i<m;i++)
        {
            m2[magazine[i]]++;
        }
    
        
        for(int i=0;i<n;i++)
        {
            if(m2.find(ransomNote[i])==m2.end() || m2[ransomNote[i]]==0)
                return false;
            
            m2[ransomNote[i]]--;
        }
        
        return true;
    }
};