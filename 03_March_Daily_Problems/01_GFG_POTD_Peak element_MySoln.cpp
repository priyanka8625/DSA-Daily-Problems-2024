// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       if(n==1)
        return 0;
        
       //let's apply binary search to find the peak element i.e. an element which should >= both of it's adjacent eles
       int left = 0, right = n-1, mid=0;
       while(left<right){
           mid = left + (right-left)/2;
           if(arr[mid]>=arr[mid+1])
                right = mid;
            else
                left = mid + 1;
       }
       return left;
    }
};