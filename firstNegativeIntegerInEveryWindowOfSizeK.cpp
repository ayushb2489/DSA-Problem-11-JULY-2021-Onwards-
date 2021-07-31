vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
        queue <long long int> q;
        for (long long int j = 0; j < k; j++)
            if (arr[j] < 0)
                q.push (arr[j]);
        long long int i = 0;
        long long int j = k - 1;
        vector <long long> retVector;
        while (true)
        {
            if (q.empty())
                retVector.push_back (0);
            else
                retVector.push_back (q.front());
            if (arr[i] == q.front())
                q.pop();
            i++;
            j++;
            if (j == n)
                break;
            if (arr[j] < 0)
                q.push (arr[j]);
        }
        return retVector;
 }