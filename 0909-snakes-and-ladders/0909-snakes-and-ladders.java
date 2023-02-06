class Cell {
    private int _x;
    private int _y;
    public Cell(int x, int y) {
        _x = x;
        _y = y;
    }

    public int getRow() {
        return _x;
    }

    public int getColumn() {
        return _y;
    }
};

class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        int destination = n*n;
        HashSet<Integer> visited = new HashSet<>();
        Queue<Integer> current = new LinkedList<>();

        Integer[] columns = new Integer[n];
        for (int i = 0; i < n; ++i) {
            columns[i] = i;
        }

        // Map from number of position in matrix
        Cell[] cellsMapper = new Cell[destination + 1];

        int currentPosition = 1;

        for (int row = n-1; row >= 0; --row) {
            for (int column : columns) {
                cellsMapper[currentPosition++] = new Cell(row, column);
            }
            Collections.reverse(Arrays.asList(columns));
        }

        current.add(1);
        visited.add(1);

        int moves = 0;

        while (!current.isEmpty()) {
            int curssize = current.size();

            for (int i = 0; i < curssize; ++i) {
                int currentnum = current.poll();
                if (currentnum == destination) return moves;

                for (int j = 1; j <= 6; ++j) {
                    int k = Math.min(currentnum+j, destination);
                    Cell currentCell = cellsMapper[k];
                    int next = (board[currentCell.getRow()][currentCell.getColumn()] == -1)?k:board[currentCell.getRow()][currentCell.getColumn()];
                    if (!visited.contains(next)) {
                        visited.add(next);
                        current.add(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
}