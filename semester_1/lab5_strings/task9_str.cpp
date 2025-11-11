//
//  task9_str.cpp
//  labs
//
//  Created by Taras Zaporozhets on 5.11.25.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <exception>

void read_string(std::string& str){
    if(!std::getline(std::cin, str)){
        throw std::runtime_error("Input error");
    }
    if (str.empty()){
        throw std::invalid_argument("Empty string given");
    }
}

bool is_lower_vowel(char ch){
    if (ch < 'a' || ch > 'z') return false;
    
    std::string lower_vowels{"aeiouy"};
    return lower_vowels.find(ch) != std::string::npos;
}

void spaces_to_pluses(std::string& str){
    for (size_t i = 0; i < str.size(); ++i){
        if (std::isspace(static_cast<unsigned char>(str[i]))){
            str[i] = '+';
        }
    }
}

void toupper_vowels(std::string& str){
    for (size_t i = 0; i < str.size(); ++i){
        if (is_lower_vowel(str[i])){
            str[i] = std::toupper(str[i]);
        }
    }
}

std::vector<std::string> split_string(const std::string& str){
    
    std::vector<std::string> words;
    size_t left = 0, right = 0;

    while (left < str.length()){
        left = str.find_first_not_of('+', right);
        if (left == std::string::npos) break;

        right = str.find_first_of('+', left);
        if (right == std::string::npos){
            right = str.length();
        }
        words.push_back(str.substr(left, right - left));
    }
    std::sort(words.begin(), words.end());
    return words;
}

void join_string(std::string& str, const std::vector<std::string>& words){
    if (words.empty()){
        return;
    }
   
    str.clear();    
    for (size_t i = 0; i < words.size(); ++i){
        if (i > 0){
            str += '+';
        }
        str += words[i];
    }
}

void print_string(const std::string& str){
    std::cout << str << '\n';
}

void transform_string(std::string& str){
    toupper_vowels(str);
    spaces_to_pluses(str);
    std::cout << "String with leading/plural spaces(pluses): ";
    print_string(str);
    join_string(str, split_string(str));
}

int main(){
    std::string s;
    
    try {
        std::cout << "Enter the string: ";
        read_string(s);

        std::cout << "Your string before operations: ";
        print_string(s);
        transform_string(s);
        std::cout << "After operations (w/o leading/plural spaces(pluses)): ";
        print_string(s);
    }
    catch (const std::runtime_error& e){
        std::cout << e.what() << '\n';
        return 1;
    }
    catch (const std::invalid_argument& e){
        std::cout << e.what() << '\n';
        return 1;
    }
    catch (...){
        std::cout << "Unknown error!" << '\n';
        return 1;
    }
    return 0;
}