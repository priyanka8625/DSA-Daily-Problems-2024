class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int count=0;
        for(int i=0; i<arr.size() && count<2; i++){
            if(arr[i]-1==i)
                continue;
            
            swap(arr[i], arr[arr[i]-1]);
            count++;
        }
        if(count == 1)
            return false;
            
        for(int i=1; i<arr.size(); i++){
            if(arr[i]<arr[i-1])
                return false;
        }
        return true;
    }
};