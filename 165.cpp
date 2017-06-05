class Solution {
public:
    vector<int> getVersion(string s){
        vector<int> ret;
        int temp = 0;
        int n = s.size();
        int index = 0;
        while(index < n){
            while(index < n && s[index] != '.'){
                temp = temp*10+s[index]-'0';
                index++;
            }
            ret.push_back(temp);
            temp = 0;
            index++;
        }
        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = getVersion(version1);
        vector<int> v2 = getVersion(version2);
        //return v2[1];
        int i = 0;
        while(i < v1.size() && i < v2.size()){
            if(v1[i] > v2[i]){
                return 1;
            }else if(v1[i] < v2[i]){
                return -1;
            }else{
                i++;
            }
        }
        while(i < v1.size()){
            if(v1[i] != 0){
                return 1;
            }
            i++;
        }
        while(i < v2.size()){
            if(v2[i] != 0){
                return -1;
            }
            i++;
        }
        return 0;
    }
};