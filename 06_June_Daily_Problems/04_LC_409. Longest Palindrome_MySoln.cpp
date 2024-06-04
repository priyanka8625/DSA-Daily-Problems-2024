class Solution {
public:
    int longestPalindrome(string s) {
        //let's take a set and follow steps: 
        //1. add the char into s if it's not already present
        //2. if char is already there, then we found a pair of same char 
        //  -> increase palindrome length by 2
        //  -> remove the character from s 
        //3. after traversing all chars of s, if there are any elements present in s 
        //  -> it means these chars are of odd length, and we can place one of them at the middle
        //  -> increase the palindrome length by 1

        int palindrome_length = 0;
        unordered_set<char> st;
        for(int i=0; i<s.length(); i++){
            if(st.count(s[i])){
                st.erase(s[i]);
                palindrome_length += 2;
            }else{
                st.insert(s[i]);
            }
        } 
        if(st.size())
            return palindrome_length+1;
        return palindrome_length;
    }
};