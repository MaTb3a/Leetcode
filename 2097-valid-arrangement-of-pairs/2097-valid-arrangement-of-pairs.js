var validArrangement = function(pairs) {
    const adj = new Map();
    const inDegree = new Map();
    const outDegree = new Map();
    const path = [];

    const euler = (u) => {
        const stack = [u];
        while (stack.length > 0) {
            const node = stack[stack.length - 1];
            if (!adj.has(node) || adj.get(node).length === 0) {
                path.push(stack.pop());
            } else {
                const child = adj.get(node).pop();
                stack.push(child);
            }
        }
    };

    // Build the graph and track in-degrees and out-degrees
    for (const [u, v] of pairs) {
        if (!adj.has(u)) adj.set(u, []);
        adj.get(u).push(v);
        outDegree.set(u, (outDegree.get(u) || 0) + 1);
        inDegree.set(v, (inDegree.get(v) || 0) + 1);
    }

    // Find the start node
    let start = pairs[0][0];
    for (const [node, outDeg] of outDegree) {
        const inDeg = inDegree.get(node) || 0;
        if (outDeg - inDeg === 1) {
            start = node;
            break;
        }
    }

    // Perform Eulerian path traversal
    euler(start);

    // Construct the result in reverse
    const result = [];
    for (let i = path.length - 1; i > 0; i--) {
        result.push([path[i], path[i - 1]]);
    }
    return result;
};
