class Solution {
public:
    int minimumLength(string s) {
        if(s.length()==1)
            return 1;

        int n=s.length(), left=0, right=n-1;
        
        char prevChar = '0';//prevChar will store the character that has been matched at both the first and last indices
        while(left<right){
            if(s[left] == s[right]){
                //move both pointers to next characters to compare
                //next time if left and right are not equal but any one of them is 
                //equal to the previous character then it is allowed as per the algorithm given
                prevChar = s[left];
                left++;
                right--;
                n-=2;//reduce the size of string
            }
            else if(prevChar == s[left]){
                //then we'll consider this into the prefix word and reduce the size of the string
                left++;
                n--;
            }
            else if(prevChar == s[right]){
                //we'll add this char to suffix part and reduce the size of the string
                n--;
                right--;
            }
            else{
                //none of the above condns are satisfied then break the loop and return size of the string
                break;
            }
        }
        if(left == right && prevChar==s[left])
        //this is to check the edge case of abbba where ab is the common part so our code gives o/p=1
        //but expected o/p is 0 as we can add this middle b into prefix or suffix
        //this condn will hold true when left and right are pointing to the same char
            n-=1;

        return n;
    }
};