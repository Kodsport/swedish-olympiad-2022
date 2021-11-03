#!/usr/bin/env python3
n = int(input())
vowels = "aieouyAIEOUY"
consonants = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ"
words = input().split()
result = ""
for j, word in enumerate(words):
    for i, letter in enumerate(word):
        if letter in vowels:
            if (
                i + 2 >= len(word)
                or word[i + 1] not in consonants
                or word[i + 2] not in consonants
            ):
                result += letter
        else:
            result += letter
    if j + 1 != len(words):
        result += " "
print(result[::-1])  # Reverses the string
