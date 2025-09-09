//
//  task5.cpp
//  labs
//
//  Created by Taras Zaporozhets on 9.09.25.
//
#include <iostream>

int main(){
    int n, m, min, max;
    
    std::cout << "Enter n и m: ";
    if(!(std::cin >> n >> m)){
        std::cout << "Error!\n";
        std::exit(1);
    }
    
    if (n < m){
        min = n;
        max = m;
    }
    else{
        min = m;
        max = n;
    }
    for (int i = 1; i <= min; i++){
        if ((min % i == 0) && (max % i == 0)){
            std::cout << i << '\n';
        }
    }
}
