class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        vector<int> alphabets(26, 0);
        int n = s.length();
        
        //convert string into set so that we'll get only unique alphabets both lower and uppercase
        set<char> uniqueChars(s.begin(), s.end());
        for(auto& ch : uniqueChars){
            if(ch>='A' && ch<='Z')
                alphabets[ch - 'A']++; //increase count of the alphabet
            else if(ch>='a' && ch<='z')
                alphabets[ch - 'a']++; 
        }
        for(int i=0; i<26; i++){
            if(alphabets[i] == 0)
                return 0;
        }
        return 1;
    }
};