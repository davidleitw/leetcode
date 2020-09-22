package golang

func isSubsequence(s string, t string) bool {
	if len(s) == 0 {
		return true
	}
	subIndex := 0
	targetPtr := s[subIndex]

	for _, char := range t {
		if char == rune(targetPtr) {
			subIndex++
			if subIndex == len(s) {
				return true
			}
			targetPtr = s[subIndex]

		}
	}

	return false
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Is Subsequence.
// Memory Usage: 2 MB, less than 39.31% of Go online submissions for Is Subsequence.
