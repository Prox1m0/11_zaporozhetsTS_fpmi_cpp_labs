#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool is_empty(std::ifstream& file){
    return file.peek() == EOF;
}

std::string get_symbols(){
    std::string symbols;
    std::cout << "Enter symbols: ";
    if (!(std::cin >> symbols)){
        std::cin.clear();
        std::cin.ignore();
        throw ("Error! Cannot read data!");
    }
    return symbols;
}

int process_line(const std::string& line, const std::string& symbols){
    int count = 0;
    int max = 0;
    for (size_t i = 0; i < line.size(); ++i){
        if (symbols.find(line[i]) != std::string::npos){
            count++;
            max = std::max(max, count);
        } else {
            count = 0;
        }
    }
    return max;
}


std::vector<std::string> read_lines_from_file(const std::string& filename){
    std::ifstream in{filename};
    
    if (!in.is_open()){
        throw ("Error! Cannot open file!");
    }
    if (is_empty(in)){
        throw ("File is empty!");
    }
    std::vector<std::string> lines;
    std::string line; 
    while (getline(in, line)){
        lines.push_back(line);
    }
    in.close();
    return lines;
}

int find_max_length(const std::vector<std::string>& lines, const std::string& symbols){
    int max = 0;
    for (size_t i = 0; i < lines.size(); ++i){
        int curr_length = process_line(lines[i], symbols);
        if (curr_length > max){
            max = curr_length;
        }
    }
    return max;
}

std::vector<std::string> find_lines_with_max_length(const std::vector<std::string>& lines, const std::string& syms, int max_length){
    std::vector<std::string> res;
    int count = 0;
    for (size_t i = 0; i < lines.size(); ++i){
        int curr_length = process_line(lines[i], syms);
        if (curr_length == max_length){
            if (count >= 10){
                return res;
            } else{
                count++;
                res.push_back(lines[i]);
            }
        }
    }
    return res;
}

void print_result(const std::vector<std::string>& lines, const int& max){
    std::cout << "Max length: " << max << '\n';
    std::cout << "Result: " << '\n';
    for (size_t i = 0; i < lines.size(); ++i){
        std::cout << i + 1 << ". " <<  lines[i] << '\n';
    }
}

int main(){
    const std::string filename{"input.txt"};
    try {
        std::string symbols = get_symbols();
        std::vector<std::string> lines = read_lines_from_file(filename);
        int max_length = find_max_length(lines, symbols);
        if (max_length == 0){
            throw ("No lines with such symbols!");
        }
        std::vector<std::string> result = find_lines_with_max_length(lines, symbols, max_length);
        print_result(result, max_length);
    }
    catch (const char* msg){
        std::cout << msg << '\n';
    }
    return 0;
}