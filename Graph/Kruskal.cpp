vector<int> parent;
vector<int> rank;

int find(int i)
{
    if (parent[i] != i)
        parent[i] = find(parent[i]);

    return parent[i];
}

void Union(int x, int y)
{
    int p_x = find(x);
    int p_y = find(y);

    if (p_x != p_y)
    {
        if (rank[p_x] > rank[p_y])
        {
            parent[p_y] = p_x;
        }
        else if (rank[p_y] > rank[p_x])
        {
            parent[p_x] = p_y;
        }
        else
        {
            parent[p_x] = p_y;
            rank[p_y]++;
        }
    }
}

int kruskal(vector<vector<int>>& minimumEdge){
	     int ans = 0;
	     for(auto&vec :minimumEdge){
	         
	          if(find(vec[1]) != find(vec[2])){
	              ans+=vec[0];
	             Union(vec[1],vec[2]);
	          }
	     }
	     return ans;
	 }
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        parent.resize(V);
        rank.resize(V,0);
        for(int i = 0 ; i< V;i++){
            parent[i]=i;
        }
        vector<vector<int>>minimumEdge;
        
        for(int i = 0 ; i < V ;i++){
            
            for(auto& it : adj[i]){
                minimumEdge.push_back({it[1],i,it[0]});
            }
        }
        
        sort(minimumEdge.begin(),minimumEdge.end());
        
        return kruskal(minimumEdge);
        
    }