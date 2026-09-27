class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> cnt(26, 0);

        for(char c: tasks)
        {
            cnt[c-'A']++;
        }

        priority_queue<int> pq;
        for(int c: cnt)
        {
            if(c>0)
            pq.push(c);
        }

        queue<pair<int, int>> q;

        int time=0;

        while(!q.empty() || !pq.empty())
        {
            time++;

            if(!pq.empty())
            {
                int c = pq.top();
                pq.pop();
                c--;

                if(c>0)
                q.push({c, time+n});
            }

            

            if(!q.empty() && q.front().second == time)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
        
    }
};
