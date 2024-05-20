#include <CNamingLock.h>
#include <stdio.h>
#include <time.h>
#include <string>

std::string get_current_local_time() 
{
	char       buf[80];

	struct tm tstruct;
	time_t now = time(0);
	localtime_s(&tstruct, &now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d_%X", &tstruct);

	return buf;
}

int main()
{
    int count = 0;
    while (TRUE)
    {
        CNamingLock lock;

        Sleep(1000);

        printf_s("[%s] count: %d.\n", get_current_local_time().c_str(), count++);
    }

    return 0;
}