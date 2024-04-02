class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mappedChars;//this will store the mapping of s with t's chars
        unordered_set<char> mappedTChars;//this will keep tract of the characters mapped in t with s
        //to avoid two characters getting mapped to the same char of t we'll use a set

        //map the characters in s with t 
        int i=0, n=s.length();
        while(i<n){
            if(mappedChars.count(s[i])==0 && mappedTChars.count(t[i])==0){
                //insert this mapping 
                mappedChars[s[i]] = t[i];
                mappedTChars.insert(t[i]);
            }else{
                //if any of the above condition is false which means 
                //1] if s' character is mapped to an element of t then we need to check if it's mapped to the current t[i]
                //2] if t' character is already present in set which means it is already mapped to any other char in s and can't be used again
                
                //if the mapping is not present in map, which means there's a mismatch
                if(mappedChars[s[i]] != t[i])
                    return false;
                //else move on to next character in s
            }
            i++;
        }
        return true;
    }
};