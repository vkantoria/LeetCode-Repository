class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> ans;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
               ans.push_back(0); 
               st.push({temperatures[i],i}); 
            }
            else if(st.top().first > temperatures[i]){
                ans.push_back(st.top().second - i);
                st.push({temperatures[i],i});
                
            }
            else if(st.top().first <= temperatures[i])
            {
                while(!st.empty() && st.top().first <= temperatures[i] )
                {
                    st.pop();
                }
                if(st.empty())
                {
                    ans.push_back(0);
                  
                }
                else
                {
                    ans.push_back(st.top().second - i);
                   
                }
                   st.push({temperatures[i],i});
            }
        }
        //cout<<st.size();
        reverse(ans.begin(),ans.end());
        
       return ans; 
    }
};