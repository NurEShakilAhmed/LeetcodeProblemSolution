class Solution {
public:

    int expand(string& s, int left, int right) {

        int count = 0;

        while(left >= 0 && right < s.length() &&
              s[left] == s[right]) {

            count++;

            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {

        int answer = 0;

        for(int i = 0; i < s.length(); i++) {
            answer += expand(s, i, i);
            answer += expand(s, i, i + 1);
        }

        return answer;
    }
};