class Solution {
    public int removeElement(int[] nums, int val) {
        int k = 0;

        int i = 0;
        int j = nums.length - 1;

        while(j >= i)
        {
            // System.out.print(Arrays.toString(nums));
            // System.out.println("i = " + i + "," + "j = " + j + ", " + "k = " + k);
            if(nums[i] != val)
            {
                i++;
                k++;
            }
            else
            {
                if(nums[j] != val)
                {
                    k++;

                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    j--;
                    i++;
                }
                else
                {
                    j--;
                }
            }
        }
        return k;
        
    }
}