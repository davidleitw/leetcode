package golang

func minCostClimbingStairs(cost []int) int {
	steps := len(cost)

	if steps == 0 {
		return 0
	}
	if steps == 1 {
		return cost[0]
	}

	for idx := 2; idx < steps; idx++ {
		if cost[idx-1] > cost[idx-2] {
			cost[idx] += cost[idx-2]
		} else {
			cost[idx] += cost[idx-1]
		}
	}

	if cost[steps-1] > cost[steps-2] {
		return cost[steps-2]
	} else {
		return cost[steps-1]
	}
}

// Runtime: 4 ms, faster than 86.46% of Go online submissions for Min Cost Climbing Stairs.
// Memory Usage: 2.9 MB, less than 100.00% of Go online submissions for Min Cost Climbing Stairs.
