#include <string>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

constexpr double BallDiameter = 2;

vector<double> normalize(const vector<double>& v) {
    double mag = sqrt(pow(v[0], 2) + pow(v[1], 2));
    return {v[0] / mag, v[1] / mag};
}

double calTime(const vector<double>& ball, const vector<double>& dir) {
    double x = ball[0], y = ball[1];
    double dx = dir[0], dy = dir[1];

    double radSum = 2.0;

    double a = dx * dx + dy * dy;
    double b = 2 * (dx * 0 + dy * 0 - dx * x - dy * y);
    double c = x * x + y * y - radSum * radSum;

    double collision = b * b - 4 * a * c;

    if(collision <= 0) return -1;

    double t1 = (-b - sqrt(collision)) / (2 * a);
    double t2 = (-b + sqrt(collision)) / (2 * a);

    double colTime = (t1 > 0) ? t1 : ((t2 > 0) ? t2 : -1);

    return colTime;
}

int solution(vector<vector<double>> objectBallPosList, vector<double> hitVector) {
    int answer = -1;

    double minTime = numeric_limits<double>::max();

    vector<double> normalizedHitVec = normalize(hitVector);

    for(int i=0; i<objectBallPosList.size(); i++) {
        double colTime = calTime(objectBallPosList[i], normalizedHitVec);

        if(colTime < minTime && colTime > 0) {
            minTime = colTime;
            answer = i;
        }
    }

    return answer;
}