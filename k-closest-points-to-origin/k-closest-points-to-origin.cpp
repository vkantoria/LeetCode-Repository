class Solution {
public:
    
   static bool comp(pair<int, double> &a, pair<int, double> &b)
    {
        return a.second<b.second;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
        vector<pair<int, double>> temp;
        for(int i=0;i<points.size();i++)
        {
            double res = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            temp.push_back(make_pair(i, res));
        }
        sort(temp.begin(), temp.end(),comp);
        for(int i=0;i<k;i++)
        {
            ans.push_back(points[temp[i].first]);
        }
        return ans;
    }
};