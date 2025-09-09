//
//  task1.cpp
//  labs
//
//  Created by Taras Zaporozhets on 4.09.25.
//
#include <iostream>

int main(){

    int a,b,d;
    std::cout << "Enter a,b,d: ";
    if (!(std::cin >> a >> b >> d)){
        std::cout << "Error! Must be integer \n";
        std::exit(1);
    }
    
    if ((b > a) && (d >= 0)){
        for (int i = a; i <= b; i += d){
            if (i % 3 == 0){
                std::cout << i << ' ';
            }
        }
    }
    else if ((a > b) && (d <= 0)){
        for (int i = a; i >= b; i += d){
            if (i % 3 == 0){
                std::cout << i << ' ';
            }
        }
    }
    
    else{
        std::cout << "Incorrect input!\n";
        std::exit(1);
    }
    return 0;
}

