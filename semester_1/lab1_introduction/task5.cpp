//
//  task5.cpp
//  labs
//
//  Created by Taras Zaporozhets on 4.09.25.
//
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (a == 0){
        return b;
    }
    return gcd(b, a % b);
}
//второй способ
int gcd_residual(int a, int b){
    while (a != b){
        if (a > b){
            a -= b;
        }
        else{
            b -= a;
        }
    }
    return a;
}

int main(){
    int n,m;
    cout << "Введите n и m: ";
    cin >> n >> m;
    cout << gcd(n, m) << "\n";
}
