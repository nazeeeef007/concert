#pragma once

#include <string>
#include <iostream>
#include <functional>

class User {
private:
    int id;
    std::string name;
    std::string email;

public:
    User(int id, std::string name, std::string email)
        : id(id), name(name), email(email) {}
    
    User() : id(0), name(""), email("") {}

    ~User() {
        std::cout << "Destroying User " << id << "\n";
    };

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    bool operator<(const User & other) const {
        return id < other.id;
    }

    bool operator==(const User & other) const {
        return id == other.id;
    }

    static bool compareByNameAscending(const User & a, const User & b) {
        return a.getName() < b.getName();
    }

    static bool compareByNameDescending(const User & a, const User & b) {
        return a.getName() > b.getName();
    }
    
    struct UserHash {
        size_t operator()(const User & user) const {
            return std::hash<int>()(user.getId());
        }
    };

};

// namespace std {
//     template <>
//     struct hash<User> {
//         size_t operator()(const User & user) const {
//             return hash<int>()(user.getId());
//         }
//     };
// }
