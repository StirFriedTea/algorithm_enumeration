#include<iostream>
using namespace std;

int fun(int i, int k){
    if(i < k)
        return fun(i, i);
    else if(i == 0)
        return 1;
    else if(k == 0)
        return 0;
    return fun(i - k, k) + fun(i, k - 1);

}

int main(){
    int n,m;
    cin >> m >> n;
    cout << fun(m, n) << endl;
    return 0;
}
