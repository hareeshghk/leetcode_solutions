impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let mut is_first_column_zero: bool = false;

        let m = matrix.len();
        let n = matrix[0].len();

        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] == 0 {
                    if j == 0 {
                        is_first_column_zero = true;
                    } else {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for i in 1..m {
            if matrix[i][0] == 0 {
                for j in 1..n {
                    matrix[i][j] = 0;
                }
            }
        }

        for i in 1..n {
            if matrix[0][i] == 0 {
                for j in 1..m {
                    matrix[j][i] = 0;
                }
            }
        }

        if matrix[0][0] == 0 {
            for i in 1..n {
                matrix[0][i] = 0;
            }
        }

        if is_first_column_zero {
            for i in 0..m {
                matrix[i][0] = 0;
            }
        }
    }
}