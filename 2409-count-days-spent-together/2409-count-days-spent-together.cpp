
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        vector<int> days = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        auto getDay = [&](string date) {
            int month = (date[0] - '0') * 10 + (date[1] - '0');
            int day = (date[3] - '0') * 10 + (date[4] - '0');
            
            for(int i = 0; i < month - 1; i++) {
                day += days[i];
            }

            return day;
        };

        int start = max(getDay(arriveAlice), getDay(arriveBob));
        int end = min(getDay(leaveAlice), getDay(leaveBob));

        cout<< start<<", "<<end;

        return max(0, end - start + 1);
    }
};
