class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        //make the corresponding nmber's index negative
        //the number which is already -ve while scanning arr is repeated
        //the number which is remained +ve after scanning is missing i.e. the missing no is the index of that no
        int missing=-1, repeated=-1;
        for(int i=0; i<arr.size(); i++){
            int index = abs(arr[i])-1;
            if(arr[index]<0){
                repeated = index+1;
            }else{
                arr[index] *= -1;
            }
        }
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>0){
                missing = i+1;
                break;
            }
        }
        return {repeated, missing};
    }
};