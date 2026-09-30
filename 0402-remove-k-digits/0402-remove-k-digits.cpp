class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string st;
        
        for(char c : num) {
            
            while(k > 0 && !st.empty() && st.back() > c) {
                st.pop_back();
                k--;
            }
            
            st.push_back(c);
        }
        
        while(k > 0) {
            st.pop_back();
            k--;
        }
        
        int i = 0;
        while(i < st.size() && st[i] == '0') {
            i++;
        }
        
        string ans = st.substr(i);
        
        if(ans.empty())
            return "0";
        
        return ans;
    }
};