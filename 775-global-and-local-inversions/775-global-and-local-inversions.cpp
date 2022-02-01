class Solution {
public:
    
   long long int global_count = 0;
   long long int local_count = 0;
    
    void merge(vector<int> &nums, int l, int mid, int r)
    {
        int temp[r-l+1];
        int i = l, j = mid+1, k = 0;
        
        while(i<=mid && j<=r)
        {
            if(nums[i]<nums[j])
            {
                temp[k] = nums[i];
                k++;
                i++;
            }
            else
            {
                
                global_count += (mid-i+1); 
                temp[k] = nums[j];
                j++;
                k++;
            }
        }
        
        while(i<=mid)
        {
            temp[k] = nums[i];
            i++;
            k++;
        }
        
         while(j<=r)
        {
            temp[k] = nums[j];
            j++;
            k++;
        }
        
        for(int i=0;i<k;i++)
        {
            nums[l+i] = temp[i];
        }
    }
    
    void mergesort(vector<int> &nums, int l, int r)
    {
        if(l<r)
        {
            int mid = (l+r)/2;
            mergesort(nums, l, mid);
            mergesort(nums, mid+1, r);
            merge(nums, l, mid, r);
            
        }
    }
    
    bool isIdealPermutation(vector<int>& nums) {
        
        if(nums.size() == 1)
            return true;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                local_count += 1;
            }
        }
        
        mergesort(nums, 0, nums.size()-1);
        
        // cout<<global_count<<" "<<local_count;
        
        return (local_count == global_count)?true:false; 
    }
};