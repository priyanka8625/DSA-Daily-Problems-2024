class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //sort both the vectors
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        //loop through both the vectors 
        int i=0, j=0, count=0;
        while(j<s.size() && i<g.size()){
            if(s[j]>=g[i]){
                count++;
                j++;
                i++;
            }else{
                j++;//move to next size of cookie
            }
        }
        return count;
    }
};
