class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        int len = n.length();
        vector<int> last(10, -1);
        //store the last occurance of each digit
        for(int i=0; i<len; i++){
            last[n[i]-'0'] = i;
        }

        //check if the maximum value is present first in the string and so on...
        for(int i=0; i<len; i++){
            //if there's a larger num after the current num in orginal string, then this needs to be swapped
            for(int digit=9; digit>n[i]-'0'; digit--){
                if(last[digit] > i){
                    swap(n[i], n[last[digit]]);
                    return stoi(n);
                }
            }
        }
        //if no swap made, then the string is already sorted in desc i.e. max string possible
        return num;
    }
};