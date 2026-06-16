//Generic Greedy Template
sort(arr.begin(), arr.end()); // sometimes needed

for (auto &x : arr) {

    if (can_take(x)) {
        take(x);
    }
    else {
        skip(x);
    }
}

return answer;
//_________________________________________________________________________________
/* Template 1: Keep Best Answer So Far
Used in:
Jump Game
Best Time to Buy and Sell Stock
Gas Station*/
int best = initial_value;

for (auto x : arr) {
    best = max(best, some_calculation);
}

return best;
______________________________________________________________________________________
/*Template 2: Sort + Take Earliest

Used in:

Activity Selection
Non-overlapping Intervals
Meeting Rooms*/
sort(intervals.begin(), intervals.end(), compare);

int count = 0;
int endTime = -1;

for (auto &interval : intervals) {

    if (interval.start >= endTime) {
        count++;
        endTime = interval.end;
    }
}
/*_________________________________________________________________________________________
Template 4: Resource Assignment

Used in:

Assign Cookies
Boats to Save People*/
sort(a.begin(), a.end());
sort(b.begin(), b.end());

int i = 0;
int j = 0;

while (i < a.size() && j < b.size()) {

    if (can_match(a[i], b[j])) {
        answer++;
        i++;
        j++;
    }
    else {
        j++;
    }
}
/*__________________________________________________________________________________________________
Template 5: Intervals Greedy

Used in:

Merge Intervals
Insert Interval*/
sort(intervals.begin(), intervals.end());

vector<vector<int>> result;

for (auto &interval : intervals) {

    if (result.empty() ||
        result.back()[1] < interval[0]) {

        result.push_back(interval);
    }
    else {

        result.back()[1] =
            max(result.back()[1], interval[1]);
    }
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Example: Best Time to Buy and Sell Stock*/
  int minPrice = INT_MAX;
int profit = 0;

for (int price : prices) {
    minPrice = min(minPrice, price);
    profit = max(profit, price - minPrice);
}

return profit;
