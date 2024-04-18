
class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        vector<int> ans;
        for(int i=0; i<n+2 && ans.size()<2; i++){
            //mark each number between 1 to n, by considering that arr[i] is actually present at index arr[i]-1
            //before marking check if the element at that index is already marked visited
            //by taking the abs of current index value - 1 and then checking at the epected index
            //take abs of current index to avoid getting index out of bound, becuase element may be already been marked while traversal
            if(arr[abs(arr[i])-1] < 0){
                //if the element has already been visited
                ans.push_back(abs(arr[i]));
                continue;
            }
            arr[abs(arr[i])-1] *= -1;//mark the element negative which represents visited element
        }
        return ans;
    }
};