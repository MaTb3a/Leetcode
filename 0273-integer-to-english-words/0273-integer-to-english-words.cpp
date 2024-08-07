class Solution {
public:
    vector<string> leesThanTen = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> leesThanTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> leesThanHundred =  {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> MultibleofHundred =  {"Hundred", "Thousand", "Million", "Billion"};
    string solve(int num){
        if(num<10) 
            return leesThanTen[num];
        if(num < 20)
            return leesThanTwenty[num-10];
        if(num < 100) 
            return leesThanHundred[num / 10]  + ((num%10 == 0) ?  ""  :  " " + solve(num%10));
        if(num < 1000) 
            return solve(num / 100)  +  " Hundred"  + ((num%100 == 0) ?  ""  :  " " + solve(num%100));
        if(num < 1000000) 
            return solve(num / 1000)  +  " Thousand" +  ((num%1000 == 0) ?  ""  :  " " + solve(num%1000));
        if(num < 1000000000) 
            return solve(num / 1000000)  +  " Million"  + ((num%1000000 == 0) ?  ""  :  " " + solve(num%1000000));
        
        return solve(num / 1000000000)  +  " Billion"  + ((num%1000000000 == 0) ?  ""  :  " " + solve(num%1000000000));

    }
    string numberToWords(int num) {
       return solve(num);
    }
};