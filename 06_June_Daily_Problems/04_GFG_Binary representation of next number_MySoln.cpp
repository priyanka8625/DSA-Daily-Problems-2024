class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        
        int bit_add = 1;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]=='0'){
                s[i] = '1';
                bit_add = 0;
                break;//no need to update furher bits as bit_add is now 0
            }else{
                //if s[i] is 1 then it should be made 0 and carry must be 1
                s[i] = '0';
            }
        }
        //after string ends check if bit_add is still 1, it needs to be added in result
        if(bit_add == 1)
            s = '1' + s;
        
        //trim leftmost zeros in s
        while(s[0] == '0' && s.length()>1){
            s.erase(s.begin());
        }
        return s;
    }
};