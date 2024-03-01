class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        //an odd number always contains a set bit at 2^0'th position
        //so, we'll add the 1's at the front of the string and the remaining last one will be at the last position
        string res="";
        int ones=0, n=s.length();
        //count no of one's in s 
        for(int i=0; i<n; i++){
            if(s[i]=='1')
                ones++;
        }
        //add ones-1 at the front and remaining zeros to res
        for(int i=0; i<n-1; i++){
            if(ones != 1){//which indicates that will append only total 1's -1 no. of ones at the front of res
                res += '1';
                ones--;
            }else{
                res += '0';
            }
        }
        //add last digit 1 to the end of res which will represent the 2^0'th set bit
        res += '1'; 
        return res;
    }
};