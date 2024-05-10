class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	typedef pair<int,int> pii;
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        pq.push({0,0});
        
        vector<bool>vis(V,false);
        

        int ans= 0;
        while(!pq.empty()){
             auto vec = pq.top();
             int wt =vec[0];
             int node = vec[1];
             pq.pop();  
               
               if(vis[node]){
                   continue;
               }
              vis[node]=true;

              ans+=wt;
              
             for(auto it : adj[node]){
                    if(!vis[it[0]])
                    pq.push({it[1] ,it[0]});
              }
         }
        
        return ans;
    }
};