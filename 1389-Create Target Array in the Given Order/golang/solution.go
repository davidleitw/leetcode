package main

import "fmt"

func createTargetArray(nums []int, index []int) []int {
	length := len(nums)
	solve := make([]int, length)

	for i := 0; i < length; i++ {
		if i == index[i] {
			solve[i] = nums[i]
		} else {
			for j := i; j > index[i]; j-- {
				solve[j] = solve[j-1]
			}
			solve[index[i]] = nums[i]
		}
	}
	return solve
}

func main() {
	solve := createTargetArray([]int{0, 1, 2, 3, 4}, []int{0, 1, 2, 2, 1})
	fmt.Println("solve = ", solve)
}

// 0 ms, faster than 100.00% of Go online submissions for Create Target Array in the Given Order.
// 2.1 MB, less than 78.26% of Go online submissions for Create Target Array in the Given Order.
