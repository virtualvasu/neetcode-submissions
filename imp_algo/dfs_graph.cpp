//start from a node
//mark it visited, add to res
//for this node, traverse all nb
//if nb not visited, call dfs for it 

class Solution {
  public:
  
    void helper(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& res,
    int source)
    {
        visited[source] = true;
        res.push_back(source);
        
        for(auto nb: adj[source])
        {
            if(!visited[nb])
            {
                helper(adj, visited, res, nb);
            }
            
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> res;
        
        //for making sure disconnected graphs also work
        for(int i =0; i<n;i++)
        {
            if(!visited[i])
            {
                 helper(adj, visited, res, 0);
            }
        }
       
        return res;
    }
};
