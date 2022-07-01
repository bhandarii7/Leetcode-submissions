// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       vector<pair<float,pair<int,int>>> v;
       
       double ans = 0;
       
       for(int i=0;i<n;i++)
       {
           float p = float(arr[i].value)/float(arr[i].weight);
           pair<int,int> in = {arr[i].value,arr[i].weight};
           
           v.push_back({p,in});
       }
       
       sort(v.begin(),v.end(),greater<>());
       
       for(int i=0;i<n;i++)
       {
           
           if(v[i].second.second<=W)
           {
               W = W-v[i].second.second;
               ans+= v[i].second.first;
           }
           else 
           {
               ans+= (double(W)/double(v[i].second.second))*v[i].second.first;
               break;
           }
    
       }
       
       
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends