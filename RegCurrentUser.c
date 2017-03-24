#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "winerrors.h"

#pragma comment(lib, "advapi32.lib")

int main(int argc, char** argv) {
	HKEY hkey = NULL;

	//char buf[80] = {0};
	char* error = 0;
	char buf[80] = {0};
	DWORD type = REG_SZ;
	DWORD count = 80;
	LONG ret = 0;
	
	ret = RegOpenCurrentUser(0, &hkey);
	if(!ERROR_SUCCESS == ret) {
		GetWinError(ret, &error);
		printf("RegOpenCurrentUser Error: %s\n", error);
		return 1;
	}

	ret = RegGetValue(HKEY_CURRENT_USER, "Volatile Environment", "USERNAME", RRF_RT_ANY, 0, (void*)buf, &count);
	if(!(ERROR_SUCCESS == ret)){
		GetWinError(ret, &error);
		printf("RegGetValue Error: %s(%d)\n", error, ret);
		return 1;
	}

	printf(buf);
	return 0;
}
