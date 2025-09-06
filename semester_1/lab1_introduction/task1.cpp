//
//  task1.cpp
//  labs
//
//  Created by Taras Zaporozhets on 4.09.25.
//
#include <iostream>
using namespace std;

int main(){
    int a,b,d;
    cout << "Введите a,b,d через пробел: ";
    cin >> a >> b >> d;
    
    for (int i = a; i <= b; i += d){
        if (i % 3 == 0){
            cout << i << ' ';
        }
    }
    
    return 0;
}

