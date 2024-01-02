class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int ksum = 0;
        for(int i=0; i<k ; i++){
            //get the sum of first k elements
            ksum += a[i];
        }
        
        long long int maxsum = ksum, sum = ksum;
        
        //now compare get the sum of next k elements 
        for(int i=k; i<n; i++){
            //find ksum of next k elements
            ksum = ksum + a[i] - a[i-k]; //add current element and subtract the 1st element of previous subarray sum
            
            //now compare it with sum+a[i] i.e. when a[i-k] is included in subarray sum
            //and when i-k not included in subarray sum which is stored in ksum
            sum = max(sum + a[i], ksum);
            
            //now compare the maxsum variable which stores the maximum sum of subarray till now
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};
