class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> temp;
        int add = 1;
        while(!digits.empty())
        {
            temp.push_back((digits.back() + add) % 10);
            add = (digits.back() + add) / 10;
            digits.pop_back();
        }
        if(add)
            temp.push_back(1);
        reverse(temp.begin(), temp.end());
        return temp;
    }
};