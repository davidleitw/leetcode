package golang

func smallerNumbersThanCurrent(nums []int) []int {
	var solve []int
	for _, val1 := range nums {
		count := 0
		for _, val2 := range nums {
			if val1 > val2 {
				count++
			}
		}
		solve = append(solve, count)
	}
	return solve
}

// 4 ms, faster than 96.51% of Go online submissions for How Many Numbers Are Smaller Than the Current Number.
// 3.2 MB, less than 53.51% of Go online submissions for How Many Numbers Are Smaller Than the Current Number.
