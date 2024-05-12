#include<iostream>

using namespace std;

template<typename T>
inline const T& Max(const T& a, const T& b){
    return max(a,b);
};

int main(){
    int a = 5;
    int b = 6;

    const int& result = Max(a,b);
    cout << result << endl;

    int* arr = new int[5];

    for(int i = 0; i < 5; i++){
        arr[i] = i;
    };
    
   
    
}