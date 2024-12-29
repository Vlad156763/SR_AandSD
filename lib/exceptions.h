#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
using std::exception;
class ex : public exception {
private:
	const char* errorMsg;
public:
	ex(const char* errorMsg) { this->errorMsg = errorMsg; }
	const char* what() const noexcept override {
		return errorMsg;
	}

};
#endif // !EXCEPTION_H

