class Solution {
  public:
    string oddEven(string s) {
        // code here
        int freq[26] = {0}, x=0, y=0;
        //count freq of all chars in s
        for(int i=0; i<s.length(); i++){
            freq[(s[i]-'a')]++;
        }
        for(int i=1; i<=26; i++){
            if(freq[i-1]==0) continue;
            
            if((i%2 == 1) && (freq[i-1]%2 == 1))
                x++;
            else if((i%2 == 0) && (freq[i-1]%2 == 0))
                y++;   
        }
        if((x+y)&1)
            return "ODD";
        return "EVEN";
    }
};