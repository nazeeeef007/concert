#include "User.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    User user1(1, "naz", "naz@gmail.com");
    User user2(2, "han", "han@gmail.com");
    std::unordered_map<User, int, User::UserHash> m;
    m[user1] = 1;
    m[user2] = 2;
    std::cout << m.count(user1) << "\n";
    return 0;
}