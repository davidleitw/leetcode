package main

import "fmt"

func nextGreaterElement(nums1 []int, nums2 []int) []int {
	var stack []int
	tmp := make(map[int]int)

	for idx, val := range nums2 {
		// while(!stack.empty() && val > stack.top() element)
		for len(stack) != 0 && val > nums2[stack[len(stack)-1]] {
			topIndex := len(stack) - 1
			tmp[nums2[stack[topIndex]]] = val
			stack = stack[:len(stack)-1] // pop
		}
		stack = append(stack, idx) // push
	}

	solution := make([]int, len(nums1))

	for idx, val := range nums1 {
		if v, ok := tmp[val]; ok {
			solution[idx] = v
		} else {
			solution[idx] = -1
		}
	}

	return solution
}

func main() {
	s := nextGreaterElement([]int{4, 1, 2}, []int{1, 3, 4, 2})
	fmt.Println(s)
}
