#pragma once

#include <string>

class Tweet
{
public:
    Tweet() = default;
    Tweet(const std::string& newMessage, const std::string& newUser)
        : message(newMessage), user(newUser)
    {
    }

    bool operator==(const Tweet& other) const
    {
        return message == other.message && user == other.user;
    }
private:
    std::string message;
    std::string user;
};