#include "ValidatorException.h"

ValidatorException::ValidatorException(const char *msg) {
    this->message = msg;
}

const char *ValidatorException::what() const noexcept {
    return this->message.c_str();
}