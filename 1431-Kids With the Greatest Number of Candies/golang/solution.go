package golang

func kidsWithCandies(candies []int, extraCandies int) []bool {
	solve := make([]bool, len(candies))
	var maxCandies int = 0
	for _, candy := range candies {
		if maxCandies < candy {
			maxCandies = candy
		}
	}

	for idx, candy := range candies {
		if (candy + extraCandies) < maxCandies {
			solve[idx] = false
		} else {
			solve[idx] = true
		}
	}
	return solve
}

// 0 ms, faster than 100.00% of Go online submissions for Kids With the Greatest Number of Candies.
// 2.3 MB, less than 80.00% of Go online submissions for Kids With the Greatest Number of Candies.
