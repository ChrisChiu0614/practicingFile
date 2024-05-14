#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr = {1,2,3,4,5};
    int sum = 0;
    cout << "to implement cbegin" <<endl;
    for(auto i = arr.cbegin(); i < arr.cend(); i++){
        if(*i%2!=0){
            sum+=*i;
        }
        
    }
    cout << "odd sum of arr : " << sum << endl;

    cout << "to implement rbegin" <<endl;
    for (auto i = arr.rbegin(); i < arr.rend(); i++)
    {
        cout<<*i<<endl;
    }
    
    return 0;
}