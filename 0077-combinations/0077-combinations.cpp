/////////////
// 1st TRY //
/////////////
// class Solution {
// public:
//     vector<vector<int>> combine(int n, int k) {
//         vector<vector<int>> result;

//         vector<int> path;
//         vector<bool> visited(n , false);

//         vector<int> nums;
//         for(int i = 1 ; i <= n ; i++){
//             nums.push_back(i);
//         }

//         backtrack(result, visited, nums, path, k);
//         return result;
//     }
// private:
//     void backtrack(vector<vector<int>>& result, vector<bool>& visited, const vector<int>& nums, vector<int>& path, int k){
//         if(path.size() == k){
//             result.push_back(path);
//             return;
//         }

//         for(int i = 0 ; i < nums.size() ; i++){
//             if(visited[i]) return;

//             path.push_back(nums[i]);
//             visited[i] = true;
//             backtrack(result, visited, nums, path, k);
//             visited[i] = false;
//             path.pop_back();
//         }
//     }
// };

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
///////////// 
// 2nd TRY //
/////////////
// class Solution{
// public:
//     vector<vector<int>> combine(int n, int k) {
//         vector<vector<int>> result;
//         vector<int> path;
//         backtrack(n, k, 1, path, result);
//         return result;
//     }

// private:
//     void backtrack(int n, int k, int start, vector<int>& path, vector<vector<int>>& result){
//         if(path.size() == k){
//             result.push_back(path);
//             return;
//         }

//         for(int i = start ; i <= n ; i++){
//             path.push_back(i);
//             backtrack(n, k, i + 1, path, result);
//             path.pop_back();
//         }
//     }
// };

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
////////////
// 3rd TRY//
////////////

class Solution{
public:
    // INTEGER n -> size n array [1, n]
    // INTEGER k -> combinations of k
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        // 存储当前路径
        vector<int> path;
        // 因为是求组合, 所以定义布尔数组->
        // 判断元素是否被访问过
        vector<bool> visited(n, false);

        backtrack(result, path, visited, n, k, 1);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int>& path, vector<bool>& visited, int n, int k, int start){
        // 如果当前路径长度等于k, 加进result
        if(path.size() == k){
            result.push_back(path);
            return;
        }

        for(int i = start ; i <= n ; i++){
            // 将元素加入当前路径, 并标记为已经访问(true)
            path.push_back(i);
            visited[i - 1] = true;

            // 按照路径的起始点递归遍历
            backtrack(result, path, visited, n, k, i + 1);

            // 弹出末尾元素, 并标记为未访问过(false)
            path.pop_back();
            visited[i - 1] = false;
        }
    }
};





















