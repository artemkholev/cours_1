#include <iostream>
#include <vector>
using namespace std;

int hash_elem(string str, int len_str, int mod) {
    int hash_elem = 0;
    for (int i = 0; i < len_str; i++) {
        hash_elem = (str[i] + 26 * hash_elem) % mod;
    }
    return hash_elem;
}

int new_hash_elem(string str, int mod, int old_hash, int dop, int index, int len_pattern) {
    int update_hash = 0;
    update_hash = (26 * (old_hash - str[index] * dop) + str[index + len_pattern]) % mod;
    if (update_hash < 0) update_hash += mod;
    return update_hash;
}

void find(string text, string pattern, int len_text, int len_pattern, int mod, vector<int> &save, vector<int> &spurious_hits) {
    int index = 0, dop = 1;
    int hash_elem_pattern = hash_elem(pattern, len_pattern, mod);
    int hash_elem_text = hash_elem(text, len_pattern, mod);
    for (int i = 0; i < len_pattern - 1; i++) {
        dop = (26 * dop) % mod;
    }

    for (index = 0; index <= len_text - len_pattern; index++) {
        if (hash_elem_pattern == hash_elem_text) {
            int j = 0, flag = 0;
            while (j < len_pattern && text[index + j] == pattern[j]) {
                if (j == len_pattern - 1) {
                    save.push_back(index);
                    flag = 1;
                }
                j++;
            }
            if (flag == 0) {
                spurious_hits.push_back(index);
            }
        }

        if (index < len_text - len_pattern) {
            hash_elem_text = new_hash_elem(text, mod, hash_elem_text, dop, index, len_pattern);
        }
    }
}

int main() {
    vector<int> matches;
    vector<int> spurious_hits;
    string text, pattern;
    int mod;
    cin >> mod >> pattern >> text;
    int len_text = text.size();
    int len_pattern = pattern.size();
    find(text, pattern, len_text, len_pattern, mod, matches, spurious_hits);
    cout << "Matches: ";
    for (int i = 0; i < matches.size(); i++) {
        cout << matches[i] << " ";
    }
    cout << "\nSpurious hits: ";
    for (int i = 0; i < spurious_hits.size(); i++) {
        cout << spurious_hits[i] << " ";
    }
    return 0;
}
