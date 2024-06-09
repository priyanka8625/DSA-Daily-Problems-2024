class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        // code here
        int i=1;
        while(i<n){
            if(!(arr[i]>arr[i-1])){
                swap(arr[i], arr[i-1]);
            }
            if(i+1 == n)
                break;
            if(!(arr[i]>arr[i+1])){
                swap(arr[i], arr[i+1]);
            }
            i+=2;
        }
    }
};