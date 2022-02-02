// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isDigitSumPalindrome(int N) {
        
        int n = N, num = 0, rev = 0, sum = 0;
        while(n>0)
        {
           num += n%10;
           n = n/10;
        }
        int no = num;
        while(num>0)
        {
           sum = num%10;
           rev = rev*10 + sum;
           num = num/10;
        }
        
        return (no == rev)?1:0;
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}
  // } Driver Code Ends