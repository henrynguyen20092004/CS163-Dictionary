#ifndef MAP_H
#define MAP_H

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

template <typename Key, typename Val, typename Hash = std::hash<Key>>
class Map {
   private:
    static constexpr size_t DEFAULT_SIZE = 1000;
    using KeyValPair = std::pair<Key, Val>;
    using List = std::list<KeyValPair>;
    size_t numElements;
    std::vector<List> lists;
    Hash HashFunc;

    Val &insertDefault(const Key &key) {
        size_t index = HashFunc(key) % lists.size();
        auto &list = lists[index];
        list.emplace_back(key, Val{});
        ++numElements;
        return list.back().second;
    }

   public:
    explicit Map(size_t size = DEFAULT_SIZE) : lists(size), numElements(0) {}

    ~Map() { clear(); }

    bool isEmpty() const { return numElements == 0; }

    size_t size() const { return numElements; }

    bool contains(const Key &key) const {
        size_t index = HashFunc(key) % lists.size();
        auto &list = lists[index];
        return std::find_if(list.begin(), list.end(), [&key](const auto &pair) {
                   return pair.first == key;
               }) != list.end();
    }

    void insert(const Key &key, const Val &val) {
        size_t index = HashFunc(key) % lists.size();
        auto &list = lists[index];
        const auto &iter =
            std::find_if(list.begin(), list.end(), [&key](const auto &pair) {
                return pair.first == key;
            });
        if (iter != list.end()) {
            return;
        } else {
            list.emplace_back(key, val);
            ++numElements;
        }
    }

    void update(const Key &key, const Val &val) {
        size_t index = HashFunc(key) % lists.size();
        auto &list = lists[index];
        const auto &iter =
            std::find_if(list.begin(), list.end(), [&key](const auto &pair) {
                return pair.first == key;
            });
        if (iter != list.end()) {
            iter->second = val;
            return;
        } else {
            list.emplace_back(key, val);
            ++numElements;
        }
    }

    void remove(const Key &key) {
        size_t index = HashFunc(key) % lists.size();
        auto &list = lists[index];
        const auto &iter =
            std::find_if(list.begin(), list.end(), [&key](const auto &pair) {
                return pair.first == key;
            });
        if (iter != list.end()) {
            list.erase(iter);
            --numElements;
        }
    }

    void clear() {
        for (auto &list : lists) {
            list.clear();
        }
        numElements = 0;
    }

    std::vector<Key> listKeys() const {
        std::vector<Key> result;
        for(const auto &list: lists) {
            for(const auto &ele: list) {
                result.push_back(ele.first);
            }
        }
        return result;
    }
    Val &value(const Key &key) {
        size_t index = HashFunc(key) % lists.size();
        auto &list = lists[index];
        const auto &iter =
            std::find_if(list.begin(), list.end(), [&key](const auto &pair) {
                return pair.first == key;
            });
        if (iter != list.end()) {
            return iter->second;
        } else {
            return this->insertDefault(key);
        }
    }

    Val &operator[](const Key &key) { return this->value(key); }

};

#endif  // MAP_H
