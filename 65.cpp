//copy others
class Solution {
public:
    bool isNumber(string s) {
        int m = 0;
        for (; isspace(s[m]); m++);
        int n = s.size() - 1;
        for (; isspace(s[n]); n--);
        if (m == s.size()) s = "";
        else s = string(s.begin() + m, s.begin() + n + 1);
        int hasdot = s.find(".",0);
        int hase = s.find_first_of("eE", hasdot == string::npos ? 0 : hasdot);

        if (hasdot != string::npos && hase != string::npos){//有小数点和e
            if (isSignNumber(string(s.begin(), s.begin() + hasdot))){
                return  isNumber(string(s.begin() + hasdot + 1, s.begin() + hase), 1) && isSignNumber(string(s.begin() + hase+1, s.end()));
            }
            else if (isUnsignNumber(string(s.begin() + hasdot + 1, s.begin() + hase))){
                return  isNumber(string(s.begin(), s.begin() + hasdot), 0) && isSignNumber(string(s.begin() + hase + 1, s.end()));
            }
            else return false;
        } 
        else if (hasdot != string::npos && hase == string::npos){//仅仅有小数点的
            if (isSignNumber(string(s.begin(), s.begin() + hasdot))){
                return  isNumber(string(s.begin() + hasdot + 1, s.end()), 1);
            }
            else if (isUnsignNumber(string(s.begin() + hasdot + 1, s.end()))){
                return  isNumber(string(s.begin(), s.begin() + hasdot), 0);
            }
            else return false;
        }
        else if (hasdot == string::npos && hase != string::npos){//仅仅有e的
            return isSignNumber(string(s.begin(), s.begin() + hase)) && isSignNumber(string(s.begin() + hase + 1, s.end()));
        }
        else return isSignNumber(string(s.begin() + hase + 1, s.end()));//没有e的
        
    }
    bool isNumber(string s, int type){
        switch (type)
        {
        case 0:
            if (s == "+" || s == "-" || s == "")  return true;
            return isSignNumber(s);
            break;
        case 1:
            if (s == "")  return true;
            return isUnsignNumber(string(s.begin(), s.end()));
            break;
        default:
            return false;
            break;
        }
    }

    bool isSignNumber(string s){
        if (s.size() == 0) return false;
        if (s[0] == '+' || s[0] == '-') s = string(s.begin() + 1, s.end());
        return isUnsignNumber(s);
    }
    bool isUnsignNumber(string s){
        if (s.size() == 0) return false;
        for (string::size_type i = 0; i < s.size(); ++i){
            if (!isdigit(s[i])) return false;
        }
        return true;
    }
};