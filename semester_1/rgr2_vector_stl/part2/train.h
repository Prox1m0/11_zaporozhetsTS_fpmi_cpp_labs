#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "time_utility.h"

using TrainId = size_t;
using namespace time_utility;


enum class TrainType { 
    PASSENGER, FREIGHT, HIGH_SPEED, SUBWAY, SPECIALIZED
};


class Train {
private:
    TrainId id_;
    TrainType type_;
    std::string destination_;
    std::time_t dispatch_time_;
    std::time_t travelling_time_;

public:
    // your code goes here
    Train() : id_(0), type_(TrainType::PASSENGER), destination_(""), dispatch_time_(0), travelling_time_(0) {}
    
    Train(TrainId id, TrainType type, const std::string& destination, std::time_t dispatch_time, std::time_t travelling_time)
        : id_(id), type_(type), destination_(destination), dispatch_time_(dispatch_time), travelling_time_(travelling_time) {}
    
    Train(const Train& other) 
        : id_(other.id_), type_(other.type_), destination_(other.destination_), dispatch_time_(other.dispatch_time_), travelling_time_(other.travelling_time_) {}

    std::time_t get_dispatch_time() const {
        return dispatch_time_;
    }
    
    std::time_t get_travelling_time() const {
        return travelling_time_;
    }

    std::string get_destination() const {
        return destination_;
    }

    TrainId get_id() const {
        return id_;
    }

    TrainType get_type() const {
        return type_;
    }
    //предполагается, что тип поезда предеается в файле числом от 0 до 4
    static Train from_string(const std::string& str){
        std::istringstream stream{str};
        TrainId id; 
        int type; 
        std::string destination; 
        std::string dispatch_time_str; 
        std::string travelling_time_str;

        if (!(stream >> id >> type >> destination >> dispatch_time_str >> travelling_time_str)){
            throw std::invalid_argument("Invalid input format");
        }
        if (type < 0 || type > 4){
            throw std::invalid_argument("Invalid train type");
        }
        TrainType train_type = static_cast<TrainType>(type);

        size_t dots_pos = dispatch_time_str.find(':'); 
        if (dots_pos == std::string::npos || dots_pos == 0 || dots_pos == dispatch_time_str.size() - 1){
            throw std::invalid_argument("Invalid dispatch time format");
        }
        int dispatch_hours = std::stoi(dispatch_time_str.substr(0, dots_pos));
        int dispatch_minutes = std::stoi(dispatch_time_str.substr(dots_pos + 1));
        std::time_t dispatch_time = SetTime(dispatch_hours, dispatch_minutes);

        dots_pos = travelling_time_str.find(':');
        if (dots_pos == std::string::npos || dots_pos == 0 || dots_pos == travelling_time_str.size() - 1){
            throw std::invalid_argument("Invalid travelling time format");
        }
        int travelling_hours = std::stoi(travelling_time_str.substr(0, dots_pos));
        int travelling_minutes = std::stoi(travelling_time_str.substr(dots_pos + 1));
        std::time_t travelling_time = SetTime(travelling_hours, travelling_minutes);
        
        return Train(id, train_type, destination, dispatch_time, travelling_time);
    }

    void print() const{
        std::string type_str; 
        if (type_ == TrainType::PASSENGER) type_str = "PASSENGER";
        if (type_ == TrainType::FREIGHT) type_str = "FREIGHT";
        if (type_ == TrainType::HIGH_SPEED) type_str = "HIGH_SPEED";
        if (type_ == TrainType::SUBWAY) type_str = "SUBWAY";
        if (type_ == TrainType::SPECIALIZED) type_str = "SPECIALIZED";

        std::cout << "Train №: " << id_ << '\n';
        std::cout << "\tType: " << type_str << '\n';
        std::cout << "\tDestination: " << destination_ << '\n';
        std::cout << "\tDispatch time: ";
        PrintTime(dispatch_time_);
        std::cout << "\n\tTravelling time: ";
        PrintTime(travelling_time_);
    }   

    bool operator<(const Train& other) const {
        return dispatch_time_ < other.dispatch_time_;
    }
};
