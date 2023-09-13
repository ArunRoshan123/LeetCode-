class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(int i = 0;i<s.length();i++)
        {
            char ch = s[i];
            if(ch == '(' or ch == '{' or ch == '[')
            {
                str.push(ch);                
            }
            else{
                if(!str.empty())
                {
                    char top= str.top();
                    if(ch == ')' and top =='('  
                       or ch == ']' and top == '['
                       or ch == '}' and top == '{')
                    {
                        str.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
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