function mergeArrays(nums1, nums2) {
    let i = 0, j = 0;
    const n = nums1.length, m = nums2.length;
    const result = [];

    while (i < n || j < m) {
        // Get the current IDs or infinity if one array is exhausted
        const id1 = i < n ? nums1[i][0] : Infinity;
        const id2 = j < m ? nums2[j][0] : Infinity;

        if (id1 < id2) {
            // Append the element from nums1
            result.push(nums1[i]);
            i++;
        } else if (id2 < id1) {
            // Append the element from nums2
            result.push(nums2[j]);
            j++;
        } else {
            // Merge the elements with the same ID
            result.push([id1, nums1[i][1] + nums2[j][1]]);
            i++;
            j++;
        }
    }
    return result;
}