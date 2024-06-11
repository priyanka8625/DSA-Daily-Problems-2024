class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        long long total=0;
        vector<pair<int, pair<int, int>>> temp;//to store absolute diff between orders of a and b and their tips
        
        for(int i=0; i<n; i++){
            temp.push_back({abs(arr[i]-brr[i]), {arr[i], brr[i]}});
        }
        
        //sort the array in descending order of difference in tips 
        //to optimally choose the maximum tip at each step
        sort(temp.begin(), temp.end(), [](const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2){
            return p1.first > p2.first;
        });
        
        for(auto &it : temp){
            int aTip = it.second.first;
            int bTip = it.second.second;
            if(x>0 && aTip>=bTip || y<=0){
                total += aTip;
                x--;
            }else{
                total += bTip;
                y--;
            }
        }
        return total;
    }
};