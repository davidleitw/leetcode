package golang

func decompressRLElist(nums []int) []int {
	var solve []int
	var length int = len(nums)
	for idx := 0; idx < length; idx += 2 {
		for t := 0; t < nums[idx]; t++ {
			solve = append(solve, nums[idx+1])
		}
	}
	return solve
}

// 4 ms, faster than 96.31% of Go online submissions for Decompress Run-Length Encoded List.
// 5.9 MB, less than 49.09% of Go online submissions for Decompress Run-Length Encoded List.
