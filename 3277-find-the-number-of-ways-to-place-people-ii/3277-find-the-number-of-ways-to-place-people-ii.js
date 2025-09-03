var numberOfPairs = function(points) {
    points.sort((a, b) => {
        if (a[0] === b[0]) return b[1] - a[1];
        return a[0] - b[0];
    });

    let n = points.length, result = 0;
    for (let i = 0; i < n; i++) {
        let top = points[i][1];
        let bot = -Infinity;
        for (let j = i + 1; j < n; j++) {
            let y = points[j][1];
            if (bot < y && y <= top) {
                result++;
                bot = y;
                if (bot === top) break;
            }
        }
    }
    return result;
};
