class Solution {
public:
    bool isValid(string s) {
        stack<char> crt;
        //crt.clean();
        int n = s.size();
        for(int i = 0;i < n; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                crt.push(s[i]);
            }
            else if(crt.size())
            {
                if(s[i] == ')')
                {
                    if(crt.top() == '(')
                        crt.pop();
                    else
                        return false;
                }
                else if(s[i] == ']')
                {
                    if(crt.top() == '[')
                        crt.pop();
                    else
                        return false;
                }
                else if(s[i] == '}')
                {
                    if(crt.top() == '{')
                        crt.pop();
                    else
                        return false;
                }
            }
            else
                return false;
        }
        if(crt.size() == 0)
            return true;
        else 
            return false;
    }
};