/**
 * @param {number[]} ranks
 * @param {number} cars
 * @return {number}
 */

var ok = function(md,ranks,cars){
    for (let r of ranks){
        cars-=Math.floor(Math.sqrt(md/r));
    }
    return cars<=0;
}
var repairCars = function(ranks, cars) {
    let st = 1;
    let ed = Math.min(...ranks) * cars * cars;
    let cur = -1;
    while(st<=ed){
        let md = Math.floor((st+ed)/2);
        if(ok(md,ranks,cars)){
            cur = md;
            ed = md-1;
        }
        else st = md+1;
    }
    return cur;
};