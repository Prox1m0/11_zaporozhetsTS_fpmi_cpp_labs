//
//  task10.cpp
//  labs
//
//  Created by Taras Zaporozhets on 4.09.25.
//
#include <iostream>

int main(){
    int n, sum1, sum2, half;
    sum1 = 0;
    sum2 = 0;
    
    std::cout << "Enter 6-digits number: ";
    std::cin >> n;
    
    if (std::to_string(n).length() != 6){
        std::cout << "Error!\n";
        std::exit(1);
    }
    
    half = n / 1000;
    for (int i = 0; i < 3; i++){
        sum1 += half % 10;
        sum2 += n % 10;
        
        half  /= 10;
        n /= 10;
    }
    if (sum1 == sum2){
        std::cout << "Lucky number" << "\n";
    }
    else{
        std::cout << "Unlucky number" << "\n";
    }
}

