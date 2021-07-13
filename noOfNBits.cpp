class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter =  0;
        int num = n;
        for(int i = 0; i < 32; i++)
        {
            if( (n >> i) & 1)
                counter++;
        }
        return counter;
    }
};