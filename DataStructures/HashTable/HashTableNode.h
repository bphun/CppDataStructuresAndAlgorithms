
template <typename KeyType, typename ValueType>
struct HashTableNode {

    KeyType key;
    ValueType value;

    HashTableNode(const KeyType& key, const ValueType& value) {
        this->key = key;
        this->value = value;
    }
};