class Solution {
  public:
    void printArr(int n, int arr[]) {
        // Your code for printing array here
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    void setToZero(int n, int arr[]) {
        // Use memset to set arr to zero
        memset(arr, 0, n*sizeof(arr[0]));
        //3 args: 1.start addr, 2.value to be filled, 3.no of bytes to fill
    }

    void xor1ToN(int n, int arr[]) {
        // Xor arr[i]^i
        for(int i=0; i<n; i++)
            arr[i] ^= i;
    }
};