#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;

// 소수 여부를 캐시하기 위한 unordered_map
unordered_map<int, bool> primeCache;

// 소수 판별 함수
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    if (primeCache.find(n) != primeCache.end()) return primeCache[n];

    // 6의 배수 간격으로 소수 판별
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            primeCache[n] = false;
            return false;
        }
    }

    primeCache[n] = true;
    return true;
}

// 신기한 소수를 찾기 위한 백트래킹 함수
void findMagicPrimes(string num, int n) {
    if (num.length() == n) {
        if (isPrime(stoi(num))) {
            cout << num << endl;
        }
        return;
    }

    for (char c = '1'; c <= '9'; ++c) {
        string newNum = num + c;
        if (isPrime(stoi(newNum))) {
            findMagicPrimes(newNum, n);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (char c : {'2', '3', '5', '7'}) {
        findMagicPrimes(string(1, c), n);
    }

    return 0;
}
