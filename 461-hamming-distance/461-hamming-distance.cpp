class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int Xor = x^y;
        int count = 0;
        
        while(Xor!=0)
        {
           Xor = Xor&(Xor-1);
            count++;
            
        }
        return count;
        
    }
};