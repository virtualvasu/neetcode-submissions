//visited array
//queue initially empty
//start with source, push to queue, mark it visited, add to res
//while q not empty, pop , get nb, if not visited mark visited,add to res,  push to q

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here 
        int n = adj.size();
        vector<int> visited(n, 0);
        
        vector<int> res;
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        res.push_back(0);
        
            while(!q.empty())
            {
                int front = q.front(); 
                q.pop();
                
                for(auto nb: adj[front])
                {
                    if(visited[nb] == 0)
                    {
                        q.push(nb);
                        visited[nb] =1;
                        res.push_back(nb);
                    }
                }
            }
        
        return res;
        
    }
};
