var clearDigits = function(s) {
    let stack = [];
    for (let ch of s) {
        if (!isNaN(ch) && stack.length > 0) {
            stack.pop();
        } else {
            stack.push(ch);
        }
    }
    return stack.join('');
};
