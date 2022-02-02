// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here
        
        int n = S.size();
        int i = n-1 ,j = n-1;
        string ans = "";
        string temp = "";
        while(i>=0)
        {
           
            if(S[i] != '.')
            {
                temp = S[i] + temp;
                i--;
            }
            else
            {
                    ans += temp;
                    ans += '.';
                    temp = "";
                    i--;
            }
          
        }
        return ans+temp;
        

        
        
        
        
        
        
        
        
        
        
        
        
       
        // int n = S.size();
        // string ans = "";
        // int j = n-1, i=n-1;
        // while(i>=0)
        // {
        // 
        //   while(S[i]!='.' && i>=0)
        //   {
        //       i--;
        //   }
        //   int t = i;
        //   while(t<j)
        //   {
        //       ans += S[t+1];
        //       t++;
        //   }
        //   ans+='.';
        //   j = i-1;
        //   i--;
        // }
        // ans.pop_back();
        // return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends