// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
 long long int count = 0;
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
  void merge(long long arr[], long long l, long long mid, long long r)
    {
        long long  temp[r-l+1];
        long long i = l, j = mid+1, k = 0;
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
                count += (mid-i+1);
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
        for(long long int i=0;i<k;i++)
        {
            arr[l+i] = temp[i];
        }
    
    }
   void mergesort(long long arr[], long long l, long long r)
    {
        if(l<r)
        {
              long long mid = (l+r)/2;
              mergesort(arr, l, mid);
              mergesort(arr, mid+1, r);
              merge(arr, l, mid, r);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
      mergesort(arr, 0, N-1);
      return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends