class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length(), start=0, end=0, cost=0, maxlength=0;
        while(end < n){
            cost += abs(s[end]-t[end]);
            //decrease window size if cost becomes > maxCost
            while(cost > maxCost && start<=end){
                cost -= abs(s[start]-t[start]);
                start++;
            }
            maxlength = max(maxlength, end-start+1);
            end++;
        }
        return maxlength;
    }
};