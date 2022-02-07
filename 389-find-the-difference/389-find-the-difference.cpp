class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<int> al(26,0);
        
        for(int i=0;i<s.size();i++)
        {
            al[s[i] - 'a'] += 1; 
        }
        for(int i=0;i<t.size();i++)
        {
            al[t[i] - 'a'] -= 1; 
        }
        for(int i=0;i<26;i++)
        {
            if(al[i] != 0)
                return ('a' + i );
        }
        return 'c';
    }
};