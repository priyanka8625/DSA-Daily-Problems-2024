class KthLargest {
    //min heap
    priority_queue<int, vector<int>, greater<int>> heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        //store k largest elements in the nums
        int i=0;
        this->k = k;
        while(i<nums.size()){
            heap.push(nums[i]);
            if(heap.size()>k){
                heap.pop();
            }
            i++;
        }
    }
    
    int add(int val) {
        //add current value only if it is one of the k largest elements
        heap.push(val);
        if(heap.size()>k){
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */