#include "Trie.h"

Trie::Node::Node(int childrenSize) {
    children = new Node*[childrenSize];

    for (int i = 0; i < childrenSize; i++) {
        children[i] = nullptr;
    }
}

void Trie::clear(Node* root) {
    if (!root) {
        return;
    }

    for (int i = 0; i < childrenSize; i++) {
        clear(root->children[i]);
    }

    delete[] root->children;
    delete root;
}

int Trie::convertCharToIndex(char c) { return c - 'a'; }

Trie::Node* Trie::removeHelper(Node* root, const std::string& word, int depth) {
    if (!root) {
        return nullptr;
    }

    int size = word.size();

    if (depth == size) {
        if (root->isEndOfWord) {
            root->isEndOfWord = false;
            root->meaning.clear();
        }

        if (isEmpty(root)) {
            delete root;
            root = nullptr;
        }

        return root;
    }

    int index = convertCharToIndex(word[depth]);
    root->children[index] =
        removeHelper(root->children[index], word, depth + 1);

    if (isEmpty(root) && root->isEndOfWord == false) {
        delete root;
        root = nullptr;
    }

    return root;
}

Trie::Trie(int childrenSize) : childrenSize(childrenSize) {}

bool Trie::isEmpty(Node* root) {
    for (int i = 0; i < childrenSize; i++) {
        if (root->children[i]) {
            return false;
        }
    }

    return true;
}

void Trie::insert(
    const std::string& word, const std::vector<std::string>& meaning
) {
    if (!root) {
        root = new Node(childrenSize);
    }

    Node* cur = root;
    int size = word.size();

    for (int i = 0; i < size; i++) {
        int idx = convertCharToIndex(word[i]);

        if (!cur->children[idx]) {
            cur->children[idx] = new Node(childrenSize);
        }

        cur = cur->children[idx];
    }

    cur->isEndOfWord = true;
    cur->meaning = meaning;
}

std::vector<std::string> Trie::getMeaning(const std::string& word) {
    std::vector<std::string> emptyList;

    if (!root) {
        return emptyList;
    }

    Node* cur = root;
    int size = word.size();

    for (int i = 0; i < size; i++) {
        int idx = convertCharToIndex(word[i]);
        cur = cur->children[idx];

        if (!cur) {
            return emptyList;
        }
    }

    return cur->isEndOfWord ? cur->meaning : emptyList;
}

Trie::Node* Trie::remove(const std::string& word) {
    return removeHelper(root, word, 0);
}

Trie::~Trie() { clear(root); }
