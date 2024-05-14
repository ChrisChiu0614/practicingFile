#include <iostream>
using namespace std;
int main()
{
    vector<int> vec;
    // add 10 memeris space
    vec.reserve(10);
    int i = 0;
    // add 1-10 number in the vec
    while (i < 10)
    {
        vec.push_back(++i);
    }

    // traverse the vec from 1-10
    for (auto j = vec.cbegin(); j < vec.cend(); j++)
    {
        cout << *j << endl;
    }

    /**
     * implement the sum from 1-10
     * ans # 55
     */
    int sum = 0;
    for (auto j = vec.cbegin(); j < vec.cend(); j++)
    {
        sum += *j;
    }
    cout << "sum: " << sum << endl;
}