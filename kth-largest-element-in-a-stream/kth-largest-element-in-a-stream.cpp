class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int y;
    KthLargest(int k, vector<int>& nums) {
        y = k;
        for(int i=0;i<min(k,int(nums.size()));i++)
        {
            pq.push(nums[i]);
        }
        if(k<nums.size())
        {
           for(int i=k;i<nums.size();i++)
        {
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
         
        }
        
    }
    
    int add(int val) {
        if(pq.size()<y)
        {
            pq.push(val);
        }
        else if(val>pq.top())
        {
            pq.pop();
            pq.push(val);
        }
          return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */