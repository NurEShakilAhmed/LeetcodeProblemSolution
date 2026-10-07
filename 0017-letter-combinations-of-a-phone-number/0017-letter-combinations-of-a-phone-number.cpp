
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> phone = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string current = "";

        backtrack(digits, 0, current, ans, phone);

        return ans;
    }

    void backtrack(string& digits, int index,
                   string& current,
                   vector<string>& ans,
                   vector<string>& phone) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = phone[digits[index] - '0'];

        for (char c : letters) {
            current.push_back(c);

            backtrack(digits, index + 1, current, ans, phone);

            current.pop_back();
        }
    }
};
