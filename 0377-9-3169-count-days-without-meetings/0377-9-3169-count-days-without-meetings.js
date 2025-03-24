/**
 * @param {number} days
 * @param {number[][]} meetings
 * @return {number}
 */
var countDays = function(days, meetings) {
    meetings.sort((a, b) => a[0] - b[0]);
    let d = 0;
    let ans = 0;
    for (const meet of meetings) {
        const start = meet[0];
        const end = meet[1];
        if (start > d) {
            ans += start - d - 1;
        }
        d = Math.max(d, end);
    }
    return ans + (days - d);

};