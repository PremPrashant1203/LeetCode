var myAtoi = function(s) {
    let i = 0;
    let sign = 1;
    let num = 0;

    while (s[i] === " ") {
        i++;
    }

    if (s[i] === "+" || s[i] === "-") {
        if (s[i] === "-") {
            sign = -1;
        }
        i++;
    }

    while (i < s.length && s[i] >= "0" && s[i] <= "9") {
        num = num * 10 + (s[i].charCodeAt(0) - 48);

        if (sign * num > 2147483647) {
            return 2147483647;
        }

        if (sign * num < -2147483648) {
            return -2147483648;
        }

        i++;
    }

    return sign * num;
};