class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        //pop and smash with top
        //repeat untill size ==0

        priority_queue<int, vector<int>> pq;

        for(int i =0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }
        
        while(pq.size()>1)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();

            pq.push(x-y);

        }

        if(pq.size()) return pq.top();
        return pq.size();
    }
};
