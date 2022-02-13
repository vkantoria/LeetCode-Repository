class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0 || right == 0)
            return 0;
        int ll = log2(left) + 1; int lr = log2(right) + 1;
        if(ll != lr)
            return 0;
        unsigned int num = left;
        for(unsigned int i = left;i<=right;i++)
        {
            left = left & i;
        }
        return left;
    }
};