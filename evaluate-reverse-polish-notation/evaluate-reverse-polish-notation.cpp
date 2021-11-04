class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            if(tokens[i] == "+")
            {
                int t = s.top();
                s.pop();
                int v = s.top()+t;
                s.pop();
                s.push(v);
                  continue;
            }
            if(tokens[i] == "-")
            {
                int t = s.top();
                s.pop();
                int v = s.top() - t;
                s.pop();
                s.push(v);
                  continue;
            }
            if(tokens[i] == "*")
            {
                int t = s.top();
                s.pop();
                int v = s.top() * t;
                s.pop();
                s.push(v);
                continue;
            }
            if(tokens[i] == "/")
            {
                int t = s.top();
                s.pop();
                int v = s.top() / t;
                s.pop();
                s.push(v);
                  continue;
            }
               s.push(stoi(tokens[i]));     
        }
        return s.top();  
    }
};