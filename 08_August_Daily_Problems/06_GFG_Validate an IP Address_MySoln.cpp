class Solution {
  public:
    int isValid(string str) {
        // code here
        int number=0, n=str.length(), numCount=0, dotCount=0;
        int i=0;
        while(i<n){
            if(str[i]=='.'){
                dotCount++;
                i++;
                continue;
            }
            while(i<n && str[i] != '.'){
                number = number*10 + (str[i]-'0');
                i++;
            }
            if(number>=0 && number<=255){
                number=0;
                numCount++;
            }else{
                return false;
            }
        }
        if(numCount==4 && dotCount==3)
            return true;
        return false;
    }
};