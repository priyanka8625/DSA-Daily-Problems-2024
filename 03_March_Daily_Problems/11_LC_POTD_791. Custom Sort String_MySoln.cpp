class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;
        for(char ch : s)
            freq[ch]++;

        string res="";
        //first append only those chars which occur in order
        for(char ch: order){
            if(freq[ch]){
                //append all occurances of ch
                while(freq[ch]){
                    res += ch;
                    freq[ch]--;
                }
            }
        }
        //now append remaining characters
        for(auto& [key, value] : freq){
            while(value--)//append all occurances of that character
                res += key;
        }
        return res;
    }
};