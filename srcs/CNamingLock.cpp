#include "CNamingLock.h"
#include <stdio.h>

#define MUTEX_NAME "03770ef5-5c5f-4a90-a169-a0997c9aaad4"

static HANDLE create_and_open_mutex()
{
    HANDLE hMutex; 

    hMutex = CreateMutex( 
        NULL,                        // default security descriptor
        FALSE,                       // mutex not owned
        TEXT(MUTEX_NAME));  // object name
    if ( hMutex != NULL && GetLastError() == ERROR_ALREADY_EXISTS ) 
    {
        CloseHandle(hMutex);

        hMutex = OpenMutex( 
            MUTEX_ALL_ACCESS,            // request full access
            FALSE,                       // handle not inheritable
            TEXT(MUTEX_NAME));  // object name

        if (hMutex == NULL) 
            printf("OpenMutex error: %d\n", GetLastError() );            
    }
    else if(hMutex == NULL)
    {
        printf("CreateMutex error: %d\n", GetLastError() );
    }

     return hMutex;
}

HANDLE get_naming_mutex()
{
    static HANDLE hMutex = create_and_open_mutex();

    return hMutex;
}

void acquire_access()
{
    WaitForSingleObject(get_naming_mutex(), INFINITE);
}

void release_access()
{
    ReleaseMutex(get_naming_mutex());
}

CNamingLock::CNamingLock()
{
    acquire_access();
}

CNamingLock::~CNamingLock()
{
    release_access();
}