#include "RepositoryException.h"

RepositoryException::RepositoryException(const char *msg) {
    this->message = msg;
}

const char *RepositoryException::what() const noexcept {
    return this->message.c_str();
}
