#include <iostream>
#include <set>

std::set<int> eratosthen_algorithm(int n){
    std::set<int> numbers;

    for (int i = 2; i <= n; i++){
        numbers.insert(i);
    }
    for (int x = 2; x * x <= n; x++){
        if (numbers.find(x) != numbers.end()){
            for (int mult = x * x; mult <= n; mult += x){
                numbers.erase(mult);
            }
        }
    }
    return numbers;
}


int main() {
    int n;
    std::cout << "Enter N: ";
    if (!(std::cin >> n )|| n < 1){
        std::cerr << "Error! N must be natural";
        return 1;
    }
    std::set<int> primes = eratosthen_algorithm(n);
    
    std::cout << "Primes from 0 to N:\n";
    for (auto it = primes.begin(); it != primes.end(); it++){
        std::cout << *it << " ";
    }

    return 0;
}