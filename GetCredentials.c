#include <windows.h>
#include <WinCred.h>
#include <stdio.h>
#include "winerrors.h"

#pragma comment(lib, "Credui.lib")

int main (int argc, char** argv) {
	DWORD result = 0;
	char username[CREDUI_MAX_USERNAME_LENGTH+1] = {0};
	char password[CREDUI_MAX_PASSWORD_LENGTH+1] = {0};
	BOOL save = 0;
	char* logonserver = "TXDAL01053";
	struct _CREDUI_INFOA credui_info;
	char* error = NULL;

	credui_info.cbSize = sizeof(credui_info);
	credui_info.hwndParent = NULL;
	credui_info.pszMessageText = "Message Text";
	credui_info.pszCaptionText = "Caption";
	credui_info.hbmBanner = NULL;

	result = CredUIPromptForWindowsCredentialsA(&credui_info, 0, 0, 0, 
		username, CREDUI_MAX_USERNAME_LENGTH+1, 
		password, CREDUI_MAX_PASSWORD_LENGTH+1, 
		NULL, 
		CREDUIWIN_GENERIC
	);
	
	GetWinError(result, &error);
	printf("Error: %s (%d)\n", error, result);

	return 0;
}
