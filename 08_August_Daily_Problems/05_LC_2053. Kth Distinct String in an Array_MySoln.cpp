class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> unique;
        for(string s:arr){
            unique[s]++;
        }
        for(string s:arr){
            if(unique[s]==1){
                if (--k == 0) return s;
            }
        }
        return "";
    }
};