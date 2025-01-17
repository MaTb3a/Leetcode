var doesValidArrayExist = function(derived) {
    return derived.reduce((acc, num) => acc + num, 0) % 2 === 0;
};
