class Solution{
    public:
    bool isPowerofTwo(long long n){
        if (n % 2 == 1)
            return false;
        if (n == 0)
            return false;
        if (n == 1 || n == 2)
            return true;
        return isPowerofTwo (n / 2);
        
    }
};
