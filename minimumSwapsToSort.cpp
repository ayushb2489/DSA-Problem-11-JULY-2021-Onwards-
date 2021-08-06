int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    vector <pair <int, int> > index(n);
    
    for (int i = 0; i < n; i++)
    {
        index[i].first = arr[i];
        index[i].second = i;
    }
    
    sort (index.begin(), index.end());
    
    int counter = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (index[i].second != i)
        {
            counter++;
            swap (index[i], index[ index[i].second]);
            i--;
        }
    }
    return counter;
    
}