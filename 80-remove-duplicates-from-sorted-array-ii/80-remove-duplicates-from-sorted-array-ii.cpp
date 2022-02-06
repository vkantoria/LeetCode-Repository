class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int count=1,j,i=1;
       
        for(int j=1;j<n;j++)
        {
            if(nums[j-1] == nums[j])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            
            if(count<=2)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};