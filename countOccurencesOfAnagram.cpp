class Solution{
public:
	int search(string pat, string txt) {
	    vector <int> patv(26, 0);
    	vector <int> txtv(26, 0);
        int m = pat.size();
    	int n = txt.size();
    	int counter = 0;
    	   
    	for (int i = 0; i < m; i++)
    	    patv[pat[i] - 97]++;
    	for (int i = 0; i < m; i++)
    	    txtv[txt[i] - 97]++;
    	int j = m - 1;
        int i = 0;
        
    	while (true)
    	{
    	    if (patv == txtv)
    	        counter++;
    	    txtv[txt[i] - 97]--;
    	    i++;
    	    j++;
    	    if (j == n)
    	        break;
    	    txtv[txt[j] - 97]++;
    	}
    	return counter;
	        
	}

};
