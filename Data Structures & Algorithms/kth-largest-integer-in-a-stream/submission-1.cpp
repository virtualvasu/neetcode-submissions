//kth largest => min of top K elem
//maintain min heap (prior. queue)
//whenver add:
// push to min heap
//if len>k, pop => removes smallest elem
// top of min heap => smallest in top K => Kth largest 


class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int k=0;

    KthLargest(int k, vector<int>& nums) {

        this->k = k;
        for(int i =0; i<nums.size(); i++)
        {

            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        
    }
    
    int add(int val) {

        int k = this->k;

         pq.push(val);

        if(pq.size()>k){
            pq.pop();
           

        }

        return pq.top();
        
        
    }
};
