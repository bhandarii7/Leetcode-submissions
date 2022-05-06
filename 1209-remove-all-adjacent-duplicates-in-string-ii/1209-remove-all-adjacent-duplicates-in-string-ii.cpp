class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        
        int n = s.size();
        if(n<k) return s;
        
        stack<pair<char,int>> stk;
        for(int i=0; i<n; ++i){
            if(stk.empty() || stk.top().first != s[i]) stk.push({s[i],1});
            else{
                auto prev = stk.top();
                stk.pop();
                stk.push({s[i], prev.second+1});
            }
            if(stk.top().second==k) stk.pop();
        }
        
        string ans = "";
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            while(cur.second--){
                ans.push_back(cur.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
//         pair<char,int> p;
        
//         stack<pair<char,int>> st;
        
//         string ans;
        
//         int i =0, n =s.size() ;
        
//         while(i<n)
//         {
           
//             if(s[i]==st.top().first )
//             {
//                 auto prev = st.top();
//                 st.pop();
//                 st.push({s[i], prev.second+1});
//             }
//             else
//             {
//                 p.first = s[i];
//                 p.second = 1;
//                 st.push(p);
//             }
            
//             if(st.top().second==k)
//                 st.pop();
            
//             i++;
//         }
        
//         while(!st.empty())
//         {
//             for(int i=0;i<st.top().second;i++)
//             {
//                 ans.push_back(st.top().first);
//             }
//             st.pop();   
//         }
        
//         reverse(ans.begin(),ans.end());
        
//         return ans;
        
    }
};