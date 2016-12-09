class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        while(!words.empty())
        {
            int temp_length = 0;
            vector<string> temp;
            while(!words.empty() && temp_length + words[0].size() <= maxWidth)
            {
                if(words[0] != "")
                {
                    temp.push_back(words[0]);
                    temp_length += words[0].size() + 1;
                }
                words.erase(words.begin());
            }
            if(words.empty())
            {
                string line;
                if(temp.empty())
                    line = "";
                else
                    line = temp[0];
                for(int i = 1;i < temp.size();i++)
                {
                    line += " ";
                    line += temp[i];
                }
                while(line.size() < maxWidth)
                {
                    line += " ";
                }
                ans.push_back(line);
                break;
            }
            if(temp.size() == 1)
            {
                while(temp[0].size() < maxWidth)
                {
                    temp[0] += " ";
                }
                ans.push_back(temp[0]);
            }
            else
            {
                int true_length = 0;
                for(int i = 0;i < temp.size();i++)
                {
                    true_length += temp[i].size();
                }
                int space_low = (maxWidth-true_length) / (temp.size()-1);
                int space_high = (maxWidth-true_length) % (temp.size()-1);
                string line = "";
                string low = "";
                string high = "";
                for(int i = 0;i < space_low;i++)
                {
                    low += " ";
                }
                for(int i = 0;i < space_low+1;i++)
                {
                    high += " ";
                }
                for(int i = 0;i < temp.size()-1;i++)
                {
                    line += temp[i];
                    if(i < space_high)
                    {
                        line += high;
                    }
                    else
                    {
                        line += low;
                    }
                }
                line += temp.back();
                ans.push_back(line);
            }
        }
        return ans;
    }
};