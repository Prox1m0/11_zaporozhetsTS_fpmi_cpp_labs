#include "time_utility.h"
#include "train.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <climits>

bool is_empty(std::ifstream& file){
    return file.peek() == EOF;
}

void read_trains(const std::string& filename, std::vector<Train>& trains){
    std::ifstream in{filename};
    std::string line;
    if (!in.is_open()){
        throw std::runtime_error("File not found");
    }
    if (is_empty(in)){
        throw std::runtime_error("File is empty");
    }
    while(std::getline(in, line)){
        if (!line.empty()){
            try {
                Train train = Train::from_string(line);
                trains.push_back(train);
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
    }
    in.close();
}

void sort_by_dispatch_time(std::vector<Train>& trains){
    std::sort(trains.begin(), trains.end());
}



void get_by_time_range(const std::vector<Train>& trains, std::time_t start, std::time_t end){
    for (const auto& train : trains){
        std::time_t dispatch_time = train.get_dispatch_time();
        if (dispatch_time >= start && dispatch_time <= end){
            train.print();
            std::cout << '\n';
        }
    }
}

void get_by_destination(const std::vector<Train>& trains, const std::string& destination){
    for (const auto& train : trains){
        if (train.get_destination() == destination){
            train.print();
            std::cout << '\n';
        }
    }
}

void get_by_type_and_destination(const std::vector<Train>& trains, TrainType type, const std::string& destination){
    for (const auto& train : trains){
        if (train.get_type() == type && train.get_destination() == destination){
            train.print();
            std::cout << '\n';
        }
    }
}

void get_fastest_to_destination(const std::vector<Train>& trains, const std::string& destination){
    const Train* fastest = nullptr;
    std::time_t min_duration = INT_MAX;
    
    for (const auto& train : trains){
        if (train.get_destination() == destination){
            std::time_t duration = train.get_travelling_time();
            if (duration < min_duration){
                min_duration = duration;
                fastest = &train;
            }
        }
    }
    if (fastest != nullptr){
        fastest->print();
    }
    else {
        std::cout << "No trains found\n";
    }
}

void print_trains(const std::vector<Train>& trains){
    for (const auto& train : trains){
        train.print();
        std::cout << '\n';
    }
}

int main() {
    const std::string filename{"trains.txt"};
    std::vector<Train> trains;

    std::string dest_1 = "Baranovichi";
    std::string dest_2 = "Minsk";
    std::time_t time_1 = time_utility::SetTime(10, 0);
    std::time_t time_2 = time_utility::SetTime(15, 0);
    std::string type_str = "PASSENGER";

    try{
        read_trains(filename, trains);
        std::cout << "1. Trains list:\n";
        print_trains(trains);
        std::cout << "\n2. Trains sorted by dispatch time:\n";
        sort_by_dispatch_time(trains);
        print_trains(trains);
        
        std::cout << "\n3. Trains by time range (from ";
        PrintTime(time_1);
        std::cout << " to ";
        PrintTime(time_2);
        std::cout << "):\n";
        get_by_time_range(trains, time_1, time_2);
        
        std::cout << "\n4. Trains to destination (" << dest_1 << "):\n";
        get_by_destination(trains, dest_1);

        std::cout << "\n5. Trains by type (" << type_str << ") and destination (" << dest_2 << "):\n";
        get_by_type_and_destination(trains, TrainType::PASSENGER, dest_2);

        std::cout << "\n6. Fastest train to destination (" << dest_1 << "):\n";
        get_fastest_to_destination(trains, dest_1);
    }
    catch (const std::exception& e){
        std::cout << e.what() << '\n';
        return 1;
    }
    return 0;
}
