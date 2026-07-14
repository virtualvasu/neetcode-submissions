//traverse matric one elem at a time
//if elem =1, increase island count, call markzero on it
//return island count

//mark zero:
//mark this elem zero
//use boundary condn : imp
//and call markzero on up, down, right , left

class Solution {
public:

    void helper(vector<vector<char>>& grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(x>=m || y>=n || y<0 || x<0) return;
        if(grid[x][y] == '0') return;

        grid[x][y] = '0';

        helper(grid, x-1, y);
        helper(grid, x+1, y);
        helper(grid, x, y-1);
        helper(grid, x, y+1);
    }
    int numIslands(vector<vector<char>>& grid) {

        int x = grid[0].size();
        int y = grid.size();
        int count=0;

        for(int i =0;i<y;i++)
        {
            for(int j =0;j<x;j++)
            {
                if(grid[i][j] == '1')
                {
                    count+=1;
                    helper(grid, i, j);
                    
                }
            }
        }

        return count;
        
    }
};
