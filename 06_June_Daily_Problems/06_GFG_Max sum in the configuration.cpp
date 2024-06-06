class Solution {
public:
    long long max_sum(int a[], int n) {
        long long res = 0, totalSum = 0, maxi = 0;
        
        for(int i = 0; i < n; i++) {
            totalSum += a[i];
            res += (i * 1ll * a[i]);
        }
        
        maxi = max(maxi, res);
        for(int i = 0; i < n; i++) {
            res = res - (totalSum - a[i]) + (a[i] * 1ll * (n - 1));
            maxi = max(maxi, res);
        }
        
        return maxi;
    }
};