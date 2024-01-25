#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int ascii_offset = 97;
const int alph_size = 26;

void recurse_chars(set<string> &lines, string c, string current) {
    if (c.length() == 0) {
        lines.insert(current);
        return;
    }
    
    for (int i = 0; i < c.length(); i++) {
        recurse_chars(
            lines,
            c.substr(0, i) + c.substr(i+1),
            current + c[i]
        );
    }
}

int main() {
    string s;
    cin >> s;

    int letters[alph_size] = {};

    for (int i = 0; i < s.size(); i++) letters[s[i] - ascii_offset]++;

    string c = "";
    for (int i = 0; i < alph_size; i++) {
        int n = letters[i];
        for (int j = 0; j < n; j++) c += char(i+ascii_offset);
    }

    set<string> lines;
    recurse_chars(lines, c, "");

    cout << lines.size() << "\n";
    for (string l : lines) cout << l << "\n";
}