class Solution {
public:
    int reverse(int x) {
        /*if (x > INT_MAX)
            return 0;
        if (x < INT_MIN)
            return 0;*/
        if (x == 0)
            return 0;
        bool cont = true;
        while (cont)
        {
            if (x% 10 == 0)
                x = x / 10;
            else
                cont = false;
        }
        string temp;
        temp = to_string (x);
        if (temp[0] != '-')
        {
            if (temp.size() > 32)
                return 0;
            ::reverse (temp.begin(), temp.end());
        }
        else
        {
            if (temp.size() > 33)
                return 0;
            ::reverse (temp.begin() + 1, temp.end());
        }
        if (stol (temp) > INT_MAX || stol (temp) < INT_MIN)
            return 0;
        else
            return stoi (temp);
    }
};
