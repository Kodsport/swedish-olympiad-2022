#!/usr/bin/env python3

input()

def compute(R, L, hasR, hasG, hasB):
    whiteSquares = 0
    for i in range(len(R)):
        r = hasR or R[i] == 'R' or L[i] == 'R'
        g = hasG or R[i] == 'G' or L[i] == 'G'
        b = hasB or R[i] == 'B' or L[i] == 'B'

        if r and g and b:
            whiteSquares += 1
    return whiteSquares

U, R, B, L = input(), input(), input(), input()

RR = compute(R, L, True, False, False)
GG = compute(R, L, False, True, False)
BB = compute(R, L, False, False, True)
RG = compute(R, L, True, True, False)
RB = compute(R, L, True, False, True)
GB = compute(R, L, False, True, True)

whiteSquares = 0
for i in range(len(U)):
    hasR = U[i] == 'R' or B[i] == 'R'
    hasG = U[i] == 'G' or B[i] == 'G'
    hasB = U[i] == 'B' or B[i] == 'B'
    if hasR and hasG:
        whiteSquares += RG
    elif hasR and hasB:
        whiteSquares += RB
    elif hasG and hasB:
        whiteSquares += GB
    elif hasR:
        whiteSquares += RR
    elif hasG:
        whiteSquares += GG
    elif hasB:
        whiteSquares += BB

print(whiteSquares)
