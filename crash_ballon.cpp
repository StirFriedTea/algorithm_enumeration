#include <iostream>
#include<cstring>
using namespace std;
char orilight[5] = {0};
char result[5] ;
char light[5] ;


int getBit(char c, int i){
    return (c >> i) & 1;
}
void setBit(char& c, int i, int v){
    if(v){
        c |= (1 << i);
    }
    else
        c &= ~(1 << i);
}
void flipBit(char& c, int i){
    c ^= (1 << i);
}
void print(char* c,int n){
    cout << "puzzle #" << n << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            cout << getBit(c[i],j);
            if(j <= 4)
                cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 6; j++){
                int n;
                cin >> n;
                setBit(orilight[i],j,n);
            }
        }
        for(int n = 0; n < 64; n++){

            char switchs = n;
            memcpy(light,orilight,sizeof(orilight));
            for(int i = 0; i < 5; i++){
                result[i] = switchs;
                for(int j = 0; j < 6; j++){
                    if(getBit(switchs,j)){
                        if(j > 0){
                            flipBit(light[i ], j - 1);
                        }
                        flipBit(light[i ], j);
                        if(j < 5){
                            flipBit(light[i ], j + 1);
                        }
                        if(i < 4)
                            flipBit(light[i + 1], j);
                    }
                }
                //if(i < 4){
                //    light[i + 1] ^= switchs;
                //}
                switchs = light[i];
            }
            if(light[4] == 0){
                print(result,t + 1);
            }

        }


    }

    return 0;
}
/*
2
0 1 1 0 1 0
1 0 0 1 1 1
0 0 1 0 0 1
1 0 0 1 0 1
0 1 1 1 0 0
0 0 1 0 1 0
1 0 1 0 1 1
0 0 1 0 1 1
1 0 1 1 0 0
0 1 0 1 0 0
*/
