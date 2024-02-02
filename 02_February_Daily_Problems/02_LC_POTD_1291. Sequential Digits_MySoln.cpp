class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        //create all the sequential digits which start from 1 to 9
        //append the next digits to these 1 to 9 digits untill we reach a no > high
        vector<int> ans;
        int seqDigits = 0;
        for(int i=1; i<=9; i++){
            seqDigits =  0;
            for(int j=i; j<=9; j++){
                seqDigits = seqDigits * 10 + j;
                if(seqDigits >= low && seqDigits<= high){
                    ans.push_back(seqDigits);
                }else if(seqDigits > high){
                    //once you get a no which is greater than high move to next i
                    break;
                }
            }
        }
        //sort the ans vector and return 
        sort(ans.begin(), ans.end());
        return ans;
    }
};