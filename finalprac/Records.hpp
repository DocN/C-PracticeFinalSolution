#pragma once
#include <vector>

template <typename K, typename V>

class Records {
private:
	std::vector<V> value;
	K key;
public:
	Records(K newKey) {
		std::cout << "records constructor " << std::endl;
		key = newKey;
	}
	void addRecord(V currentVal) {
		value.push_back(currentVal);
	}
};