#include "ServiceException.h"

ServiceException::ServiceException(const char *msg) {
    this->message = msg;
}

const char *ServiceException::what() const noexcept {
    return this->message.c_str();
}
