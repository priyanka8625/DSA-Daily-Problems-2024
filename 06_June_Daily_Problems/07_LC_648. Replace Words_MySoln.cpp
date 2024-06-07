class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> s(dictionary.begin(), dictionary.end());
        int n=sentence.length(), end=0;
        string word = "", res="";
        while(end<n){
            string word = "";
            while(end<n && sentence[end] != ' '){
                word += sentence[end];
                if(s.count(word)){
                    break;
                }
                end++;
            }
            //append the desired word in res
            res += word + " ";
            //update start and end to point to the start of next word in sentence
            while(end < n && sentence[end] != ' ')
                end++;
            end++;
        }
        //remove extra space appended in the end of res
        res.pop_back(); 
        return res;
    }
};