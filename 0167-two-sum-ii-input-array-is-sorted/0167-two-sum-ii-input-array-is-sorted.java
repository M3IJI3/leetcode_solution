class Solution {
    public int[] twoSum(int[] numbers, int target) {
        // 只能使用常数级别的额外空间
        // Solution 1: O(n^2)
        // for(int i = 0 ; i < numbers.length - 1 ; i++)
        // {
        //     for(int j = i + 1 ; j < numbers.length ; j++)
        //     {
        //         if(numbers[i] + numbers[j] == target)
        //         {
        //             return new int[]{i+1, j+1};
        //         }
        //     }
        // }

        // return null;
        // -------------------------------------------------

        int left = 0;
        int right = numbers.length - 1;

        while(left < right)
        {
            int total = numbers[left] + numbers[right];

            if(total == target)
            {
                return new int[]{left + 1, right + 1};
            }
            else if(total > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return null;
    }
}