package golang

func min(n1, n2, n3 int) int {
	if n1 < n2 && n1 < n3 {
		return n1
	} else if n2 < n3 {
		return n2
	} else {
		return n3
	}
}

func countSquares(matrix [][]int) int {
	solution := 0

	for i, _ := range matrix {
		for j, _ := range matrix[i] {
			if matrix[i][j] != 0 && i != 0 && j != 0 {
				matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + matrix[i][j]
			}
			solution += matrix[i][j]
		}
	}

	return solution
}

// Runtime: 64 ms, faster than 94.12% of Go online submissions for Count Square Submatrices with All Ones.
// Memory Usage: 7.1 MB, less than 29.41% of Go online submissions for Count Square Submatrices with All Ones.
