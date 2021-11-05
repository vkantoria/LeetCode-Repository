class Solution {
public:
    
    bool check(long long curr, long long n)
    {
       if(curr<=n)
           return true;
        else
            return false;
    }
    
    int arrangeCoins(int n) {
       long long left = 1;
       long long right = n;
       long long mid, curr, ans;
        
        while(left <= right)
        {
            mid = left + (right - left)/2;
            curr = mid * (mid + 1)/2;
             if(curr == n)
                return mid;
            if(check(curr, n))
                ans = mid;
            if( n<curr) right = mid - 1;
            else left = mid + 1;      
        }
        return int(ans);
        
        
    }
};