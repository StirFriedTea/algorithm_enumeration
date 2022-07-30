//输入很多行单词，统计每个单词的数量并以此排序，出现次数一样多时，按照字典序排列。
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;

struct StudentInfo{
    int StuId;
    string name;
};
struct student{
    int score;
    StudentInfo studentinfo;
};


typedef multimap<int, StudentInfo> Stu;
int main(){
    Stu stu;
    char c[20];
    while(cin >> c){
        if(c[0] == 'A') {
            int score;
            StudentInfo studentinfo;
            cin >> studentinfo.name >> studentinfo.StuId >> score;
            stu.insert(make_pair(score,studentinfo));
        }
        if(c[0] == 'Q'){
            int score;
            cin >> score;
            Stu::iterator p = stu.lower_bound(score);
            if(p != stu.begin()){
                p--;
                int max_score = p->first;
                int max_Id = p->second.StuId;
                string name = p->second.name;
                for(; p != stu.begin() && p->first == max_score ;p--){
                    if(max_Id < p->second.StuId){
                        max_Id = p->second.StuId;
                        name = p->second.name;
                    }
                }
                if(p == stu.begin()){
                    if(max_Id < p->second.StuId){
                        max_Id = p->second.StuId;
                        name = p->second.name;
                    }
                }
                cout<< name << " " << max_Id << " " << max_score << endl;
            }
            else
                cout<< "Nobody"<<endl;

        }


    }

    return 0;
}
