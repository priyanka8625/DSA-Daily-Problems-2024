class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mp;
        for(int ele : arr1){
            string num = to_string(ele);
            string prefix="";
            for(int i=0; i<num.length(); i++){
                prefix.push_back(num[i]);
                mp[prefix] = prefix.length();
            }
        }
        int max_length = 0;
        for(int ele : arr2){
            string num = to_string(ele);
            string prefix="";
            for(int i=0; i<num.length(); i++){
                prefix.push_back(num[i]);
                if(mp[prefix]){
                    max_length = max(max_length, mp[prefix]);
                }
            }
        }
        return max_length;
    }
};