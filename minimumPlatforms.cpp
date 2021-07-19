class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
   {
       
       sort (arr, arr + n);
       sort (dep, dep + n);
       int counter = 0, maxPlatform = 0;
       for (int i = 0, j = 0; i < n && j < n;)
        {
            if (arr[i] <= dep[j])
            {
                counter++;
                i++;
            }
            else
            {
                counter--;
                j++;
            }
            if (counter > maxPlatform)
                maxPlatform = counter;
        }

       return maxPlatform;
    }
};