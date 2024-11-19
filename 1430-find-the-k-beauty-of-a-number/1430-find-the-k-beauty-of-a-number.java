class Solution {
    public int divisorSubstrings(int num, int k) {
        String str = String.valueOf(num);
        int count = 0;
        int n = str.length();
        int i = 0;

        while(i + k <= n)
        {
            int divisor = Integer.parseInt(str.substring(i, i + k));

            if(divisor != 0 && num % divisor == 0)
            {
                count++;
            }
            i++;
        }
        return count;

        // String str = String.valueOf(num);
        // int n = str.length();
        // int r=0;
        // int count = 0;
        // while(r+k <= n)
        // {
        //     int val = Integer.parseInt(str.substring(r,r+k));
        //     if(val!=0 && num%val==0)
        //         count++;
        //     r++;
        // }
        // return count;
    }
}