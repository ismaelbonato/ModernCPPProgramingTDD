#pragma once

#include <string>

class InvalidUserException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "notStartingWith@";
    }
};

class Tweet
{
    static constexpr std::string NULL_USER{"@"};
public:
    Tweet(const std::string &newMessage = "",
          const std::string &newUser = NULL_USER)
        : message(newMessage)
        , user(newUser)
    {
        if (!isValid(user)) {
            throw InvalidUserException();
        }
    }

    bool operator==(const Tweet &other) const
    {
        return message == other.message && user == other.user;
    }

    bool isValid(const std::string &user) const { return '@' == user[0]; }

private:
    std::string message;
    std::string user;
};
