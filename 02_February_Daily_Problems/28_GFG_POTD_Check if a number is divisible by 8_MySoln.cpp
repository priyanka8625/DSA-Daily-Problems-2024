class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        //According to the divisiblity rule of 8, if the last 3 digits of a number are divisible by 8
        //then the number is divisible by 8
        int number=0, n=s.length();
        for(int i=n-3; i<=n-1; i++){
            number = number*10 + (s[i]-'0');
        }
        return (number%8==0)? 1:-1;
    }
};