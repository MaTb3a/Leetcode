var maximumInvitations = function(favorite) {
    const n = favorite.length;
    const deg = Array(n).fill(0);
    favorite.forEach(fav => deg[fav]++);

    const q = [];
    const chain = Array(n).fill(1);

    for (let i = 0; i < n; i++) {
        if (deg[i] === 0) q.push(i);
    }

    while (q.length > 0) {
        const x = q.shift();
        const y = favorite[x];
        chain[y] = Math.max(chain[y], chain[x] + 1);
        deg[y]--;
        if (deg[y] === 0) q.push(y);
    }

    let mx = 0, meetings = 0;
    for (let i = 0; i < n; i++) {
        if (deg[i] === 0) continue;
        let cur = i, length = 0;
        while (deg[cur] > 0) {
            length++;
            deg[cur] = 0;
            cur = favorite[cur];
        }
        if (length > 2) {
            mx = Math.max(mx, length);
        } else {
            meetings += chain[i] + chain[favorite[i]];
        }
    }

    return Math.max(mx, meetings);
};
