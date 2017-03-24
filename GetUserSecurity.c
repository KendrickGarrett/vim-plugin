#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <sddl.h>
#include "winerrors.h"

#pragma comment(lib, "advapi32.lib")

struct UserInfo {
	char* username;
	char* userdomain;
	char* logonserver;
	unsigned int userdomain_size;
	unsigned int username_size;
};

int GetCurrentUserAccountInfo(struct UserInfo* uinfo){
	char* rkey[3] = {"Volatile Environment", "USERNAME", "USERDOMAIN"};

	RegGetValue(HKEY_CURRENT_USER, rkey[0], rkey[1],
		RRF_RT_REG_SZ, 0, uinfo->username, &uinfo->username_size );
	RegGetValue(HKEY_CURRENT_USER, rkey[0], rkey[2], RRF_RT_REG_SZ, 0, uinfo->userdomain, &uinfo->userdomain_size);

	return 0;
}

int main (int argc, char** argv) {
	struct UserInfo uinfo;
	uinfo.userdomain = NULL;	
	SID sid;
	DWORD sid_size = 28;
	BOOL ret;
	char* error = 0;
	SID_NAME_USE sidtype = SidTypeUser;

	uinfo.username_size = 80;
	uinfo.username = malloc(uinfo.username_size);
	SecureZeroMemory(uinfo.username, uinfo.username_size);

	uinfo.userdomain_size = 14;
	uinfo.userdomain = malloc(uinfo.userdomain_size);
	SecureZeroMemory(uinfo.userdomain, uinfo.userdomain_size);

	char* sidstr;
	char userdomain[14];

	GetCurrentUserAccountInfo(&uinfo);

	//Lookup account info by username	
	ret = LookupAccountName(0, uinfo.username, &sid, &sid_size, userdomain, &uinfo.userdomain_size, &sidtype);

	if(!ret) {
		DefErrorHandler(GetLastError(), "LookupAccountName");
		printf("Required SID size = %d\n", sid_size);
		printf("Required Domain size = %d\n", uinfo.userdomain_size);
		return 1;
	}

	ret = ConvertSidToStringSidA(&sid, &sidstr);
	if(!ret) {
		DefErrorHandler(GetLastError(), "ConvertSidToStringSidA");
		return 1;
	}
	
	HANDLE hProcess = 0;
	HANDLE hToken = 0;
	hProcess = GetCurrentProcess();

	if(!OpenProcessToken(hProcess, TOKEN_ALL_ACCESS, &hToken )) {
		DefErrorHandler(GetLastError(), "OpenProcessToken");
		return 1;
	}

	TOKEN_PRIVILEGES structTokenPrivileges[4];
	SecureZeroMemory(structTokenPrivileges, sizeof(structTokenPrivileges));
	DWORD priv_size;
	ret = GetTokenInformation(hToken, TokenPrivileges, structTokenPrivileges, sizeof(structTokenPrivileges), &priv_size);
	
	if(!ret) {
		printf("Privilege count: %d\n", structTokenPrivileges->PrivilegeCount);
		printf("Bytes in: %d\nBytes out: %d\n", sizeof(structTokenPrivileges), priv_size);
		DefErrorHandler(GetLastError(), "GetTokenInformation");
		return 1;
	}

	#define LUID_NAME_SIZE 80
	DWORD luidname_size = LUID_NAME_SIZE  ;
	char luidname[LUID_NAME_SIZE] ; 
	int i = 0;
	while(structTokenPrivileges->PrivilegeCount--) {
		LookupPrivilegeNameA(0, &structTokenPrivileges->Privileges[i].Luid, luidname, &luidname_size);
		printf("Luid %d name is %s\n", i, luidname);
		i++;
	}

	//printf("Username: %s\nUserdomain: %s\n", uinfo.username, uinfo.userdomain);
	//printf(sidstr);

	//printf("%s\\%s\n", uinfo.userdomain, uinfo.username);
	return 0;
}
