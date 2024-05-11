//Connected components = number of times we need to do dfs to cover the entire graph
// Strongly connected omponents = Topo sort + Reverse Edges + Connected components.



	void topo(int u ,vector<vector<int>>& adj,vector<int>&vis,stack<int>& st){
	    
	     vis[u]=1;
	     
	     for(auto& it: adj[u]){
	         
	         if(!vis[it]){
	             
	             topo(it,adj,vis,st);
	         }
	     }
	     st.push(u);
	}
	
	
	
	void dfs(int u ,unordered_map<int,vector<int>>& mp,vector<int>& vis )
	{
	    vis[u]=1;
	    
	    for(auto& it: mp[u]){
	        
	        if(!vis[it]){
	            dfs(it,mp,vis);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        
        stack<int>st;
        vector<int>vis(V,0);
        
        // toposort to get the order
        for(int i = 0 ; i < V ;i++){
            
            if(!vis[i]){
                topo(i,adj,vis,st);
            }
        }
        
        
        // reverse the edges
        unordered_map<int,vector<int>>mp;
        
        vis = vector<int>(V,0);
        
        for(int i = 0 ; i < V;i++){
            
            for(auto& v:adj[i]){
                
                mp[v].push_back(i);
            }
        }
        
        int ans =0;
        
        // traverse dfs according to topo order
        
        while(!st.empty()){
            
            int top = st.top();
            st.pop();
            
            if(!vis[top]){
                dfs(top,mp,vis);
                ans++;
            }
             
        }
        return ans;
    }