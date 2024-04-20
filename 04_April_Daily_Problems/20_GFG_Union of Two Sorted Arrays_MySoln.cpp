class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        set<int> sortedUnion;
        int i=0, j=0;
        while(i<n){
            sortedUnion.insert(arr1[i]);
            i++;
        }
        while(j<m){
            sortedUnion.insert(arr2[j]);
            j++;
        }
        vector<int> ans(sortedUnion.begin(), sortedUnion.end());
        return ans;
    }
};