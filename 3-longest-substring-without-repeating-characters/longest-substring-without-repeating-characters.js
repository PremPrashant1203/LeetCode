var lengthOfLongestSubstring = function(s) {
    let left = 0;
    let maxLength = 0;
    let set = new Set();

    for (let right = 0; right < s.length; right++) {

        // Agar character already present hai,
        // left ko aage move karenge
        while (set.has(s[right])) {
            set.delete(s[left]);
            left++;
        }

        set.add(s[right]);
        maxLength = Math.max(maxLength, right - left + 1);
    }

    return maxLength;
};