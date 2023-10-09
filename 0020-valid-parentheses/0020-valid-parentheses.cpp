class Solution {
public:
    bool isValid(string s) {
        stack<char>str;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(' or s[i] == '[' or s[i] == '{')
            {
                str.push(s[i]);
            }
            else{
                if(!str.empty())
                {
                    if((s[i] == ')' && str.top() == '(') or (s[i] == '}' && 
                    str.top() == '{') or (s[i] == ']' && str.top() == '[') )
                    {
                        str.pop();
                    }
                    else{
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
    if(str.empty())
        return true;
    else
        return false;
    }
};