class Solution {
public:
    char findTheDifference(string s, string t) {
        
        unordered_map<char, int> um;
        
        for(auto i:s)
        {
            um[i]++;
        }
        for(auto i:t)
        {
            um[i]--;
        }
        for(auto i:um)
        {
            if(i.second != 0)
                return i.first;

        }
        return 'c';
    }
};