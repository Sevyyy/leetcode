class Solution {
public:
    int binSearch(vector<int> & v, int target, int begin){
        int end = v.size()-1;
        while(begin <= end){
            int mid = (begin+end)/2;
            if(v[mid] == target){
                return mid;
            }
            else if(v[mid] > target){
                end = mid-1;
            }
            else{
                begin = mid+1;
            }
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0;i < n-1;i++){
            int temp = binSearch(numbers, target-numbers[i], i+1);
            if(temp != -1){
                return vector<int>({i+1,temp+1});
            }
        }
    }
};