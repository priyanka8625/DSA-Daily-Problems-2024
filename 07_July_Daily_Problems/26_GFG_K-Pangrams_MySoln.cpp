class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int alpha[26]= {0};
        int spaces=0;
        for(char ch:str){
            if(ch!=' '){
                alpha[ch-'a']++;
            }
        }
        int existingChars=0, canSwapChars=0;//represents the count of chars in str that we can swap
        for(int i=0; i<26; i++){
            if(alpha[i]>=1){
                existingChars++;
                canSwapChars += alpha[i]-1;//-1 cuz one freq is of the original char and other freqs can be swapped with any other chars
            }
        }
        if(existingChars<26){
            int expected = 26-existingChars;
            if(expected>canSwapChars || expected>k){
                return false;
            }
        }
        return true;
    }
};
