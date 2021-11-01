class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int m = gas.size();
        int sum1 = 0, sum2 = 0;
        
        for(int i=0;i<m;i++)
        {
           sum1 += gas[i];
           sum2 += cost[i];
        }
        
        if(sum2>sum1)
            return -1;
        int start = gas[0];
        int j = 0;
        for(int i=0;i<m;i++)
        {  
           if(cost[i]>start)
           {
               if(i==m-1)
               {
                   break;
               }
              start = gas[i+1];
               j = i+1;
              continue; 
           }
            if(i == m-1)
            {
                break;
            }
           start = gas[i+1] + start - cost[i];
            
        }
       return j; 
    }
};