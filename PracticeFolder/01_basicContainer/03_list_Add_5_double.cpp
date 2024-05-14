#include <iostream>
#include <list>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

void findMaxAndMinByList(const list<double>& l)
{
    double min = numeric_limits<double>::max();
    double max = numeric_limits<double>::min();
    for (auto i = l.cbegin(); i != l.cend(); i++)
    {
        if (*i < min)
        {   
            min = *i;
        }
        if(*i > max){
            max = *i;
        }
    }
        cout << "Max: "<<max<<" Min: "<<min << endl;
}

int main()
{
    list<double> l;

    random_device rd;
    default_random_engine eng(rd());

    uniform_real_distribution<double> distr(1.0, 10.01);
    int i = 0;
    while(i < 5){
        double d = distr(eng);
        cout << d<< endl;
        l.push_back(d);
        i++;
    }



    findMaxAndMinByList(l);
}