//
//  task9.cpp
//  labs
//
//  Created by Taras Zaporozhets on 9.09.25.
//
#include <iostream>

std::string to_reverse(int operand){
    std::string temp;
    
    temp = std::to_string(operand);
    std::reverse(temp.begin(), temp.end());
    
    return temp;
}

int main(){
    
    int a,b;
    
    std::cout << "Input a, b: ";
    
    if (!(std::cin >> a >> b)){
        std::cout << "Incorrect input!\n";
        std::exit(1);
    }
    
    for (int i = a; i <= b; i++){
        if (std::to_string(i) == to_reverse(i)){
            std::cout << i << " ";
        }
    }
    
    
}