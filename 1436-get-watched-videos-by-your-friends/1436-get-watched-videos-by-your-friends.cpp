class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();

        vector<int> dist(n, -1);
        queue<int> q;
        q.push(id);
        dist[id] = 0;

        vector<int> targetFriends;
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            if(dist[curr] == level){
                targetFriends.push_back(curr);
                continue;
            }
            if(dist[curr] > level) continue;
            for(auto& next : friends[curr]){
                if(dist[next] == -1){
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }

        // 2. 统计视频
        unordered_map<string, int> videoCount;
        for (int friendId : targetFriends) {
            for (const string& video : watchedVideos[friendId]) {
                videoCount[video]++;
            }
        }

        // 3. 排序
        vector<string> ans;
        for (auto& [video, count] : videoCount) {
            ans.push_back(video);
        }

        sort(ans.begin(), ans.end(), [&](const string& a, const string& b) {
            if (videoCount[a] != videoCount[b]) {
                return videoCount[a] < videoCount[b];
            }
            return a < b;
        });
        
        return ans;
    }
};