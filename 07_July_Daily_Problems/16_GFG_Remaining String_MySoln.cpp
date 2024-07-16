class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        int index=-1, num=0;
        string ans="";
        int i=0; 
        while(i<s.length()){
            if(s[i]==ch){
                num++;
                if(num==count){
                    index = i;
                    break;
                }
            }
            i++;
        }
        if(index == -1){
            return "";
        }
        //point to the next char after count'th ch
        index++;
        while(index<s.length()){
            ans.push_back(s[index]);
            index++;
        }
        
        return ans;
    }
};