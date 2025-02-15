/**
 * @param {number} n
 * @return {number}
 */
function solve(num,target){
    if (num === target)return true;
    if(num < target || target < 0)return false;
    return solve(Math.floor(num/10),target - num%10) || solve(Math.floor(num/100),target - num%100) || solve(Math.floor(num/1000),target - num%1000)
}
var punishmentNumber = function(n) {
    let answer = 0;
    for(let i = 1 ; i <= n;i++){
        if(solve(i*i,i))
            answer+=i*i;
    }
    return answer;
    
};