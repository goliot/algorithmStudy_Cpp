#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int minCity = INT_MAX;
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;
vector<int> selected;

void cal() {
    int cityDistance = 0;
    for(int i=0; i<house.size(); i++) {
        int minHouseDistance = INT_MAX;
        for(int j=0; j<chicken.size(); j++) {
            if(selected[j]==1) {
                int houseDistance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                minHouseDistance = min(minHouseDistance, houseDistance);
            }
        }
        cityDistance += minHouseDistance;
    }
    minCity = min(cityDistance, minCity);
}

void selectChicken() {
    for(int i=0; i<chicken.size()-m; i++) {
        selected.push_back(0);
    }
    for(int i=0; i<m; i++) {
        selected.push_back(1);
    }
    do {
        cal();
    } while(next_permutation(selected.begin(), selected.end()));
}
int main() {
    cin >> n >> m;
    int flag;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> flag;
            if(flag==1) house.emplace_back(i, j);
            else if(flag==2) chicken.emplace_back(i, j);
        }
    }
    selectChicken();
    cout << minCity;

    return 0;
}