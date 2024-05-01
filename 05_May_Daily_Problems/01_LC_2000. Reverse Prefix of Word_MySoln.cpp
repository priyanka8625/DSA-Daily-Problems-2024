class Solution {
public:
    string reversePrefix(string word, char ch) {
        //let's first find the index where ch occurs in word
        int index=-1, n=word.length();
        for(int i=0; i<n; i++){
            if(word[i] == ch){
                index = i;
                break;
            }
        }
        //now reverse the segment from i=0 to i=index using two pointers
        int left=0, right=index;
        while(left<right){
            swap(word[left], word[right]);
            left++;
            right--;
        }
        return word;
    }
};