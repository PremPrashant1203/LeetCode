var reverse = function(x) {
    let sign = x < 0 ? -1 : 1;
    let num = Math.abs(x);
    let reversed = 0;

    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num = Math.floor(num / 10);
    }

    reversed *= sign;

    if (reversed < -2147483648 || reversed > 2147483647) {
        return 0;
    }

    return reversed;
};