class Solution {
public:
    int scoreOfString(string s) {
        int score=0;
        int i=0, j=1, n=s.length();
        while(j<n){
            score += abs(s[i]-s[j]);
            i++;
            j++;
        }
        return score;
    }
};