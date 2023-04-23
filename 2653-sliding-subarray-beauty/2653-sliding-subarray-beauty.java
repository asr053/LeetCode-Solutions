class Solution {
    public int[] getSubarrayBeauty(int[] nums, int k, int x) {
        int n = nums.length;
        int[] curr = new int[101];
        for (int i = 0; i < k; i++) {
            curr[nums[i] + 50]++;
        }
        List<Integer> res = new ArrayList<>();
        int total = 0;
        for (int i = 0; i < 101; i++) {
            if (curr[i] == 0) {
                continue;
            }
            total += curr[i];
            if (total >= x) {
                if (i >= 50) {
                    res.add(0);
                } else {
                    res.add(i - 50);
                }
                break;
            }
        }
        for (int i = k; i < n; i++) {
            curr[nums[i - k] + 50]--;
            curr[nums[i] + 50]++;
            total = 0;
            for (int j = 0; j < 101; j++) {
                if (curr[j] == 0) {
                    continue;
                }
                total += curr[j];
                if (total >= x) {
                    if (j >= 50) {
                        res.add(0);
                    } else {
                        res.add(j - 50);
                    }
                    break;
                }
            }
        }
        int[] result = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            result[i] = res.get(i);
        }
        return result;
    }
}