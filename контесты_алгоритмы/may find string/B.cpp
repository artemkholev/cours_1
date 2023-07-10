#include <iostream>
#include <vector>
using namespace std;

void  prefix(string str, vector<int> &prefix, int len_str);
void find(string text, string pattern, int len_text, int len_pattern, vector<int> &save, vector<int> &prefix_template, vector<int> &prefix_function);

int main() {
    vector<int> matches, prefix_template, prefix_function;
    string text, pattern;
    cin >> pattern >> text;
    int len_pattern = pattern.size();
    int len_text = text.size() + 1 + len_pattern;
    prefix_template.resize(len_pattern);
    prefix_function.resize(len_text);
    find(text, pattern, text.size(), len_pattern, matches, prefix_template, prefix_function);
    cout << "Prefix template: ";
    for (int i = 0; i < prefix_template.size(); i++) {
        cout << prefix_template[i] << " ";
    }
    cout << "\nPrefix function: ";
    for (int i = 0; i < len_text; i++) {
        cout << prefix_function[i] << " ";
    }
    cout << "\nMatches: ";
    for (int i = 0; i < matches.size(); i++) {
        cout << matches[i] << " ";
    }
    return 0;
}

void  prefix(string str, vector<int> &prefix, int len_str) {
    for (int i = 1; i <  len_str; i++) {
        int k = prefix[i - 1];
        while (k > 0 && str[i] != str[k]) {
            k = prefix[k - 1];
        }
        if (str[i] == str[k]) {
            k++;
        }
        prefix[i] = k;
    }
}

void find(string text, string pattern, int len_text, int len_pattern, vector<int> &save, vector<int> &prefix_template, vector<int> &prefix_function) {
    int index_pattern = 0, index_text = 0;
    prefix(pattern, prefix_template, len_pattern);
    string expand_str = pattern + '+' + text;
    prefix(expand_str, prefix_function, expand_str.size());

    while (index_text < len_text) {
        if (text[index_text] == pattern[index_pattern]) {
            if (index_pattern == len_pattern - 1) {
                save.push_back(index_text - len_pattern + 1);
            }
            index_text++, index_pattern++;
        } else if (index_pattern > 0 && text[index_text] != pattern[index_pattern]) {
            index_pattern = prefix_template[index_pattern - 1];
        } else {
            index_pattern = 0, index_text++;
        }
    }
}
