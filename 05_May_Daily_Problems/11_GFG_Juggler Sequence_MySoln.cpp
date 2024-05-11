class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        // code here
        vector<int> ans;
        ans.push_back(n);
        int index=0;
        while(ans[index] != 1){
            //get the current index element i.e. ak
            int ak = ans[index];
            
            //check if it's even or odd
            if(ak%2 == 0){
                //use even formula
                ans.push_back(pow(ak, 0.5));
            }else{
                //use odd formula
                ans.push_back(pow(ak, 1.5));
            }
            
            //make index point to the next ak
            index++;
        }
        return ans;
    }
};