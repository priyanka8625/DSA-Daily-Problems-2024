class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n*(n+1)/2;
        int prefixSum=0;
        for(int i=1; i<=n; i++){
            //let's consider i as the pivot element
            prefixSum += i;
            if(prefixSum == (totalSum-prefixSum)+i)
                return i;
        }
        return -1;
    }
};