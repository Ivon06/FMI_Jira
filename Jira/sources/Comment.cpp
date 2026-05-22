#include "../headers/Comment.h"

Comment::Comment(unsigned int authorId,
    const std::string& content)
    : authorId(authorId),
    content(content),
    createdAt(std::time(nullptr)) {
}

Comment::Comment(unsigned int authorId,
    const std::string& content,
    std::time_t createdAt)
    : authorId(authorId),
    content(content),
    createdAt(createdAt) {
}

unsigned int Comment::getAuthorId() const {
    return authorId;
}

const std::string& Comment::getContent() const {
    return content;
}

std::time_t Comment::getCreatedAt() const {
    return createdAt;
}

void Comment::serialize(std::ostream& os) const {

    os << authorId << '\n'
        << content << '\n'
        << createdAt << '\n';
}

void Comment::print(std::ostream& os) const {

    os << "Author ID: "
        << authorId
        << '\n';

    os << "Content: "
        << content
        << '\n';

    os << "Created at: "
        << std::ctime(&createdAt);
}

std::ostream& operator<<(std::ostream& os,
    const Comment& comment) {

    comment.print(os);

    return os;
}