#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

double expression_value();
double term_value();
double factor_value();

int main(){

    cout<< expression_value()<< endl;
    return 0;
}

double expression_value(){
    double result = term_value();
    bool flag = 1;
    while(flag){
        char c = cin.peek();
        if(c == '+' || c == '-'){
            cin.get();
            if(c == '+')
                result += term_value();
            if(c == '-')
                result -= term_value();
        }
        else
            flag = 0;
    }
    return result;

}
double term_value(){
    double result = factor_value();
    bool flag = 1;
    while(flag){
        char c = cin.peek();
        if(c == '*' || c == '/'){
            cin.get();
            if(c == '*')
                result *= factor_value();
            if(c == '/')
                result /= factor_value();
        }
        else
            flag = 0;
    }
    return result;
}
double factor_value(){
    char c = cin.peek();
    double result = 0;
    bool isinteger = 1;
    int demicalplaces = 0;
    if(c == '('){
        cin.get();
        result += expression_value();
        cin.get();
    }

    else if(isdigit(c)){
        bool flag = 1;
        while(flag){
            if(isdigit(c) && isinteger){
                result = result * 10 + c - '0';
                cin.get();
                c = cin.peek();
            }
            else if(c == '.'){
                isinteger = 0;
                cin.get();
                c = cin.peek();
            }
            else if(isdigit(c) && !isinteger){
                result += pow(0.1, ++demicalplaces) * (c - '0');
                cin.get();
                c = cin.peek();
            }
            else
                flag = 0;
        }
    }



    return result;

}
