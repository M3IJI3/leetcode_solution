class Solution {
    public int[] plusOne(int[] digits) {
        int tail = digits.length - 1;

        int[] newDigits = new int[digits.length + 1];
        newDigits[0] = 1;

        for (int digit : digits) {
            if (digit != 9) {
                break;
            }
        }

        for(int i = tail ; i > -1 ; i--)
        {
            digits[i] += 1;

            if(digits[i] == 10)
            {
                digits[i] = 0;
            }
            else
            {
                return digits;
            }
        }

        return newDigits;
    }
}