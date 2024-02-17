class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int index=1;
        int i=0;
        while(index<n && i<n){
            //check if i'th node is greater than index'th and index+1'th nodes (descendants)
            if(index+1<n && (arr[i]>=arr[index] && arr[i]>=arr[index+1])){
                //we'll increase the index value for next i'th node
                //to point to the correct descendants of i'th node
                i++;
                index+=2;//move to the children of next i
            }else if(index+1==n && arr[i]>=arr[index]){
                //edge case : when there is only a single child present for an i'th node
                //in that case compare i with the single child only
                i++;
                index+=2;
            }else{
                //hence arr can't be converted to a heap 
                //as all the nodes in head are greater than all of its descendants
                return 0;
            }
        }
        return 1;
    }
};