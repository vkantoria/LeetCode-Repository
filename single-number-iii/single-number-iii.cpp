class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0;
        for(int i=0;i<nums.size();i++)
        {
            Xor ^= nums[i]; 
        }
        int pos = 0;
        for(int i=31;i>=0;i--)
        {
            if(Xor & 1 == 1)
            {
                pos = 31-i;
                break;
            } 
            Xor>>=1;
        }
        int v1 = 0,v2 = 0;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]&(1<<pos)) 
               v1 ^= nums[i];
            else
                v2 ^= nums[i];
        }
        return {v1,v2};
    }
};