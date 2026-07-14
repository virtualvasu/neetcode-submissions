//traverse grid one elem at a time
//maintain global max
//if elem =1, initialize a local area, call helper on it
//update global max
//return global max

//helper:
//mark this elem zero, area++
//use boundary condn : imp
//and call helper on up, down, right , left
//return area

class Solution {
public:

    int helper(vector<vector<int>>& grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(x>=m || y>=n || y<0 || x<0) return 0;
        if(grid[x][y] == 0) return 0;

        grid[x][y] = 0;
        
        return 1 +
         helper(grid, x-1, y) +
         helper(grid, x+1, y) +
         helper(grid, x, y-1) +
         helper(grid, x, y+1);

      
    }
     int maxAreaOfIsland(vector<vector<int>>& grid) {

        int x = grid[0].size();
        int y = grid.size();
        int count=0;
        int max_area =0;

        for(int i =0;i<y;i++)
        {
            for(int j =0;j<x;j++)
            {
                if(grid[i][j] == 1)
                {
                    count+=1;
                    max_area = max(max_area, helper(grid, i, j));     
                    
                }
            }
        }

        return max_area;
        
    }
};


