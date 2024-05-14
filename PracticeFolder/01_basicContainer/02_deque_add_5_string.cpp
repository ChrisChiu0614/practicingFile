#include <iostream>
#include <string>
#include <deque>
#include <algorithm> // for remove_if

using namespace std;

void printF(const deque<string>& ds){
    for(const auto& s : ds){
        cout << s;
    }
    cout << endl;

}

int main()
{
    deque<string> ds;
    string strfornt[] = {"chris,","Hello! "};
    string strBack[] = {"you're ", " a ", "super software engineer!"};
    for(const auto& str:strfornt){
        ds.push_front(str);
    }
    for(const auto& str:strBack){
        ds.push_back(str);
    }

    printF(ds);
    
    /**
     * string::npos是C++标准库中std::string类的一个常量，用于表示“没有找到”的特殊值。它实际上是std::string类中声明的一个静态成员，等同于一个很大的无符号整数值（通常是-1转化成的无符号数）。它在标准库中已经定义好，无需用户显式声明。npos的全称是“not a position”。
    */
    auto rem = remove_if(ds.begin(),ds.end(),[](const string& x){return x.find("Hello! ") != string::npos;});
    ds.erase(rem,ds.end());
    
    printF(ds);
}