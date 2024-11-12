class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int start = 0; // 可能的起点
        int totalGas = 0; // 总净油量
        int currentGas = 0; // 当前段的净油量

        for (int i = 0; i < gas.length; i++) {
            int fuelGain = gas[i] - cost[i]; // 第 i 个加油站的净油量
            totalGas += fuelGain;
            currentGas += fuelGain;

            if (currentGas < 0) {
                // 无法从当前 start 到达 i
                currentGas = 0;
                start = i + 1; // 更新起点到 i+1
            }
        }
        return totalGas < 0 ? -1 : start; // 如果总净油量 >= 0，返回起点；否则返回 -1
    }   
}