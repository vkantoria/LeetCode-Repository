class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int, int> ump;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ump[nums[i]]++;    
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(ump.find(i) == ump.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};