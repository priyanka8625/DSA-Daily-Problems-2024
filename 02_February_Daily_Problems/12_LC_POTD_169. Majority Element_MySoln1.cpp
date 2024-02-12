class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //optimised approach:
        // when a number is guaranteed to be occured more than n/2 times, it means that
        // the number exist atleast one times more than all the other elements 
        // suppose at worst case, 
        // n=5, nums=[3, 2, 3, 2,3], majority element 3 occurs 1 times more than other elements
        // so, let's keep a count variable which will be increased when -
        // 1. same element occurs twice in a loop (adjacently), 
        // 2. otherwise decrease the count, 
        // 3. if count is 0 then make it 1 and update mojorElement variable. cuz now new ele is being counted
        // repeat this process unless you traverse all the elements 
        // at the end of the loop majorElement will contain the majorityElement that is required
        // for example:
        // nums=[2, 2, 1, 1, 1, 2, 2]
        // majorEle = 0, count=0;
        // for i=0:
        // count = 1, majorEle = 2
        // for i=1
        // count =2, majorEle = 2
        // for i=2
        // count = 1, majorEle = 2
        // for i =3
        // count = 2, majorEle = 2
        // for i=4
        // count = 3, majorEle = 2
        // for i = 6
        // count = 2, majorEle = 2
        // for i=7, 
        // count = 3, majorEle = 2
        int majorElement=0, count=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(count == 0){
                count++;
                majorElement = nums[i];
            }else{
                if(majorElement == nums[i])
                    count++;
                else
                    count--;
            }
        } 
        return majorElement;
    }
};