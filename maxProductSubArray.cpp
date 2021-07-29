class Solution{
public:
	
	long long getSum (int* arr, int left, int right)
	{
	    long long sum = 1;
	    for (int i = left; i <= right; i++)
	        sum *= arr[i];
	    return sum;
	}
	
	long long maxProduct(int *arr, int n) {
	    long long maxSum = INT_MIN;
	    for (int i = 0; i < n; i++)
	    {
	        for (int j = i; j < n; j++)
	        {
	            long long temp = getSum (arr, i, j);
	            if (temp > maxSum)
	                maxSum = temp;
	        }
	    }
	    return maxSum;
	}
};