#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    string vowels = "aeiouy";
    cin >> s;
    bool vowel_map[26] = {0};
    for(int c1 = 0; c1 < vowels.length(); c1++){
        vowel_map[vowels[c1]-'a'] = 1;
    }
    int n = s.length();
    int ans = 0;
    for(int mask = 1; mask < (1 << n); mask++){
        string word = "";
        int mask2 = mask;
        for(int c1 = 0; c1 < n; c1++){
            if(mask2%2 == 1)word += s[c1];
            mask2 /= 2;
        }
        bool valid = 1;
        for(int c1 = 0; c1 < int(word.length())-2; c1++){
            if(vowel_map[word[c1]-'a'] && !vowel_map[word[c1+1]-'a'] && !vowel_map[word[c1+2]-'a']){
                valid = 0;
            }
        }
        ans += valid;
    }
    cout << ans << "\n";

    return 0;
}

