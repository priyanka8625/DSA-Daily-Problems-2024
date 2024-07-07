
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int start=0, end=arr.size()-1, mid=0;
        while(start<=end){
            mid = start+(end-start)/2;
            if(arr[mid] == key){
                return mid;
            }
            
            //check if start is <= mid
            if(arr[start]<=arr[mid]){
                //if key is present in the left part
                if(arr[start]<=key && arr[mid]>key){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }else{
                //if key is there in the right part
                if(arr[mid]<key && key<=arr[end]){
                    start = mid+1;
                }else{
                    end = mid -1;
                }
            }
        }
        return -1;
    }
};