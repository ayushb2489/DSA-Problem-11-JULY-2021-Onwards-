

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:

    bool subsetSum (int* arr, int n, int sum, int** dp)
    {
        if (sum == 0)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        if (arr[n - 1] <= sum)
            dp[n][sum] = subsetSum (arr, n - 1, sum - arr[n - 1], dp) || subsetSum (arr, n - 1, sum, dp);
        else
            dp[n][sum] = subsetSum (arr, n - 1, sum, dp);
        return dp[n][sum];
    }
    
    int equalPartition(int N, int arr[])
    {
        int totalSum = 0;
        for (int i = 0; i < N; i++)
            totalSum += arr[i];
        if (totalSum % 2 != 0)
            return 0;
        int targetSum = totalSum / 2;
        int** dp = new int*[N + 1];
        for (int i = 0; i <= N; i++)
        {
            dp[i] = new int[targetSum + 1];
            for (int j = 0; j <= targetSum; j++)
                dp[i][j] = -1;
        }
        return subsetSum (arr, N, targetSum, dp);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  