// You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

// Write a function to determine if the starting player can guarantee a win.

// Example:

// Input: s = "++++"
// Output: true 
// Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
// Follow up:
// Derive your algorithm's runtime complexity. -> O(N!)


public boolean canWin(String s) {
        HashMap<String, Boolean> h = new HashMap();
        return canWin(s.toCharArray(), h);
    }
    
    private boolean canWin(char[] c, HashMap<String, Boolean> h) {
        for (int i = 1; i < c.length; i++)
            if (c[i] == '+' && c[i - 1] == '+') {
                c[i] = '-'; c[i - 1] = '-';
                
                boolean t;
                String key = String.valueOf(c);
                if (!h.containsKey(key)) {
                    t = canWin(c, h);
                    h.put(key, t);      //System.out.println(key + " --> " + t);
                } else {
                    t = h.get(key);     //System.out.println(key + " ==> " + t);
                }   // can not directly use if (t) return true here, cuz you need to restore
                
                c[i] = '+'; c[i - 1] = '+';
                if (!t) return true;
            }
        return false;
    }