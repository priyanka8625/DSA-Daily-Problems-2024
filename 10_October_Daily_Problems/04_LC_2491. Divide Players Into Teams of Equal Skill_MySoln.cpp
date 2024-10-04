class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size(), half=n/2;
        sort(skill.begin(), skill.end());

        int left=0, right=n-1;
        int prevSum = skill[left] + skill[right];
        long long product=0;
        while(left<right){
            int sum = skill[left] + skill[right];
            if(prevSum != sum)
                return -1;
            product += (skill[left]*skill[right]);
            left++;
            right--;
        }
        return product;
    }
};