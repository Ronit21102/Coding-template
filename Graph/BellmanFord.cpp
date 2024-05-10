class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    typedef pair<int,int> pii;
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        
        vector<int>weight(V,1e9);
        
        pq.push({0,S});
        weight[S]=0;
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto vec : adj[node]){
                 
                 
                if(dist+vec[1] < weight[vec[0]] ){
                    weight[vec[0]]=dist+vec[1];
                    pq.push({dist+vec[1] , vec[0]});
                }
            }
        }
        return weight;
    }
};