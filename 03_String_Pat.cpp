#include <iostream>
#include <vector>
#include <string>

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

    return next;
};

vector<int> kmpAlg(const string &text, const string &patt)
{
    int textLen = text.size();
    int pattLen = patt.size();
    vector<int> nextTable = next(patt);
    vector<int> matches;
    int i = 0, j = 0;

    while (i < textLen)
    {
        if (patt[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == pattLen)
        {
            matches.push_back(i - j);
            j = nextTable[j - 1];
        }
        else if (i < textLen && patt[j] != text[i])
        {
            if (j != 0)
            {
                j = nextTable[j - 1];
            }else{
                i++;
            }
        }
    }
    return matches;
};

int main(){
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    vector<int> matches = kmpAlg(text, pattern); // 使用KMP算法查找匹配位置
    
    if (matches.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at indices:"; // 打印所有匹配位置索引
        for (size_t i = 0; i < matches.size(); i++) {
            cout << " " << matches[i];
        }
        cout << endl;
    }
    
    return 0;
}