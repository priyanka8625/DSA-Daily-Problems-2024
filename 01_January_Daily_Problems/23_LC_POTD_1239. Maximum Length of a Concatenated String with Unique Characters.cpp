class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLength = 0;
        findMaxLength(arr, "", 0, maxLength);
        return maxLength;
    }
private:
    void findMaxLength(vector<string>& arr, string current, int start, int &maxLength){
        if(maxLength < current.length())
            maxLength = current.length();
        
        //compare the current string with new string starting from start index upto end
        //if the new string is unique concat it and call for next index
        for(int i=start; i<arr.size(); i++){
            //compare current and new string
            if(isValid(current, arr[i])){
                findMaxLength(arr, current + arr[i], i+1, maxLength);
            }
            //if duplicates exist in new string i.e. arr[i], move to next index
        }
    }
    bool isValid(string& current, string& newString){
        unordered_map<char, int> characters;

        for(auto& ch : newString){
            characters[ch]++;
            if(characters[ch]>1)
                return false;
            if(current.find(ch) != string::npos)
                return false;
        }
        return true;
    }
};