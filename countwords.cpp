//输入一系列单词，根据出现频率输出单词，当频率一致时，按字典序输出
#include<iostream>
#include<map>
#include<set>
using namespace std;

typedef map<string, int> MP;

struct word{
    string word;
    int count;
};

struct rule{
    bool operator ()(const word &s1, const word &s2)const{
        if(s1.count != s2.count){
            return s1.count > s2.count;
        }
        else
            return s1.word < s2.word;
    }
};
typedef set<word,rule> ST;

int main(){
    MP mp;
    string s;
    while(cin >> s){
        if(s == "end")
            break;
        mp[s]++;
    }
    ST st;
    for(MP::iterator mpp = mp.begin(); mpp != mp.end(); mpp++){
        word temp;
        temp.word = mpp->first;
        temp.count = mpp->second;
        st.insert(temp);
    }

    for(ST::iterator stp = st.begin(); stp != st.end(); stp++){
        cout << stp->word << " " << stp->count << endl;
    }

    return 0;
}
