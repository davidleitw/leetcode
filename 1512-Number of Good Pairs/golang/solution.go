package golang

func numIdenticalPairs(nums []int) int {
	var solve int = 0
	hash := make(map[int]int)
	for _, val := range nums {
		if _, ok := hash[val]; !ok {
			hash[val] = 0
		} else {
			hash[val]++
			solve += hash[val]
		}
	}
	return solve
}

// 0 ms, faster than 100.00% of Go online submissions for Number of Good Pairs.
// 2 MB, less than 100.00% of Go online submissions for Number of Good Pairs.
