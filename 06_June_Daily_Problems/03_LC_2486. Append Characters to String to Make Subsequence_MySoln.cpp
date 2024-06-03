class Solution {
public:
    int appendCharacters(string s, string t) {
        int left=0, right=0;
        int n1=s.length(), n2=t.length();
        while(left<n1 && right<n2){
            if(s[left] == t[right]){
                //find nex char in subsequence
                left++;
                right++;
            }else{
                //increase left to check if t's char exists in further parts
                left++;
            }
        }
        //return t.length - right, right represents how many chars are matched in t
        return n2 - right;
    }
};