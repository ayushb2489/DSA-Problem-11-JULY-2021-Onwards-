class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque <int> maxl;
        for (int i = 0; i < k; i++)
        {
            while (!maxl.empty() && maxl.back () < arr[i])
                maxl.pop_back ();
            maxl.push_back (arr[i]);
        }
        int i = 0;
        int j = k - 1;
        vector <int> retVector;
        
        while (true)
        {
            retVector.push_back (maxl.front());
            if (arr[i] == maxl.front())
                maxl.pop_front();
            i++;
            j++;
            if (j == n)
                break;
            while (!maxl.empty() && maxl.back () < arr[j])
                maxl.pop_back ();
            maxl.push_back (arr[j]);
        }
        return retVector;
    }
};