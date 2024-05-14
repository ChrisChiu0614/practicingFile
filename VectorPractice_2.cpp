#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    // 使用 reserve 預先分配容量為 10
    vec.reserve(10);

    std::cout << "Capacity after reserve: " << vec.capacity() << std::endl;

    // 將一些元素添加到 vector 中
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }

    std::cout << "Size after pushing back 5 elements: " << vec.size() << std::endl;

    return 0;
}
