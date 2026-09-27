class Solution {
public:

    string build(string s)
    {
        string st;

        for(char c : s)
        {
            if(c == '#')
            {
                if(!st.empty())
                    st.pop_back();
            }
            else
            {
                st.push_back(c);
            }
        }

        return st;
    }

    bool backspaceCompare(string s, string t)
    {
        return build(s) == build(t);
    }
};