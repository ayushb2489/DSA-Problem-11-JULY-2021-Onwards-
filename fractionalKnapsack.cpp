class Solution
{
    public:
    
    static bool compare (pair <double, pair <int, int > > a, pair <double, pair <int, int > > b)
    {
        return a.first > b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector <pair <double, pair <int, int> > > valueByWeight;
        for (int i = 0; i < n; i++)
            valueByWeight.push_back (make_pair ((arr[i].value *1.0 / arr[i].weight), make_pair (arr[i].value, arr[i].weight)));
        sort (valueByWeight.begin(), valueByWeight.end(), compare);
        double sum = 0;
        int weight = 0;
        for (int i = 0; i < n; i++)
        {
            if (weight + valueByWeight[i].second.second <= W)
            {
                weight += valueByWeight[i].second.second;
                sum += valueByWeight[i].second.first;
            }
            else
            {
                sum += valueByWeight[i].first * (W - weight);
                break;
            }
        }   
        return sum;
    }
        
};