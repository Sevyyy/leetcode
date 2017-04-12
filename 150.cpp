class Solution {
public:
    int s2i(string s)
    {
        int n = s.size();
        int ans = 0;
        int i = 0;
        if(s[0] == '-')
            i = 1;
        for(;i < n;i++)
        {
            int num = s[i] - '0';
            ans = ans * 10 + num;
        }
        if(s[0] == '-')
            return -ans;
        else
            return ans;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0;i < tokens.size();i++)
        {
            if(tokens[i][0] >= '0' && tokens[i][0] <= '9')
            {
                s.push(s2i(tokens[i]));
            }
            else if(tokens[i][0] == '-' && tokens[i].size() > 1)
            {
                s.push(s2i(tokens[i]));
            }
            else
            {
                switch(tokens[i][0])
                {
                    case '+':
                    {
                        int p2 = s.top();
                        s.pop();
                        int p1 = s.top();
                        s.pop();
                        s.push(p1+p2);
                        break;
                    }
                    case '-':
                    {
                        int p2 = s.top();
                        s.pop();
                        int p1 = s.top();
                        s.pop();
                        s.push(p1-p2);
                        break;
                    }
                    case '*':
                    {
                        int p2 = s.top();
                        s.pop();
                        int p1 = s.top();
                        s.pop();
                        s.push(p1*p2);
                        break;
                    }
                    case '/':
                    {
                        int p2 = s.top();
                        s.pop();
                        int p1 = s.top();
                        s.pop();
                        s.push(p1/p2);
                        break;
                    }
                }
            }
        }
        return s.top();
    }
};