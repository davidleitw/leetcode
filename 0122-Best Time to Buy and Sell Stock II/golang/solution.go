package golang

func maxProfit(prices []int) int {
	max_profit := 0
	for idx := 1; idx < len(prices); idx++ {
		if prices[idx] > prices[idx-1] {
			max_profit += prices[idx] - prices[idx-1]
		}
	}
	return max_profit
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 3.2 MB, less than 16.63% of Go online submissions for Best Time to Buy and Sell Stock II.
