class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int num = 0;
        for(int i=0;i<32;i++)
        {
           num<<=1;
           num = num|n&1;
           n>>=1;
        }
        return num;
    }
};