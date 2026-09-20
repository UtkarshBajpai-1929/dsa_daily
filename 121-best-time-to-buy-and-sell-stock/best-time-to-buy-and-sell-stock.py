class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        buy = prices[0]
        ans  = 0
        for price in prices:
            ans = max(ans, price-buy)
            buy = min(buy, price)
        return ans