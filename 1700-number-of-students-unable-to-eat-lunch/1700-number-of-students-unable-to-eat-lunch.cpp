class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        queue<int> q;

        for (int student : students) {
            q.push(student);
        }

        int index = 0;
        int rotations = 0;

        while (!q.empty()) {

            int student = q.front();
            q.pop();
            if (student == sandwiches[index]) {

                index++;

                rotations = 0;
            }
            else {

                q.push(student);

                rotations++;
            }

            if (rotations == q.size()) {
                break;
            }
        }
        return q.size();
    }
};