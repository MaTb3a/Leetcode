class Solution {
    public boolean ok(long md,int [] ranks,long cars){
        long cnt = 0;
        for(int i = 0 ; i < ranks.length;i++){
            cars-=(long)Math.sqrt(md/(long)ranks[i]);
        }
        return cars <=0;
    }
    public long repairCars(int[] ranks, int cars) {
        long st = 1, ed = 100L*cars*cars,md,cur = -1;
        while(st<=ed){
            md = (st+ed)/2;
            if(ok(md,ranks,cars)){
                ed = md -1;
                cur = md;
            }
            else st = md+1;
        }
        return cur;
    }
}