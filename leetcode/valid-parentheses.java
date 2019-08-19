public boolean isValid(String s) 
{
    HashMap<String, String> parenMap = new HashMap<String, String>();
    parenMap.put("(", ")");
    parenMap.put("{", "}");
    parenMap.put("[", "]");

    Stack<String> tempStack = new Stack<String>(); 

    for(int i = 0 ; i < s.length() ; ++i)
    {
        String curStr = String.valueOf(s.charAt(i));
        // 1. Opening bracket entered.
        if(parenMap.containsKey(curStr))
            // 1-1 put it in the stack for future reference
            tempStack.push(curStr);
        else
            // 2. Closing bracket entered
        {
            // 2-1. If stack is empty, this is not a valid sequence.
            if(tempStack.empty())
                return false;
            // 2-2. Does it pair up with the peek element of the stack?
            // if so, we can eliminate this pair.
            if(parenMap.get(tempStack.peek()).equals(curStr))
                tempStack.pop();
            // 2-3. Else, this is not a valid parentheses sequence.
            else
                return false;
        }
    }
    return tempStack.empty();
}
