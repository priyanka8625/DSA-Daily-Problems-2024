class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int midIndex = n/2 - 1;
        int i=0, j=n-1, leftCount=0, rightCount=0;
        while(i<j){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i]=='u' || s[i]=='i'||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i]=='U' || s[i]=='I'){
                leftCount++;
            }
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'o' || s[j]=='u' || s[j]=='i'||
                s[j] == 'A' || s[j] == 'E' || s[j] == 'O' || s[j]=='U' || s[j]=='I'){
                rightCount++;
            }
            i++;
            j--;
        }
        return leftCount == rightCount;
    }
};
