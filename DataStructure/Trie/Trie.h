#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>

class Trie {
   private:
    struct Node {
        std::vector<std::string> meaning;
        bool isEndOfWord = false;
        Node** children;

        Node(int childrenSize);
    };

    int childrenSize;
    Node* root = nullptr;

    void clear(Node* root);
    int convertCharToIndex(char c);
    Node* removeHelper(Node* root, const std::string& word, int depth);

   public:
    Trie(int childrenSize);
    bool isEmpty(Node* root);
    void insert(
        const std::string& word, const std::vector<std::string>& meaning
    );
    std::vector<std::string> getMeaning(const std::string& word);
    Node* remove(const std::string& word);
    ~Trie();
};

#endif
