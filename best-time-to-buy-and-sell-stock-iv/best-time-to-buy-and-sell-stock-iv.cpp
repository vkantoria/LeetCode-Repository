class Solution {
public:
     int dp[1001][101][2];
    
     int helper(vector<int>& prices, int k, int i, int state){
         if(k<=0)
             return 0;
    
         if(i>=prices.size())
             return 0;
         
         if(dp[i][k][state] != -1)
             return dp[i][k][state];
         
         if(state == 0)
             return dp[i][k][state] = max(-prices[i] + helper(prices, k, i+1, 1), helper(prices,k,i+1,0));
         
         if(state == 1)
             return dp[i][k][state] = max(prices[i] + helper(prices, k-1, i+1, 0), helper(prices, k, i+1, 1));  
    
             return dp[i][k][state];
     }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        helper(prices, k, 0, 0);
        return max(dp[0][k][0], 0);
    }
};