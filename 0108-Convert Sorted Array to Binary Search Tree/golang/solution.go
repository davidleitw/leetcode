package golang

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedArrayToBST(nums []int) *TreeNode {
	length := len(nums)
	if length == 0 {
		return nil
	}
	middle := length / 2
	return &TreeNode{
		Val:   nums[middle],
		Left:  sortedArrayToBST(nums[:middle]),
		Right: sortedArrayToBST(nums[middle+1:]),
	}
}

// Runtime: 88 ms, faster than 98.32% of Go online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 247.7 MB, less than 5.33% of Go online submissions for Convert Sorted Array to Binary Search Tree.
