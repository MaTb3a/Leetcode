var numTilePossibilities = function(tiles) {
    tiles = tiles.split("").sort().join("");
    let vis = new Array(tiles.length).fill(false);
    
    function solve() {
        let ret = 1;
        for (let i = 0; i < tiles.length; i++) {
            if (vis[i] || (i > 0 && tiles[i] === tiles[i - 1] && !vis[i - 1])) continue;
            vis[i] = true;
            ret += solve();
            vis[i] = false;
        }
        return ret;
    }

    return solve() - 1;
};

