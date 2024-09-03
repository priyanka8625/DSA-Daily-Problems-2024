class Solution {
public:
    int getLucky(string s, int k) {
        int alpha[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3, 4, 5, 6, 7, 8};
        int ans=0;
        //1st transform
        for(char ch : s){
            ans += alpha[ch-'a'];
        }  
        cout<<ans<<endl;
        k--;
        //2 or more transforms
        while(k--){
            int num = ans;
            ans = 0;
            while(num){
                ans += (num%10);
                num /= 10;
            }
            cout<<ans<<endl;
        }

        return ans;
    }
};