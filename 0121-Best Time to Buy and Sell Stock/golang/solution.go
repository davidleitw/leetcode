package golang

import "math"

func maxProfit(prices []int) int {
	max_price := 0
	min_price := math.MaxInt32
	for _, val := range prices {
		if val > min_price {
			if val-min_price > max_price {
				max_price = val - min_price
			}
		} else {
			min_price = val
		}
	}
	return max_price
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 3.1 MB, less than 100.00% of Go online submissions for Best Time to Buy and Sell Stock.
