// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // vector<pair<int,int>>v;
        // vector<int> ans;
        
        // int maxm = INT_MIN;
        // int count = 0, profit = 0;
        
        // for(int i=0;i<n;i++)
        // {
        //     maxm = max(maxm,arr[i].dead);
            
        //     v[i].first = arr[i].profit;
        //     v[i].second = arr[i].dead;
        // }
        
        // sort(v.begin(),v.end(),greater<>());
        
        // vector<int>vis = {maxm+1,0};
        
        // for(int i=0;i<n;i++)
        // {
        //     if(vis[v[i].second]==0)
        //     {
        //         count++;
        //         profit+=v[i].first;
        //         vis[v[i].second] = 1;
        //     }
        //     else
        //     {
        //         int k = v[i].second-1;
        //         while(k>0)
        //         {
        //             if(vis[k]==0)
        //             {
        //                 vis[k] =1;
        //                 count++;
        //                 profit+=v[i].first;
        //                 break;
        //             }
        //             k--;
        //         }
        //     }
        // }
        
        // ans.push_back(count);
        // ans.push_back(profit);
        
        // return ans;
        
        vector<pair<int, int>> job;
       vector <int> res;
       int profit = 0;
       int count = 0;
       int mx = 0;
       for(int i = 0; i < n; i++){
           mx = max(mx, arr[i].dead);
           job.push_back({arr[i].profit, arr[i].dead});
       }
       int deadline[mx + 1];
       for(int i = 0; i <= mx; i++){
           deadline[i] = -1;
       }
       sort(job.begin(), job.end());
       reverse(job.begin(), job.end());
       for(int i = 0; i < n; i++){
           // cout << job[i].first << " " << job[i].second << endl;
           int t = job[i].second;
           if(deadline[t] == -1){
               profit += job[i].first;
               deadline[t] = 1;
               count++;
               // cout<< count << " " << profit << endl;
           }
           else{
               int p = t-1;
               while(p > 0){
                   if(deadline[p] == -1){
                       profit += job[i].first;
                       deadline[p] = 1;
                       count++;
                       // cout<< count << " " << profit << endl;
                       p = 0;
                   }
                   p--;
               }
           }
       }
       res.push_back(count);
       res.push_back(profit);
       return res;
        
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends