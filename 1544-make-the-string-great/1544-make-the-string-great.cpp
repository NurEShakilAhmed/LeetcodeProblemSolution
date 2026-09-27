class Solution {
public:
    string makeGood(string s) {

        string st;

        for(char c : s)
        {
            if(!st.empty() &&
               tolower(st.back()) == tolower(c) &&
               isupper(st.back()) != isupper(c))
            {
                st.pop_back();
            }
            else
            {
                st.push_back(c);
            }
        }

        return st;
    }
};