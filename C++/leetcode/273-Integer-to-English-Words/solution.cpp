class Solution {
public:
    string GetOriginEnglishWith2Digits(int num) {
        string NumberToEnglishBelow10[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string NumberToEnglishFrom10To19[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string NumberToEnglishWith10Times[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if (num < 10) {
            return NumberToEnglishBelow10[num];
        }
        else if (num < 20) {
            return NumberToEnglishFrom10To19[num - 10];
        }
        else {
            int tenDigit = num / 10, singleDigit = num % 10;
            if (!singleDigit) return NumberToEnglishWith10Times[tenDigit - 2];
            else return NumberToEnglishWith10Times[tenDigit - 2] + " " + NumberToEnglishBelow10[singleDigit];
        }
    }
    
    string GetOriginEnglishWith3Digits(int num) {
    	string NumberToEnglishBelow10[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    	string res = "";
    	if (num >= 100) res += NumberToEnglishBelow10[num / 100] + " Hundred";
    	if (num % 100 > 0) res += (num >= 100 ? " " : "") + GetOriginEnglishWith2Digits(num % 100);
    	return res;
    }
    
    string numberToWords(int num) {
        if (!num) return "Zero";
        string res = "";
        int now;
        string tag[] = {"", " Thousand ", " Million ", " Billion "};
	    for (int i = 0; i < 4; ++i) {
	        now = num % 1000;
	        num /= 1000;
	        if (now) res = GetOriginEnglishWith3Digits(now) + tag[i] + res;
    	} 
    	if (res[res.size() - 1] == ' ') {
			res.erase(res.size() - 1, 1);
		}
    	return res;
    }
};
