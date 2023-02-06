class Solution {
    List<String> answer;

    public List<String> restoreIpAddresses(String s) {
        answer = new ArrayList<>();
        String sequence = "";
        backtrack(s, 0, sequence, 3);
        return answer;
    }

    private void backtrack(String s, int index, String sequence, int remaining) {
        if (remaining == 0) {
            if ((s.length()-index < 4) && isvalidString(s.substring(index))) {
                answer.add(sequence + s.substring(index));
            }
            return;
        }

        for (int i = 1; i <= 3 && index+i <= s.length(); ++i) {
            String sString = s.substring(index, index+i);
            if (isvalidString(sString)) {
                backtrack(s, index+i, sequence + sString + ".", remaining-1);
            }
        }
    }

    private boolean isvalidString(String s) {
        if (s == null || s.length() == 0 || s.length() > 3) {
            return false;
        }

        if (s.charAt(0) == '0' && s.length() > 1) return false;

        if (s.length() <= 2) return true;

        if (Integer.parseInt(s) <= 255) return true;

        return false;
    }
}