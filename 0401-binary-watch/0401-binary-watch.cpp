class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn > 8) return {};

        const vector<int> hours = {1, 2, 4, 8};
        const vector<int> mins  = {1, 2, 4, 8, 16, 32};
        vector<string> ans;

        // 枚举小时灯亮的个数
        for(int hCount = 0; hCount <= min(turnedOn, 4) ; hCount++){
            // 分钟灯亮的个数
            int mCount = turnedOn - hCount;
            if(mCount > 6) continue; // 去掉小时灯后, 检查分钟灯的数量的合法性

            // 定义两个动态数组, 存放小时和分钟的所有和的可能性
            vector<int> hourSums;
            vector<int> minSums;
            getSums(hours, hCount, 0, 0, hourSums);
            getSums(mins, mCount, 0, 0, minSums);

            for(int h : hourSums){
                if(h >= 12) continue;
                for(int m : minSums){
                    if(m >= 60) continue;

                    // 拼成 HH::MM 格式
                    string time = to_string(h) + ":";
                    time += (m < 10 ? "0" : "") + to_string(m);
                    ans.push_back(time);
                }
            }
        }
        return ans;
        
    }
private:
    void getSums(const vector<int>& nums, int count, int index, int sum, vector<int>& result){
        // 没有灯亮 -> sum = 0; 
        // 将结果存入对应的动态数组中
        if(count == 0){
            result.push_back(sum);
            return;
        }

        for(int i = index ; i < nums.size() ; i++){
            getSums(nums, count - 1, i + 1, sum + nums[i], result);
        }
    }
};