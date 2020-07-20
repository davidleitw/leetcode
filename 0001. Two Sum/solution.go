package solution

func twoSum(nums []int, target int) []int {
	hash := make(map[int]int)
	for i, val := range nums {
		if v, ok := hash[target-val]; ok {
			return []int{i, v}
		}
		// val對應索引值
		hash[val] = i
	}
	return nil
}

// 4 ms, faster than 94.09% of Go online submissions for Two Sum.
// 3.8 MB, less than 49.61% of Go online submissions for Two Sum.
