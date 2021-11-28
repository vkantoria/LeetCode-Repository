class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        stringstream str(s);
        string word;
        string ans = "";
        while(str>>word)
        { 
            //string t = word;
            word += " ";
            ans = word + ans;
        }
        ans.pop_back();
        return ans;
        
    }
};