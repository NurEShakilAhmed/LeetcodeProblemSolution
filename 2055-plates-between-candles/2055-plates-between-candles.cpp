class Solution {
public:
    vector<int> platesBetweenCandles(string s,
                                     vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> prefix(n, 0);

        for(int i = 0; i < n; i++) {

            if(s[i] == '*')
                prefix[i] = 1;

            if(i > 0)
                prefix[i] += prefix[i - 1];
        }

        vector<int> leftCandle(n, -1);

        int last = -1;

        for(int i = 0; i < n; i++) {

            if(s[i] == '|')
                last = i;

            leftCandle[i] = last;
        }

        vector<int> rightCandle(n, -1);

        int next = -1;

        for(int i = n - 1; i >= 0; i--) {

            if(s[i] == '|')
                next = i;

            rightCandle[i] = next;
        }

        vector<int> ans;
        for(auto &q : queries) {

            int left = q[0];
            int right = q[1];

            int start = rightCandle[left];
            int end = leftCandle[right];

            if(start == -1 || end == -1 || start >= end) {
                ans.push_back(0);
            }
            else {
                ans.push_back(prefix[end] - prefix[start]);
            }
        }
        return ans;
    }
};