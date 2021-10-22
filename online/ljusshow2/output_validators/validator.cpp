// usage: ./a.out input_file correct_output output_dir < contestants_output
#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define trav(a, x) for(auto& a : x)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

static string input_file, output_dir, answer_file;

void die(const string& msg) {
    cout << msg << endl;
    ofstream(output_dir + "/score.txt") << 0;
    exit(43);
}

void accept(long double score) {
    ofstream(output_dir + "/score.txt") << setprecision(2) << fixed << score;
    exit(42);
}

void judge_error(const string& msg) {
	cout << msg << endl;
	exit(1);
}

template <class F>
void assert_done(istream& is, F fail) {
    try {
        string dummy;
        is >> dummy;
		if (is) fail("extraneous data: " + dummy);
    } catch(...) {}
}

int char_to_mask(char ch){
    if(ch == 'R')return 1;
    if(ch == 'G')return 2;
    if(ch == 'B')return 4;
    return -1;
}

template <class F>
double score(istream& is, vector<string>& grid, F fail) {
	int n = sz(grid);
	int m = sz(grid[0]);
    vector<int> row_masks(n, 0);
    vector<int> col_masks(m, 0);

    rep(c1,0,4){
        string s;
        if(!(is >> s)){
            fail("Could not read answer.\n");
        }
        if((c1%2 == 0 && sz(s) != m) || (c1%2 == 1 && sz(s) != n)){
            fail("Answer had invalid length.\n");
        }
        rep(c2,0,sz(s)){
            if(s[c2] != 'R' && s[c2] != 'G' && s[c2] != 'B'){
                fail("Invalid character.\n");
            }
            if(c1%2 == 0){
                col_masks[c2] |= char_to_mask(s[c2]);
            }
            else{
                row_masks[c2] |= char_to_mask(s[c2]);
            }
        }
    }
	assert_done(is, fail);

    int matches = 0;
    rep(c1,0,n){
        rep(c2,0,m){
            matches += (((row_masks[c1]|col_masks[c2]) == 7) == (grid[c1][c2] == '1'));
        }
    }

    double ans = max(0.0, double(matches) - double(n*m)/2.0);
	return ans;
}

int main(int argc, char** argv) {
    if (argc < 4) exit(1);
    cin.sync_with_stdio(0);
    cin.tie(0);

    input_file = argv[1];
    answer_file = argv[2];
    output_dir = argv[3];

    ifstream fin(input_file);
    fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);

    int T;
    fin >> T;

    int n, m;
    fin >> n >> m;

	vector<string> grid;

	rep(i,0,n){
		string line;
		fin >> line;
		grid.push_back(line);
	}

    assert_done(fin, die);
    fin.close();

	ifstream fans(answer_file);

    try {
		long double sc = score(cin, grid, die);
		long double bestsc = score(fans, grid, judge_error);
        //bestsc = double(n*m)/2.0;
		long double ratio = sc / bestsc;
		if (T == 0) accept(0);
		else accept(10.0 * ratio);
    } catch(...) {
        die("IO failure");
    }
}