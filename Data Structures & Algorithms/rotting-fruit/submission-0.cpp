//in one full pass of the grid:
//count: # of fresh oranges
//simultanously keep pushin rotten to queue
// now while !q.empty, calc size of queue, process only this many fruits
// for each if rotten, pass
//if fresh make rotten, add to queue, adjust fresh count
//min++ (only if at least one fruit infected in the cycle)
//if at end fresh count = 0, return min
//else return -1


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        int fresh=0, rotten=0, min=0;

        for(int i =0;i<grid.size(); i++)
        {
            for(int j =0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i, j});
            }

        }

        if(fresh == 0) return 0;

        

        int row = grid.size();
        int col = grid[0].size();

        while(!q.empty())
        {
            int size = q.size();
            bool infected = false;
            while(size --){

                pair<int, int> node = q.front();

                q.pop(); 

                int x = node.first;
                int y = node.second;

                if(x+1<row && grid[x+1][y] == 1) 
                {
                    grid[x + 1][y] = 2;
                    q.push({x+1, y});
                    fresh--; 
                    infected = true;
                }
                if(x-1>=0 && grid[x-1][y] == 1) 
                {
                    grid[x - 1][y] = 2;
                    q.push({x-1, y});
                    fresh--; 
                    infected = true;
                }
                if(y+1<col && grid[x][y+1] == 1) 
                {
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                    fresh--; 
                    infected = true;
                }
                if(y-1>=0 && grid[x][y-1] == 1) 
                {
                    grid[x][y-1] = 2;
                    q.push({x, y-1});
                    fresh--; 
                    infected = true;
                }

                

            }
            if(infected) min++;
           
        }

        if(fresh == 0) return min;
        return -1;
        
    }
};
