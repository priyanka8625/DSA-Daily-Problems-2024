class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long maxBooks = 0, books=0;
        for(int i=0; i<n; i++){
            if(arr[i] <= k){
                books += arr[i];
                maxBooks = (books>maxBooks)? books:maxBooks;
            }else{
                books = 0;
            }
        }
        return maxBooks;
    }
};