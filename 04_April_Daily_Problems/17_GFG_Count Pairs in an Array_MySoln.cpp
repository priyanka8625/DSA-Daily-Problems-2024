
class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        //apply the algorithm of count inversions on the new array formed by doing index*arr[index]
        for(int i=0; i<n; i++){
            arr[i] *= i;
        }
        int count=0;
        mergesort(arr, 0, n-1, count);
        return count;
    }
    void mergesort(int* &arr, int start, int end, int &count){
        if(start>=end)
            return;
        int mid = start + (end-start)/2;
        mergesort(arr, start, mid, count);
        mergesort(arr, mid+1, end, count);
        merge(arr, start, mid, end, count);
    }
    void merge(int* &arr, int start, int mid, int end, int &count){
        vector<int> temp(end-start+1);
        int index=0, left=start, right=mid+1;
        while(left <= mid && right<=end){
            if(arr[left]<=arr[right]){
                temp[index] = arr[left];
                left++;
                index++;
            }else{
                temp[index] = arr[right];
                count += (mid - left + 1);
                right++;
                index++;
            }
        }
        while(left <= mid){
            temp[index] = arr[left];
            left++;
            index++;
        }
        while(right <=end){
            temp[index] = arr[right];
            right++;
            index++;
        }
        index=0;
        while(start<=end){
            arr[start] = temp[index];
            index++;
            start++;
        }
    }
};