class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string s:details){
            if(s[11]>'6' && s[12]>='0'){
                count++;
            }else if(s[11]=='6' && s[12]>='1'){
                count++;
            }
        }
        return count;
    }
};