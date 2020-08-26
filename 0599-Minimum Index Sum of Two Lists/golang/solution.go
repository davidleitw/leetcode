package golang

func findRestaurant(list1 []string, list2 []string) []string {
	var solution []string
	min := len(list1) + len(list2)
	hash := make(map[string]int)

	for idx, val := range list1 {
		hash[val] = idx
	}

	for idx, val := range list2 {
		if v, ok := hash[val]; ok {
			if min > v+idx {
				min = v + idx
			}
		}
	}

	for idx, val := range list2 {
		if idx > min {
			break
		}

		if v, ok := hash[val]; ok && min == v+idx {
			solution = append(solution, val)
		}
	}
	return solution
}

// Runtime: 20 ms, faster than 100.00% of Go online submissions for Minimum Index Sum of Two Lists.
// Memory Usage: 6.6 MB, less than 71.19% of Go online submissions for Minimum Index Sum of Two Lists.
