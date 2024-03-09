class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        while(r--){
            string res="";
            //process upto n only
            for(int i=0; i<=n; i++){
                if(s[i] == '1')
                    res += "10";
                else
                    res += "01";
            }
            //we'll get new string in res
            //copy it into s, so that next time we get a new string in res again
            s = res;
        }
        return s[n];
    }
};