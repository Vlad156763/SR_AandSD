#include "exceptions.h"
ex::ex(const int& errorCode, const char* errorMsg) : errorCode(errorCode), errorMsg(errorMsg) {}
ex::ex(const char* errorMsg) : errorMsg(errorMsg) {}
ex::ex(const int& errorCode) : errorMsg(errorMsg) {}

int ex::getErrorCode() const { return this->errorCode; }
const char* ex::getErrorMsg() const { return this->errorMsg; }