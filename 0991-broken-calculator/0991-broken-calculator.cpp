class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        // we just reversed the logic, we are going from the target to startValue
        // instead of -1 , we are doing +1 &&  *2 to /2
        
        if(startValue >= target) {
            return startValue - target;
        }


        if(target % 2 == 0) {
            return 1 + brokenCalc(startValue, target / 2);
        }


        return 1 + brokenCalc(startValue, target + 1);
    }
};