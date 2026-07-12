//create a max heap
// insert pair of (dist, point) into max heap
// if size of max heap>k, pop
//repeat for all points
//at end => only k points with least dist remain 
//return the max heap as a vector

//time complexity: O(n*logn)
//spce: O(n)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue <pair<int, pair<int, int>>> maxheap;

        for(int i=0;i<points.size();i++)
        {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxheap.push({dist, {points[i][0], points[i][1]}});

            if(maxheap.size()>k) maxheap.pop();
        }

        vector<vector<int>> ans;

         while (!maxheap.empty()) {
            auto p = maxheap.top();
            ans.push_back({p.second.first, p.second.second});
            maxheap.pop();
        }

        return ans;



        
    }
};
