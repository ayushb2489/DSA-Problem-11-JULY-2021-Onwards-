class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bits = 0;
        int alt1 = 3, alt2 = 4;
        while (n != 0 && bits < 32)
        {
            if (alt1 == alt2)
                return false;
            if (bits % 2 == 0)
                alt1 = n & 1;
            else
                alt2 = n & 1;
            n = n >> 1;
            bits++;
            if (alt1 == alt2)
                return false;
        }   
        return true;
    }
};