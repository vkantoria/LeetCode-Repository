// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   long long reversedBits(long long X) {
   long long ans=0;
   long long n=X;
   for(int i=0;i<32;i++){
       ans=(ans<<1)|(n&1);
       n=n>>1;
       }
   return ans;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}  // } Driver Code Ends