class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }

        String value = String.valueOf(x); // convert interger x to String

        Queue<Character> queue = new LinkedList<>();
        Stack<Character> stack = new Stack<>();

        for(int i = 0 ; i < value.length() ; i++)
        {
            queue.add(value.charAt(i));
            stack.push(value.charAt(i));
        }

        for(int k = 0 ; k < value.length() ; k++)
        {
            if(stack.peek() != queue.peek())
            {
                return false;
            }

            stack.pop();
            queue.poll();
        }

        return true;
    }
}