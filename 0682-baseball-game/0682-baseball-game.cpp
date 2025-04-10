class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        int sum = 0;

        for (int i = 0; i < ops.size(); i++) {
            // string -> char

            if (ops[i] == "C") {
                // C: remove the previous element
                ans.pop_back();
            } else if (ops[i] == "D") {
                // D: double the previous element and add into record
                ans.push_back(ans[ans.size() - 1] * 2);
            } else if (ops[i] == "+") {
                // +: record new scroe that is sum of the previous two scores
                ans.push_back(ans[ans.size() - 1] + ans[ans.size() - 2]);
            } else {
                ans.push_back(stoi(ops[i]));
            }
        }

        for (int num : ans) {
            sum += num;
        }

        return sum;
    }
};