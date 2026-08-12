class Solution {
public:
    string longestCommonPrefix(vector<string>& A) {
         string prefix = A[0];

        for (int i = 1; i < A.size(); i++) {
            int j = 0;

            while (j < prefix.size() &&
                   j < A[i].size() &&
                   prefix[j] == A[i][j]) {
                j++;
            }

            prefix = prefix.substr(0, j);

            if (prefix.empty())
                return "";
        }

        return prefix;
    }
};