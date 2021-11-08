class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if( nums.size()== 2)
        {
            return max(nums[0], nums[1]);
        }
        vector<int> ans(nums.size());
        ans[0] = 0;
        ans[1] = nums[0];
        int maxi;
        
        for(int i=1;i<nums.size()-1;i++)
        {
            ans[i+1] = max(ans[i], nums[i]+ans[i-1]);
        }
       maxi = ans[nums.size()-1]; 
        
       fill(ans.begin(), ans.end(), 0);
        reverse(nums.begin(), nums.end());
        ans[0] = 0;
        ans[1] = nums[0];
         for(int i=1;i<nums.size()-1;i++)
        {
            ans[i+1] = max(ans[i], nums[i]+ans[i-1]);
        }
        maxi = max(ans[nums.size()-1], maxi);
        return maxi;
    }
};