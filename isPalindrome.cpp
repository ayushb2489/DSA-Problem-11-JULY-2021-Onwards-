class Solution{
public:	
	
	
	int isPlaindrome(string str)
	{
	    int n = str.size();
	    string temp = str;
	    for (int i = 0; i < (n / 2); i++)
	        swap (str[i], str[n - 1 - i]);
	    if (temp == str)
	        return 1;
	    return 0;
	}

};