class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int mp[26] = {0};
        for(char ch : p){
            mp[ch-'a']++;
        }
        int n=s.length(), start=0, end=0, count=p.length(), minLength=INT_MAX, startIndex=-1;
        string ans="";
        while(end<n){
            if(mp[s[end]-'a']>0){
                //one of p's char found
                count--;
            }
            mp[s[end]-'a']--;
            
            //if you got a valid window
            while(start<=end && count==0){
                mp[s[start]-'a']++;
                if(mp[s[start]-'a']>0){
                    //we regained the p's char again
                    count++;
                }
                if(end-start+1 < minLength){
                    minLength = end-start+1;
                    startIndex = start;
                }
                start++;
            }
            end++;
        }
        return startIndex==-1? "-1" : s.substr(startIndex, minLength);
    }
};