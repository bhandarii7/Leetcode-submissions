// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void fun(vector<int>arr,vector<int>&ans,int &sum,int i,int n)
    {
        if(i==n)
        {
           ans.push_back(sum);
           return;
        }
        
        sum+= arr[i];
        fun(arr,ans,sum,i+1,n);
        sum-=arr[i];
        fun(arr,ans,sum,i+1,n);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        int sum =0;
        
        fun(arr,ans,sum,0,N);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends