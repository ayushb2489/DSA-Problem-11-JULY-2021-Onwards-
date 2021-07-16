
class Solution{
    public:
    int countBitsFlip(int a, int b){
        
        int arr1[32], arr2[32];
        int itr = 0;
        while (itr < 32)
        {
            arr1[itr] = (a >> itr) & 1;
            itr++;
        }
        itr = 0;
        while (itr < 32)
        {
            arr2[itr] = (b >> itr) & 1;
            itr++;
        }
        int counter = 0;
        for (int i = 0; i < 32; i++)
            if (arr1[i] != arr2[i])
                counter++;
        return counter;
    }
};

