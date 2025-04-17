#include <string>
#include <vector>
#include <climits>
using namespace std;

int solution(vector<vector<int>> field, int farmSize) {
    int answer = INT_MAX;

    int row = field.size();
    int col = field[0].size();

    for(int i=0; i<=row - farmSize; i++) {
        for(int j=0; j<=col - farmSize; j++) {
            bool hasPoison = false;
            int rock = 0;

            for(int x=0; x<farmSize; x++) {
                for(int y=0; y<farmSize; y++) {
                    if(field[i + x][j + y] == 2) {
                        hasPoison = true;
                        break;
                    }
                    if(field[i+x][j+y] == 1) {
                        rock++;
                    }
                }
                if(hasPoison) break;
            }

            if(!hasPoison) {
                answer = min(answer, rock);
            }
        }
    }

    return (answer == INT_MAX) ? -1 : answer;
}