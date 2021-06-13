class Solution(object):
    def maximumWealth(self, accounts):
        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        richest = 0
        current = 0;
        for customer in accounts:
            for value in customer:
                current += value
            if current > richest:
                richest = current
            current = 0
        return richest
