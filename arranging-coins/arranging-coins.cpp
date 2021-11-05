class Solution {
public:
    int arrangeCoins(int n) {
       
        long left = 0;
        long right = n;
        long mid , curr;
        
        while(left <= right)
        {
            mid = left + (right - left)/2;
            curr = mid * (mid + 1)/2;
            
            if(n == curr) return (int)mid;
            else if( n < curr) right = mid - 1;
            else left = mid + 1;
                
        }
        return int(right);
        
        
    }
};