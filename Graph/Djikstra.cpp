//Djikstra

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





// Optimised 

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    typedef pair<int,int> pii;
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        set<pii>st;
        
        vector<int>weight(V,1e9);
        
        st.insert({0,S});
        weight[S]=0;
        
        while(!st.empty()){
            auto it = *st.begin();
            int dist = it.first;
            int node = it.second;
           
           st.erase(it);
            for(auto vec : adj[node]){
                 
                 int adjNode = vec[0];
                 int d = vec[1];
                if(dist+d < weight[adjNode] ){
                    
                    if(weight[adjNode] !=1e9){
                        st.erase({weight[adjNode],adjNode});
                    }
                    
                    weight[adjNode]=dist+d;
                    st.insert({dist+d , adjNode});
                }
            }
        }
        return weight;
    }
};