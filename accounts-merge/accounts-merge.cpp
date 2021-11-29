class Solution {
public:
    vector<int> parent;
    int findParent(int y) {
        while(parent[y] != y) {
            y = parent[y];
        }
        return parent[y];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        if(accounts.size() == 1) {
            sort(accounts[0].begin()+1, accounts[0].end());
            return accounts;
        }
        //maps every email to the given source id
        unordered_map<string, int> emailmap;
        parent = vector<int>(accounts.size(), -1);
        //maps every account to the given name
        vector<string> namemap(accounts.size(), "");
        int i=0;
        //loop thorugh the accounts and initially map the parent of each account to itself and 
        //map the given name for each account. If an email is already found, then change the parent
        //of the current iterating account to the root parent of the account in which the email was already
        //found. 
        for(auto &x : accounts) {
            namemap[i] = x[0];
            parent[i] = i;
            for(int y=1; y<x.size(); y++) {
                if(emailmap.find(x[y]) != emailmap.end())
                    parent[findParent(i)] = findParent(emailmap[x[y]]);
                else
                    emailmap[x[y]] = i;
            }
            i++;
        }
        unordered_map<int, vector<string>> resmap;
        //loop the formed emailmap and cluster the emails by finding the root parent for each of the map
        for(auto &m : emailmap) {
            int p = findParent(m.second);
            resmap[p].push_back(m.first);
        }
        vector<vector<string>> results;
        //loop the formed cluster, sort it, and insert the name from the name map at the first position 
        for(auto &r : resmap) {
            sort(r.second.begin(), r.second.end());
            r.second.insert(r.second.begin(), namemap[r.first]);
            results.push_back(r.second);
        }
        return results;
    }
};