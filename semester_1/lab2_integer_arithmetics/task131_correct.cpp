//
//  correct_task.cpp
//  labs
//
//  Created by Taras Zaporozhets on 16.09.25.
//


 #include <iostream>

void TryRead(int& number){
    if (!(std::cin >> number)){
        std::cout << "Fail on reading the number\n";
        exit(0);
    }
}

bool IsNotNegative(int number){
    return number >= 0;
}

int main(){
    int number;
    
    std::cout << "Enter the number: ";
    TryRead(number);

    
    if (IsNotNegative(number) == 1){
        std::cout << "Number is >= 0 \nTry again....\n";
        
    } else {
        std::cout << "Number is negative\n";
    }
    
    return 0;
}