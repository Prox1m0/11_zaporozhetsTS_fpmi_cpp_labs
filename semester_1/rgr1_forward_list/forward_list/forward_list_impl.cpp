#include "forward_list_impl.h"

ForwardList::ForwardList() : head_ (nullptr), size_(0) {}

ForwardList::ForwardList(const ForwardList& other) : head_(nullptr), size_(0) {
    Node* curr = other.head_;
    Node* prev = nullptr;
    while (curr){
        Node* new_node = new Node(curr->value_);
        if (head_){
            prev->next_ = new_node;
        }
        else{
            head_ = new_node;
        }
        curr = curr->next_;
        prev = new_node;
        ++size_;
    }
}

ForwardList::ForwardList(size_t count, int32_t value) : head_(nullptr), size_(0){
    for (size_t i = 0; i < count; ++i){
        PushFront(value);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init) : head_(nullptr), size_(0) {
    Node* tail = nullptr;
    for (int32_t value : init){
        Node* new_node = new Node(value);
        if (!head_){
            head_ = new_node;
        }
        else {
            tail->next_ = new_node;
        }
        tail = new_node;
        ++size_;
    }
}   

ForwardList& ForwardList::operator=(const ForwardList& other) {
    if (this == &other){
        return *this;
    }
    ForwardList tmp(other);
    Swap(tmp);
    return *this;
}

ForwardList::~ForwardList(){
    Clear();
}

void ForwardList::Swap(ForwardList& other){
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
}

void ForwardList::PushFront(int32_t value){
    Node* new_node = new Node(value);
    new_node->next_ = head_;
    head_ = new_node;
    ++size_;
}

void ForwardList::PopFront(){
    if (head_ == nullptr){
        throw std::out_of_range("List is already empty!\n");
    }
    Node* tmp = head_;;
    head_ = head_->next_;
    delete tmp;
    --size_;
}

void ForwardList::Remove(int32_t value){
    while (head_ && head_->value_ == value ){
        PopFront();
    }
    Node* prev = head_;
    while (prev && prev->next_){
        if (prev->next_->value_ == value){
            Node* target = prev->next_;
            prev->next_ = target->next_;
            delete target;
            --size_;
        }
        else{
            prev = prev->next_;
        }
    }
}

void ForwardList::Clear(){
    while (head_){
        Node* tmp = head_;
        head_ = head_->next_;
        delete tmp;
    }
    size_ = 0;
}

bool ForwardList::FindByValue(int32_t value){
    Node* curr = head_;
    while (curr){
        if (curr->value_ == value){
            return true;
        }
        curr = curr->next_;
    }
    return false;
}

void ForwardList::Print(std::ostream& out){
    Node* curr = head_;
    while (curr) {
        out << curr->value_;
        if (curr->next_) {
                out << " ";
        }
        curr = curr->next_;
    }
}

int32_t ForwardList::Front() const{
    if (head_ == nullptr){
        throw std::out_of_range("List is empty!\n");
    }
    return head_->value_;
}

size_t ForwardList::Size() const{
    return size_;
}