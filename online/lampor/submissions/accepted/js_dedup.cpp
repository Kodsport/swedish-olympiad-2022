#include <iostream>
#include <string>

using namespace std;

int compute(string& R, string& L, bool hasR, bool hasG, bool hasB) {
    int whiteSquares = 0;
    for (int i = 0; i < (int)R.size(); i++) {
        bool r = hasR || R[i] == 'R' || L[i] == 'R';
        bool g = hasG || R[i] == 'G' || L[i] == 'G';
        bool b = hasB || R[i] == 'B' || L[i] == 'B';

        if (r && g && b) whiteSquares++;
    }
    return whiteSquares;
}

int main() {
    int ign;
    cin >> ign >> ign;
    string U, R, B, L;
    cin >> U >> R >> B >> L;

    int RR = compute(R, L, true, false, false);
    int GG = compute(R, L, false, true, false);
    int BB = compute(R, L, false, false, true);
    int RG = compute(R, L, true, true, false);
    int RB = compute(R, L, true, false, true);
    int GB = compute(R, L, false, true, true);

    long long whiteSquares = 0;
    for (int i = 0; i < (int)U.size(); i++) {
        bool hasR = U[i] == 'R' || B[i] == 'R';
        bool hasG = U[i] == 'G' || B[i] == 'G';
        bool hasB = U[i] == 'B' || B[i] == 'B';
        if (hasR && hasG) whiteSquares += RG;
        else if (hasR && hasB) whiteSquares += RB;
        else if (hasG && hasB) whiteSquares += GB;
        else if (hasR) whiteSquares += RR;
        else if (hasG) whiteSquares += GG;
        else if (hasB) whiteSquares += BB;
    }

    cout << whiteSquares << endl;
}
