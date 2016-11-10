class Solution {
private:
    string num_2 = "abc";
    string num_3 = "def";
    string num_4 = "ghi";
    string num_5 = "jkl";
    string num_6 = "mno";
    string num_7 = "pqrs";
    string num_8 = "tuv";
    string num_9 = "wxyz";
    string num[10] = {"", "", num_2, num_3, num_4, num_5, num_6, num_7, num_8, num_9};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "")
            return ans;
        ans.push_back("");
        int n = digits.size();
        for(int i = 0; i < n; i++)
        {
            int size = ans.size();
            for(int j = 0;j < size; j++)
            {
                string head = ans[0];
                ans.erase(ans.begin());
                for(int k = 0; k < num[digits[i] - '0'].size(); k++)
                {
                    ans.push_back(head + num[digits[i] - '0'][k]);
                }
            }
        }
        return ans;
    }
};