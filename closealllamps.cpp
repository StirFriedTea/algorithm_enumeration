#include<iostream>
#include<string>
using namespace std;

int GetBit(char c, int i){
    return (c >> i) & 1;
}

void SetBit(char &c, int i, int flag){
    if(flag)
        c |= (1 << i);
    else
        c &= ~(1 << i);
}

void Flip(char &c, int i){
    c ^=  (1 << i);
}

int main(){
    char orilights[5];
    char lights[5];
    char results[5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++){
            int binary;
            cin >> binary;
            SetBit(orilights[i], j, binary);
        }
    for(int n = 0; n < 32; n++){
        memcpy(lights, orilights, sizeof(orilights));
        char deal = n;
        for(int i = 0; i < 5; i++){
            results[i] = deal;
            for(int j = 0; j < 5; j++)
                if(GetBit(results[i], j)){
                    Flip(lights[i], j);
                    if(j > 0)
                        Flip(lights[i ], j - 1);
                    if(j < 5)
                        Flip(lights[i ], j + 1);
                    if(i < 4)
                        Flip(lights[i + 1], j);
                }
            deal = lights[i];
        }
        if(lights[4] == 0){
            for(int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    cout << GetBit(results[i], j) ;
                    if(j != 4)
                        cout <<  " ";
                }
                cout << endl;
            }
        }
    }

}
/*

   1 0 1 1 0
   0 1 1 0 0
   1 1 1 0 0
   0 0 1 0 1
   1 0 1 0 1


*/
