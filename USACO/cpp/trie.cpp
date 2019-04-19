#include <iostream>
#include <fstream>

#define MAX_N 100005

using namespace std;

struct trie {
    int prefix;
    int words;
    
    struct trie* con[26];
};

trie* init() { 
    trie *a = new trie;
    a->prefix = 0; a->words = 0;

    for (int i = 0; i < 26; i ++) { a->con[i] = NULL; }
    
    return (a);
}

void add_word(trie* vertex, string st) {
    if (st.size() == 0) { vertex->words ++; }
    else {
        vertex->prefix ++;
        
        if (vertex->con[st[0] - 'a'] == NULL) 
        { vertex->con[st[0] - 'a'] = init(); }
        
        add_word(vertex->con[st[0] - 'a'], st.substr(1, st.size() - 1));
    }
}

int count_prefix(trie* vertex, string pre) {
    if (pre.size() == 0) { return (vertex->prefix); }
    else if (vertex->con[pre[0] - 'a'] == NULL) { return (0); }
    else {
        return (count_prefix(vertex->con[pre[0] - 'a'], pre.substr(1, pre.size() - 1)));
    }
}

int count_word(trie* vertex, string word) {
    if (word.size() == 0) { return (vertex->words); }
    else if (vertex->con[word[0] - 'a'] == NULL) { return (0); }
    else {
        return (count_word(vertex->con[word[0] - 'a'], word.substr(1, word.size() - 1)));
    }
}

trie* root;

int main() {
    root = init();
    
    add_word(root, "harro");
    add_word(root, "hasdassadassd");

    cout << count_word(root, "harro") << endl;

    return (0);
}