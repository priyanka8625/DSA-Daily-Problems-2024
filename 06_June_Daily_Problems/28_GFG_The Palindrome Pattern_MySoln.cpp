class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        //1. check for row palindromes
        for(int i=0; i<n; i++){
            int start=0, end=n-1;
            bool flag = true;
            while(start<end){
                if(arr[i][start] != arr[i][end]){
                    flag = false;
                    break;
                }
                start++;
                end--;
            }
            if(flag){
                return to_string(i) + " R";
            }
        }
        //2. check for clumn palindromes
        for(int i=0; i<n; i++){
            int start=0, end=n-1;
            bool flag = true;
            while(start<end){
                if(arr[start][i] != arr[end][i]){
                    flag = false;
                    break;
                }
                start++;
                end--;
            }
            if(flag){
                return  to_string(i) + " C";
            }
        }
        //3. if arrived upto here, it means no palindrome found
        return "-1";
    }
};