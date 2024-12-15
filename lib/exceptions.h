#ifndef EXCEPTION_H
#define EXCEPTION_H
class ex {
private:
	int errorCode = 0;
	const char* errorMsg = "";
public:
	ex(const int& ErrorCode);
	ex(const char* ErrorMsg);
	ex(const int& ErrorCode = -1, const char* ErrorMessage = "");
	int getErrorCode() const;
	const char* getErrorMsg() const;
};
#endif // !EXCEPTION_H

