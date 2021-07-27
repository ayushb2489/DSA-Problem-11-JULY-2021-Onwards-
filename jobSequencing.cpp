class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool compare (Job a, Job b)
    {
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int counter = 0;
        sort (arr, arr + n, compare);
      /*  for (int i = 0; i < n; i++)
            cout << arr[i].id << " " << arr[i].dead << " " << arr[i].profit << "\n";
        cout << "\n";
        cout << "\n";*/
        vector <int> retArray(n);
        for (int i = 0; i < n; i++)
        {
            if (retArray[((arr[i].dead > n)? n : arr[i].dead) - 1] == 0)
            {
                retArray[((arr[i].dead > n)? n : arr[i].dead) - 1] = arr[i].profit;
                counter++;
            }
            else
            {
                bool flag = true;
                for (int j = (arr[i].dead > n ? n : arr[i].dead) - 2; j >= 0 && flag; j--)
                {
                    if (retArray[j] == 0)
                    {
                        retArray[j] = arr[i].profit;
                        flag = false;
                        counter++;
                    }
                }
            }
        }
        int sum;
        sum = accumulate (retArray.begin(), retArray.end(), 0);
        vector <int> retVector;
        retVector.push_back (counter);
        retVector.push_back (sum);
        return retVector;
    }   
};
