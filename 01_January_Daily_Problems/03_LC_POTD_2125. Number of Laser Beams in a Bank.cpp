//2125. Number of Laser Beams in a Bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, n = bank.size();
        int prevRowCount=0, currentRowCount=0;
        for(int i=0; i<n; i++){
            currentRowCount = count(bank[i]);
            if(currentRowCount == 0){
                continue;
            }
            ans += currentRowCount * prevRowCount;
            prevRowCount = currentRowCount;
        }
        return ans;
    }
    int count(string row){
        int cnt=0;
        for(int i=0; i<row.length(); i++){
            if(row[i] == '1')
                cnt++;
        }
        return cnt;
    }
};
