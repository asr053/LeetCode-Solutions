/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var getSubarrayBeauty = function(nums, k, x) {
   const n = nums.length;
const curr = new Array(101).fill(0);
for (let i = 0; i < k; i++) {
curr[nums[i] + 50]++;
}
const res = [];
let total = 0;
for (let i = 0; i <= 100; i++) {
if (curr[i] == 0) {
continue;
}
total += curr[i];
if (total >= x) {
if (i >= 50) {
res.push(0);
} else {
res.push(i - 50);
}
break;
}
}
for (let i = k; i < n; i++) {
curr[nums[i - k] + 50]--;
curr[nums[i] + 50]++;
total = 0;
for (let j = 0; j <= 100; j++) {
if (curr[j] == 0) {
continue;
}
total += curr[j];
if (total >= x) {
if (j >= 50) {
res.push(0);
} else {
res.push(j - 50);
}
break;
}
}
}
return res;
}
