class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 0)
            return 0;
        int candy = 1;
        int sum = 1;
        int last = 0;
        int more = 0;
        for(int i = 1;i < ratings.size();i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                candy++;
                sum += candy;
            }
            else if(ratings[i] == ratings[i-1])
            {
                candy = 1;
                more = 0;
                sum += candy;
                last = i;
            }
            else
            {
                if(candy == 1)
                {
                    if(more > 0)
                    {
                        sum += i-last;
                        more--;
                    }
                    else
                        sum += i-last+1;
                }
                else
                {
                    more = candy - 2;
                    candy = 1;
                    sum += candy;
                    last = i-1;
                }
            }
        }
        return sum;
    }
};