class Solution {
public:
    int rob(vector<int>& nums) {
         vector<int> ans(nums.size()+1);
        ans[0] = 0;
        ans[1] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            ans[i+1] = max(ans[i], nums[i]+ans[i-1]);
        }
           return ans[nums.size()]; 
    }
};