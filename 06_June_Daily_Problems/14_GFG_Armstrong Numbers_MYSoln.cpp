class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int number = 0, temp=n;
        while(temp){
            int digit = temp%10;
            number += pow(digit, 3);
            temp /= 10;
        }
        if(number == n) return "true";
        return "false";
    }
};
