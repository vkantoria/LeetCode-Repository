class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        
        for(auto i:nums)
        {
            um[i]++;
        }
        
        for(auto j:um)
        {
            if(j.second>1)
                return true;
        }
        return false;
    }
};