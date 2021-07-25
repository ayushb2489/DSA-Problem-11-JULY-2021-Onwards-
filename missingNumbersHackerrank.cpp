vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    map <int, int> freq;
    int m = brr.size();
    int n = arr.size();
    for (int i = 0; i < m; i++)
        freq[brr[i]]++;
    for (int i = 0; i < n; i++)
        freq[arr[i]]--;
    vector <int> retVector;
    for (auto i : freq)
        if (i.second > 0)
            retVector.push_back (i.first);
    return retVector;
}