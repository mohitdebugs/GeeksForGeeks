class Solution 
{
    public:
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int last_dfs;
	    vector<bool>vis(V,false);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,V,adj,vis);
	            last_dfs=i;
	        }
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        vis[i]=false;
	    }
	    dfs(last_dfs,V,adj,vis);
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==false)
	        {
	            return -1;
	        }
	    }
	    return last_dfs;
	}
	void dfs(int start,int V, vector<int>g[],vector<bool>&vis)
    {
        vis[start]=true;
        for(auto node:g[start])
        {
            if(!vis[node])
            {
                dfs(node,start,g,vis);
            }
        }
    }

};
