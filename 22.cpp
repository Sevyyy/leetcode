class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        ans.clear();
        if(n == 0)
            return ans;
        ans.push_back("(");
        int length = 1;
        while(length < 2*n)
        {
            int size = ans.size();
            for(int i = 0;i < size; i++)
            {
                string head = ans[0];
                ans.erase(ans.begin());
                int left = count(head.begin(), head.end(), '(');
                int right = count(head.begin(), head.end(), ')');
                if(left == right)
                {
                    ans.push_back(head + "(");
                }
                else if(left > right && left < n)
                {
                    ans.push_back(head + "(");
                    ans.push_back(head + ")");
                }
                else
                {
                     ans.push_back(head + ")");
                }
            }
            length ++;
        }
        return ans;
    }
};