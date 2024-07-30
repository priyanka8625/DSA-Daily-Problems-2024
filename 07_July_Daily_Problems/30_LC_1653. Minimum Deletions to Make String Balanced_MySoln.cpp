class Solution {
public:
    int minimumDeletions(string str) {
        int i=0, ans=0;//bCount will store continous occuring b's count
        stack<char> s;
        while(i<str.length()){
            while(!s.empty() && i<str.length() && s.top()=='b' && str[i]=='a'){
                ans++;
                s.pop();
                i++;
            }
            s.push(str[i]);
            i++;
        }
        return ans;
    }
};