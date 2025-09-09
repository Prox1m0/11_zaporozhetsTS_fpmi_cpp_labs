//
//  task6.cpp
//  labs
//
//  Created by Taras Zaporozhets on 6.09.25.
//
#include <iostream>

int main(){
    int n, start, sum;
    start = 1;
    sum = 0;
    
    std::cout << "Enter n: ";
    if(!(std::cin >> n) || (n < 0)){
        std::cout << "Error!\n";
        std::exit(1);
    }
    
    for (int i = 0; i < n; i++){
        sum += start;
        start += 2;
    }
    std::cout << "Sum of first n odd numbers: " << sum << '\n';
}
