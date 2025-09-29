#include <iostream>

bool is_palindrome(int x){

    if (x < 0){
        return false;
    }

    int original = x;
    int reversed_x = 0;

    while (x > 0){
        reversed_x = reversed_x * 10 + x % 10;
        x /= 10;
    }
    
    return original == reversed_x;
}

int main(){

    int a,b;

    std::cout << "Enter a, b: ";
    if(!(std::cin >> a >> b)){     
        std::cout << "Error!";
        std::exit(1);
    }

     if (a > b) {
        std::cout << "Error: a should be less or equal to b";
        std::exit(1);
    }

    for (int i = a; i <= b; i++){
        if (is_palindrome(i)){
            std::cout << i << ' ';
        }

    }

}