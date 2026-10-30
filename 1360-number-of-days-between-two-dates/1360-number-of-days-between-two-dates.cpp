class Solution {
public:
    int daysBetweenDates(string dat1, string dat2) {
        int n = dat1.length();
        vector<int> days = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

        auto getDay = [&](string date) {

            int year = stoi(date.substr(0, 4));
            int month = stoi(date.substr(5, 2));
            int day = stoi(date.substr(8, 2));

            int total = year * 365 + day;

            for(int i = 0; i < month - 1; i++) {
                total += days[i];
            }

            // Count leap years
            total += (year - 1) / 4 - (year - 1) / 100
                     + (year - 1) / 400;

            // Leap year adjustment
            if(month > 2 && (year % 400 == 0 ||
               (year % 4 == 0 && year % 100 != 0))) {
                total++;
            }

            return total;
        };

    return abs(getDay(dat1) - getDay(dat2));
    }
};