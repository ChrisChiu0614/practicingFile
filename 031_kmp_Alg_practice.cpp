#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> next(string patt)
{
    int length = patt.length();
    vector<int> next(length, 0);
    int j = 0;

    for (int i = 1; i < length;)
    {
        
        if (patt[i] == patt[j])
        {
            next[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = next[j - 1];
            }
            else
            {
                next[i] = 0;
                i++;
            }
        }
    }
   for (size_t i = 0; i < next.size(); i++)
   {
    cout << next[i]<<endl;
   }
   
    return next;
};


vector<int> kmp(const string& t, const string& p){
    int tLen = t.size();
    int pLen = p.size();
    
    vector<int> nextT = next(p);
    vector<int> matches;

    
    int i =0, j = 0;

    while(i < tLen){
        if(p[j]==t[i]){
            i++;
            j++;
        }
        if(j == pLen){
            matches.push_back(i-j);
            j= nextT[j-1];
        }else if(i < tLen && p[j]!= t[i]){
            if(j!=0){
                j= nextT[j-1];
            }else{
                i++;
            }
        }
    }

    return matches;

}


int main(){
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    vector<int> matches = kmp(text, pattern); // 使用KMP算法查找匹配位置
    cout<<"----------" << endl;
    cout<<"123" << endl;
    if(matches.empty()){
        cout<<"not found" << endl;
    }else{
       cout << "-------打印所有匹配位置索引:"; // 打印所有匹配位置索引
        for (size_t i = 0; i < matches.size(); i++) {
            cout << " " << matches[i];
        }
        cout << endl;
    }
    return 0;
}