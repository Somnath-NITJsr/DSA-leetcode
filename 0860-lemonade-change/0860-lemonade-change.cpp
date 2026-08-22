class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten  = 0;


        for(auto& bill : bills) {

            if(bill == 5) {
                five++;
            } else if(bill == 10) { // return 5

                if(five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else if(five > 0 && ten > 0) { // return 15, 10 and 5
                five--;
                ten--;
            } else if(five >= 3) { // return  5 thrice
                five -= 3;
            } else {
                return false;
            }

        }
        
        return true;
    }
};