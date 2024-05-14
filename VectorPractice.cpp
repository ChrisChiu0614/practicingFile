#include <iostream>
#include <vector>

int main() {
    // 創建一個空的 vector
    std::vector<int> vec;

    // 使用 resize 將 vector 大小設置為 5，並初始化為 0
    vec.resize(5);

    // 使用 reserve 提前分配記憶體空間，但不會改變 vector 的大小
    vec.reserve(10);

    // 使用 emplace_back 在 vector 的末尾插入元素，而不需要額外的拷貝或移動操作
    vec.emplace_back(10);
    vec.emplace_back(20);
    vec.emplace_back(30);

    // 使用 clear 清空 vector
    vec.clear();

    // 使用 capacity 獲取 vector 當前能容納的元素個數
    std::cout << "Capacity after clear: " << vec.capacity() << std::endl;

    return 0;
}
