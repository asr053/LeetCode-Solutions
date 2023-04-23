class Solution(object):
    def getSubarrayBeauty(self, nums, k, x):
        n = len(nums)
        curr = [0] * 101
        for i in range(k):
            curr[nums[i] + 50] += 1
        res = []
        total = 0
        for i in range(101):
            if curr[i] == 0:
                continue
            total += curr[i]
            if total >= x:
                if i >= 50:
                    res.append(0)
                else:
                    res.append(i - 50)
                break
        for i in range(k, n):
            curr[nums[i - k] + 50] -= 1
            curr[nums[i] + 50] += 1
            total = 0
            for j in range(101):
                if curr[j] == 0:
                    continue
                total += curr[j]
                if total >= x:
                    if j >= 50:
                        res.append(0)
                    else:
                        res.append(j - 50)
                    break
        return res
