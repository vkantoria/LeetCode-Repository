class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), dist=0,src,dest;
        unordered_set<string> us;
        queue<int> q;
        
        for(int i=0;i<n;i++)
            us.insert(wordList[i]);
        
        if(us.find(endWord) == us.end())
            return 0;
                               
        if(us.find(beginWord) == us.end())
             wordList.push_back(beginWord);
         vector<int> adj[wordList.size()];
          vector<int> visited(wordList.size(), 0);
                               
        for(int i=0;i<wordList.size();i++)
        {
            string s = wordList[i];
            for(int j=i+1;j<wordList.size();j++)
            {
                int t = 0, count = 0;
                while(t<s.size())
               {
                  if(s[t] != wordList[j][t])
                      count++;
                  t++;  
               }
                if(count == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // int k=0;
        // for(auto i:adj)
        // {
        //     cout<<k<<" ->";
        //     for(auto j : i)
        //     {
        //          cout<<j<<" ";
        //     }
        //     cout<<endl;
        //    k++;
        // }
        for(int i=0;i<wordList.size();i++)
        {
            if(wordList[i] == beginWord)
                src = i;
            if(wordList[i] == endWord)
                dest = i;
        }
        q.push(src);
        visited[src] = 1;
        while(!q.empty())
        { 
           int size = q.size();
            dist++;
            while(size--)
            {
                int num = q.front();
                  q.pop();
                if(num == dest)
                {
                    return dist;
                }
              
                for(auto i:adj[num])
                    {
                       if(!visited[i])
                       {
                          q.push(i);
                          visited[i] = 1;
                       }
                       
                    }        
            }
        }
   return 0;                        
 }
};