class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
         int n = intervals.size();
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> temp = intervals[0];
        for(auto i:intervals)
        {
            if(i[0]<=temp[1])
            {
                int maxi = max(temp[1],i[1]);
                temp[1] = maxi;
            }
            else
            {
                ans.push_back(temp);
                temp = i;
            }
            
        }
        ans.push_back(temp);
        return ans;
        
    }
};