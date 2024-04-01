class Solution {
public:
    int lengthOfLastWord(string s) {
        int index=s.length()-1, length=0;
        while(index >=0 && s[index] == ' ')
            index--;
        while(index>=0 && s[index] != ' '){
            index--;
            length++;
        }
        return length;
    }
};