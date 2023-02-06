class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        ArrayList<int[]> answer = new ArrayList<>();

        int numIntervals = intervals.length;

        int itr = 0;

        for (itr = 0; itr < numIntervals && intervals[itr][1] < newInterval[0]; ++itr) {
            answer.add(intervals[itr]);
        }

        while (itr < numIntervals) {
            if (newInterval[1] < intervals[itr][0]) {
                answer.add(newInterval);
                break;
            } else {
                newInterval[0] = Math.min(newInterval[0], intervals[itr][0]);
                newInterval[1] = Math.max(newInterval[1], intervals[itr][1]);
            }
            ++itr;
        }

        if (itr == numIntervals) answer.add(newInterval);

        while (itr < numIntervals) {
            answer.add(intervals[itr]);
            ++itr;
        }

        int[][] answerArray = new int[answer.size()][];

        for (itr = 0; itr < answer.size(); ++itr) {
            answerArray[itr] = answer.get(itr);
        }
        return answerArray;
    }
}