class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long int num = 0;
        vector<int> v(32,0);
        for(int i=31;i>=0;i--)
        {    int count = 0;
            for(int j=0;j<nums.size();j++)
            {
              int a = nums[j];
              if(a&1 == 1)
                  count++;
              nums[j]>>=1;
            } 
         v[i] = count;
        }
        for(int i=0;i<32;i++)
        {
            v[i] = v[i]%3;
            cout<<v[i] <<" ";
            num = num + (v[i] *  pow(2,31-i)); 
        }
        return int(num);
    }
};