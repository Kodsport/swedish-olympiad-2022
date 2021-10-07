#include <bits/stdc++.h>

using namespace std;

int toi(char c) {
    switch (c) {
        case 'R': return 1;
        case 'G': return 2;
        case 'B': return 4;
    }
    return 0;
}

int main() {
    int r, c;
    cin >> r >> c;
    string U, R, B, L;
    cin >> U >> R >> B >> L;
    for (int i = 0; i < c; i++) U[i] = toi(U[i]);
    for (int i = 0; i < r; i++) R[i] = toi(R[i]);
    for (int i = 0; i < c; i++) B[i] = toi(B[i]);
    for (int i = 0; i < r; i++) L[i] = toi(L[i]);

    long long ans = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            ans += (U[j] | B[j] | R[i] | L[i]) == 7;
        }
    cout << ans << endl;
}
