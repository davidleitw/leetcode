package golang

func min(x, y byte) byte {
	if x > y {
		return y
	}
	return x
}

func maximalSquare(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}

	var sum int = 0
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			matrix[i][j] -= '0'
			if i != 0 && j != 0 && matrix[i][j] == 1 {
				matrix[i][j] = min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]) + matrix[i][j]
			}

			if sum < int(matrix[i][j]) {
				sum = int(matrix[i][j])
			}
		}
	}
	return sum * sum
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Maximal Square.
// Memory Usage: 3.4 MB, less than 94.48% of Go online submissions for Maximal Square.
