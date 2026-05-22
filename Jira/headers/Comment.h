#pragma once
#include <string>
#include <ctime>
#include <iostream>

class Comment {
private:
    unsigned int authorId;
    std::string content;
    std::time_t createdAt;

    void print(std::ostream& os) const;

public:
    Comment(unsigned int authorId,
        const std::string& content);

    Comment(unsigned int authorId,
        const std::string& content,
        std::time_t createdAt);

    unsigned int getAuthorId() const;

    const std::string& getContent() const;

    std::time_t getCreatedAt() const;

    void serialize(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os,
        const Comment& comment);
};