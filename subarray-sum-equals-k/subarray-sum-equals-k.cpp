class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        
        um.emplace(0,1);
        int presum=0, count =0;
        
        for(int i=0;i<nums.size();i++)
        {
            presum += nums[i];
            if(um.find(presum-k) != um.end())
            {
                count += um[presum-k];
            }
            
                um[presum]++;
        }
        return count;
    }
};