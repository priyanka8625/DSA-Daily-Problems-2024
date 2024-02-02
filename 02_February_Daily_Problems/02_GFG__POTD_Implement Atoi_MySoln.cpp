class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int i=0, n=s.length(), ans=0;
        if(s[0] == '-')
        //means it can be a negative number
            i = 1; //so we'll start the conversion from 1st index
        
        for(; i<n; i++){
            if(s[i] >= '0' && s[i] <= '9')
                ans = ans*10 + (s[i]-'0');//append the current digit to previous digits of s
            else
                return -1; //means it's an alpha character other 0-9
        }
        
        if(s[0] == '-')
            return ans * -1;
        return ans;
    }
};