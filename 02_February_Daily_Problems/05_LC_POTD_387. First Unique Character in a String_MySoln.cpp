class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        for(auto& ch : s)
            freq[ch]++;
        
        for(int i=0; i<n; i++)
            if(freq[s[i]] == 1)
                return i;
        return -1;
    }
};