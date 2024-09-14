class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> positives, negatives;
        int n = arr.size();
        for(int i:arr){
            if(i >= 0)
                positives.push_back(i);
            else
                negatives.push_back(i);
        }
        int pos=0, neg=0, index=0;
        while(pos<positives.size() && neg<negatives.size()){
            if(index&1){
                arr[index++] = negatives[neg++];
            }else{
                arr[index++] = positives[pos++];
            }
        }
        while(pos<positives.size()){
            arr[index++] = positives[pos++];
        }
        while(neg<negatives.size()){
            arr[index++] = negatives[neg++];
        }
    }
};