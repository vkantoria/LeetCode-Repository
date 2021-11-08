class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> ans(max(m,n)+1, 0);
        int sum = 0, c = 0;
        string s = "";
        int i= m-1, j = n-1, k = max(m,n);
       while(i>=0 || j>=0)
        {
            sum = (i>=0?(a[i]-'0'):0) ^ (j>=0?(b[j]-'0'):0) ^ c;
            //cout<<sum<<" ";
            c = (i>=0?(a[i]-'0'):0) & (j>=0?(b[j]-'0'):0) | (i>=0?(a[i]-'0'):0) & c | (j>=0?(b[j]-'0'):0) & c;
           ans[k] = sum;
           i--;
           j--;
           k--;
        }
        if(c==0)
            ans[0] = 0;
        else
            ans[0] = 1;
        int t = 0;
        if(ans[0] == 0)
            t++;
        for(auto i:ans)
         cout<<i;
        for(int i=t;i<ans.size();i++)
        {
           s += ans[i] +  '0'; 
        }
        return s;
    }
};