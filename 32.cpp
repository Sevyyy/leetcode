class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        int start = 0;
        for(int i = 0;i < s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                if(st.empty())
                {
                    start = i+1;
                }
                else
                {
                    st.pop();
                    if(st.empty())
                    {
                        ans = max(ans, i-start+1);
                    }
                    else
                    {
                        ans = max(ans, i-st.top());
                    }
                }
            }
        }
        return ans;
    }
};