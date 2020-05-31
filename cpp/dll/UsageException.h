#ifndef _USAGEEXCEPTION_H
#define _USAGEEXCEPTION_H
using namespace std;

typedef enum{
	STATE_OK,
	MINUS_NUMBER,
	LENGTH_OVER,
}ERROR_TYPE;

class UsageException
{
private:
	int num;
	ERROR_TYPE err;
public:
	UsageException(ERROR_TYPE err):err(err)
	{ }
	void ShowErrorInfo()
	{
		if(err == MINUS_NUMBER)
			cout << "!! number is minus" << endl;
		else if(err == LENGTH_OVER)
			cout << "!! string length is over" << endl;
	}
};
#endif
