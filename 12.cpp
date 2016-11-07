class Solution {
private:
    string str_1[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string str_2[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string str_3[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string str_4[4] = {"", "M", "MM", "MMM"};
    string *str[4] = {str_1, str_2, str_3, str_4};
public:
    string intToRoman(int num) {
        string ans = "";
        int index = 0;
        while(num)
        {
            ans = str[index][num % 10] + ans;
            num /= 10;
            index ++;
        }
        return ans;
    }
};