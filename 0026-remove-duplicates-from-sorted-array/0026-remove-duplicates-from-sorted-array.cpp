class Solution {
public:
    int removeDuplicates(vector<int>& A) {
         int j = 1;

        for (int i = 1; i < A.size(); i++) {
            if (A[i] != A[i - 1]) {
                A[j] = A[i];
                j++;
            }
        }

        return j;
    }
};