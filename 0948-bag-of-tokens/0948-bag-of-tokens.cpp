class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(begin(tokens), end(tokens));


        int maxScore = 0;
        int score    = 0;

        // 100 , 200 , 300 , 400
        // i                   j

        int i = 0;
        int j = n - 1;

        while(i <= j) {

            if(power >= tokens[i]) {
                score++;

                power   -= tokens[i];
                maxScore = max(maxScore, score);

                i++;
            } else if(score >= 1) {
                score --;

                power += tokens[j];
                j--;
            } else {

                return maxScore;
            }
        }

        return maxScore;
    }
};