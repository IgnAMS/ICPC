#include <iostream>
#include <cassert>
#include "validation.h"

std::string wordle_query(std::string query, std::string answer) {
    int n = std::size(query);
    std::string res(n, 'B');

    std::array<int,26> count = {};
    for (char c: answer) count[c-'a']++;

    // place green tiles
    for (int i = 0; i < n; i++) {
        if (query[i] == answer[i]) {
            res[i] = 'G';
            count[query[i]-'a']--;
        } 
    }

    // place yellow tiles
    for (int i = 0; i < n; i++) {
        if (res[i] != 'G' && count[query[i]-'a'] > 0) {
            count[query[i]-'a']--;
            res[i] = 'Y';
        }
    }

    return res;
}

int main(int argc, char **argv) {
    std::ifstream in(argv[1]);
    OutputValidator v(argc, argv);

    int m, n;
    in >> m >> n;

    std::vector<std::string> words(m-1), colors(m-1);
    for (int i = 0; i < m-1; i++) {
        in >> words[i] >> colors[i];
    }
    
    std::string all_letters = std::string(26, 'a') + std::string(26, 'A');
    for (int i = 0; i < 26; i++) {
        all_letters[i] += i;
        all_letters[26+i] += i;
    }
    
    // TODO: extend validation.h with case insensitivity?
    std::string answer = v.read_string("word", n, n, all_letters);
    for (char& c : answer) c |= 0x20;
    v.newline();

    for (int i = 0; i < m-1; i++) {
        v.check(wordle_query(words[i], answer) == colors[i],
                "Wrong answer: does not fit word ", i);
    }
}
