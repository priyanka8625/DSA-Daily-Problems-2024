class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> sortedStr(strs.begin(), strs.end());
        vector<vector<string>> result;

        //sort each str present in strs
        for(auto& str: sortedStr)
            sort(str.begin(), str.end());
        
        //now compare each str with next strs for finding the match
        int i=0;
        for(; i<n-1; i++){
            vector<string> group;
            if(sortedStr[i] != "NULL")
                group.push_back(strs[i]);
            else
                continue;

            for(int j=i+1; j<n; j++){
                if(sortedStr[i] == sortedStr[j] && sortedStr[j] != "NULL"){
                    group.push_back(strs[j]);
                    sortedStr[j] = "NULL";//so that next time we'll not insert the string repeatedly
                }
            }
            result.push_back(group);
        }
        //if the last element of sortedStr is not null it means it is not inserted in the result 
        //so insert it after the loop
        if(sortedStr[i] != "NULL")
            result.push_back({strs[i]});
        return result;
    }
};