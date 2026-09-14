var convert = function(s, numRows) {
    if (numRows === 1 || numRows >= s.length) {
        return s;
    }

    let rows = Array.from({ length: numRows }, () => "");
    let row = 0;
    let direction = 1;

    for (let char of s) {
        rows[row] += char;

        if (row === 0) {
            direction = 1;
        } else if (row === numRows - 1) {
            direction = -1;
        }

        row += direction;
    }

    return rows.join("");
};