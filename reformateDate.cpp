class Solution {
public:
    string reformatDate(string date) {
        map <string, string> months;
        months["Jan"] = "01";
        months["Feb"] = "02";
        months["Mar"] = "03";
        months["Apr"] = "04";
        months["May"] = "05";
        months["Jun"] = "06";
        months["Jul"] = "07";
        months["Aug"] = "08";
        months["Sep"] = "09";
        months["Oct"] = "10";
        months["Nov"] = "11";
        months["Dec"] = "12";
        
        string retString = "";
        retString += date.substr (date.size() - 4, 4);
        retString += '-';
        
        retString += months[date.substr (date.size() - 8, 3)];
        
        retString += '-';
        int counter = 0;
        while (isdigit (date[counter]))
            counter++;
        if (counter == 1)
        {
            retString += '0';
            retString += date[0];
        }
        else
        {
            retString += date[0];
            retString += date[1];
        }
            
        
        return retString;
    }
};