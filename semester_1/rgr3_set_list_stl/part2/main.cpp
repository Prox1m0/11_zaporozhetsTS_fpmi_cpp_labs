#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

bool is_empty(std::ifstream& file){
    return file.peek() == EOF;
}

class Author {
    private:
        std::string last_;
        std::string first_;
        std::string middle_;
    
    public:
        Author() = default;
        Author(const std::string& last, const std::string& first, const std::string& middle) : last_(last), first_(first), middle_(middle) {}

        std::string get_full_name() const {
            return last_ + " " + first_ + " " + middle_;
        }

        bool operator<(const Author& other) const{
            if (last_ != other.last_) return last_ < other.last_;
            if (first_ != other.first_) return first_ < other.first_;
            return middle_ < other.middle_;
        }

        bool operator==(const Author& other) const {
            return this->last_ == other.last_ && this->first_ == other.first_ && this->middle_ == other.middle_;
}
};

class Book{
    private:
        int udc_;
        std::list<Author> authors_;
        std::string title_;
        int year_;
    
    public:
        Book() = default;
        Book(int udc, std::list<Author> authors, std::string title, int year) 
            : udc_(udc), authors_(authors), title_(title), year_(year) {}
        
        const int get_udc() const {
            return udc_;
        }
        const std::list<Author>& get_authors() const {
            return authors_;
        }
        const std::string get_title() const {
            return title_;
        }
        const int get_year() const {
            return year_;
        }

        bool add_author(const Author& author){
            authors_.push_back(author);
            authors_.sort(); 
            return true;
        }

        bool remove_author(const Author& a) {
            auto old = authors_.size();
            authors_.remove(a);       
            return authors_.size() != old;  
        }

        bool operator<(const Book& other) const{
            return title_ < other.title_;
        }

        void print() const {
            std::cout << title_ << " (" << year_ << "), UDC " << udc_ << "\n  Authors: ";
            bool first = true;
            for (const auto& a : authors_) {
                if (!first) std::cout << " | ";
                std::cout << a.get_full_name();
                first = false;
            }
            std::cout << "\n";
        }

        static Book parse_line(const std::string& line) {
            std::istringstream stream(line);
            std::string udc_s, authors_s, title_s, year_s;

            if (!std::getline(stream, udc_s, ';') ||
                !std::getline(stream, title_s, ';') ||
                !std::getline(stream, year_s, ';') ||
                !std::getline(stream, authors_s)) {
                throw std::runtime_error("Incorrect input!");
            }
            int udc = std::stoi(udc_s);
            int year = std::stoi(year_s);

            std::list<Author> authors;
            std::istringstream auth_stream(authors_s);
            std::string token;
            while (std::getline(auth_stream, token, '|')) {
                if (token.empty()) continue;
                std::stringstream a_stream(token);
                std::string last, first, middle;
                if (!(a_stream >> last >> first >> middle)) {
                    throw std::runtime_error("Incorrect author input!");
                }
                authors.emplace_back(last, first, middle);
            }
            authors.sort();
            return Book(udc, authors, title_s, year);
        }  
};

class Library{
    private:
        std::list<Book> books_;
    
    public:
        void insert(Book book){
            books_.push_back(std::move(book));
            books_.sort(); 
        }

        bool erase_by_title(const std::string& title){
            for (auto it = books_.begin(); it != books_.end(); ++it) {
                if (it->get_title() == title) {
                    books_.erase(it);
                    return true;
                }
            }
            return false;
        }

        std::list<Book> find_by_title(const std::string& title) const {
            std::list<Book> res;
            for (const auto& b : books_) {
                if (b.get_title() == title) res.push_back(b);
                if (b.get_title() > title) break;
            }
            return res;
        }

        std::list<Book> find_by_author(const Author& author) const {
            std::list<Book> res;
            for (const auto& b : books_) {
                for (const auto& a : b.get_authors()) {
                    if (a.get_full_name() == author.get_full_name()) res.push_back(b);
                }
            }
            return res;
        }

        bool add_author_to_book(const std::string& title, const Author& author){
            for (auto& b : books_) {
                if (b.get_title() == title) {
                    b.add_author(author);
                    return true;
                }
            }
            return false;
        }

        bool remove_author_from_book(const std::string& title, const Author& author){
            for (auto& b : books_) {
                if (b.get_title() == title) {
                    return b.remove_author(author);
                }
            }
            return false;
        }

        void print_all() const {
            for (const auto& b : books_) {
                b.print();
            }
        }
};

std::list<Book> read_books_from_file(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()){ 
        throw std::runtime_error("Cannot open file");
    }
    if (is_empty(in)){
        throw std::runtime_error("File is empty");
    }

    std::list<Book> books;
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        books.push_back(Book::parse_line(line));
    }
    return books;
}

int main() {
    const std::string filename{"books.txt"};
    Library lib;
    try {
        auto books = read_books_from_file(filename);
        for (auto& b : books){
            lib.insert(std::move(b));
        }
        std::cout << "Initial library (loaded from file):\n";
        lib.print_all();

        Book new_book = Book::parse_line("101;Test Book;2024;Neymar Santos Junior");
        lib.insert(std::move(new_book));
        std::cout << "\nAfter adding 'Test Book':\n";
        lib.print_all();

        std::cout << "\nFinding books with title 'War and Peace':\n";
        for (const auto& b : lib.find_by_title("War and Peace")) {
            b.print();
        }

        std::cout << "\nFinding books by author 'Bradbury Ray Douglas':\n";
        Author query_author{"Bradbury", "Ray", "Douglas"};
        for (const auto& b : lib.find_by_author(query_author)) {
            b.print();
        }

        std::cout << "\nAdding author 'Coauthor Test A' to 'Fahrenheit 451':\n";
        Author new_author{"Coauthor", "Test", "A"};
        bool added = lib.add_author_to_book("Fahrenheit 451", new_author);
        std::cout << (added ? "Author added\n" : "Book not found\n");
        lib.print_all();

        std::cout << "\nRemoving author 'Coauthor Test A' from 'Fahrenheit 451':\n";
        bool removed_author = lib.remove_author_from_book("Fahrenheit 451", new_author);
        std::cout << (removed_author ? "Author removed\n" : "Author or book not found\n");
        lib.print_all();

        std::cout << "\nRemoving book with title 'New_Addition':\n";
        bool removed = lib.erase_by_title("New_Addition");
        std::cout << (removed ? "Removed successfully\n" : "Book not found\n");
        std::cout << "Library after removal:\n";
        lib.print_all();

        std::cout << "\nRemoving book with title 'War and Peace':\n";
        bool removed_2 = lib.erase_by_title("War and Peace");
        std::cout << (removed_2 ? "Removed successfully\n" : "Book not found\n");
        std::cout << "Library after removal:\n";
        lib.print_all();
    }
    catch (const std::exception& e){
        std::cout << e.what() << '\n';
        return 1;
    }
    return 0;
}
