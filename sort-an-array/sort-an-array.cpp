class Solution {
public:
    
     void merge(vector<int> &arr, int l, int mid, int r)
     {
        vector<int> temp(r-l+1);
        int i = l, j = mid+1, k = 0;
        while(i<=mid && j<= r)
        {
            if(arr[i]<=arr[j])
            {
               temp[k] = arr[i];
               i++;
               k++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
                k++;
            }
        }
        while(i<=mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while(j<=r)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
         for(int i = 0;i<k;i++)
         {
             arr[l+i] = temp[i];
         }
        
    }
        void mergesort(vector<int>  &arr, int l, int r)
       {
        if(l<r)
        {
            int mid = (l+r)/2;
            mergesort(arr, l, mid);
            mergesort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
       }
    
    
    vector<int> sortArray(vector<int>& arr) {
         int N = arr.size();
         mergesort(arr, 0, N-1);
         return arr;
    }
};