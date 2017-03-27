#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <sddl.h>

#define SECURITY_WIN32
#include <security.h>
#include "winerrors.h"

#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "secur32.lib")

struct UserInfo {
	unsigned int 	username_size;
	char* 			username;

	unsigned int 	userdomain_size;
	char* 			userdomain;

	unsigned int	principal_sid_size;
	SID*			principal_sid;
};

char* GetSidTypeStr(SID_NAME_USE sidtype) {
	switch(sidtype) {
		case SidTypeUser:
			return "SidTypeUser";
		case SidTypeGroup:
			return "SidTypeGroup";
		case SidTypeDomain:
			return "SidTypeDomain";
		case SidTypeAlias:
			return "SidTypeAlias";
		case SidTypeWellKnownGroup:
			return "SidTypeWellKnownGroup";
		case SidTypeDeletedAccount:
			return "SidTypeDeletedAccount";
		case SidTypeInvalid:
			return "SidTypeInvalid";
		case SidTypeUnknown:
			return "SidTypeUnknown";
		case SidTypeComputer:
			return "SidTypeComputer";
		case SidTypeLabel:
			return "SidTypeLabel";
		default:
			return 0;
	}
}

/*
int GetCurrentUserAccountInfo(struct UserInfo* uinfo){
	char* rkey[3] = {"Volatile Environment", "USERNAME", "USERDOMAIN"};

	RegGetValue(HKEY_CURRENT_USER, rkey[0], rkey[1],
		RRF_RT_REG_SZ, 0, uinfo->username, &uinfo->username_size );
	RegGetValue(HKEY_CURRENT_USER, rkey[0], rkey[2], RRF_RT_REG_SZ, 0, uinfo->userdomain, &uinfo->userdomain_size);

	return 0;
}
*/

int LogOnToAdminAccount(struct UserInfo* uinfo) {
	unsigned int result = 0;
	HANDLE token;
	LogonUser("dddkgarrett", uinfo->userdomain, "CNKStone18", LOGON32_LOGON_INTERACTIVE, LOGON32_PROVIDER_WINNT50, &token);
	result = GetLastError();
	if(result != 0) {
		DefErrorHandler(result, "LogonUser", 66);
		return 1;
	}
}

int GetCurrentUserAccountInfo(struct UserInfo* uinfo) {
	unsigned char ret = 0;
	unsigned int result = 0;
	SID_NAME_USE sidtype = 0;

	//Get the username of the current user
	while( !GetUserNameExA(NameSamCompatible, uinfo->username, &uinfo->username_size) ) {
		result = GetLastError();
		if(result != ERROR_INSUFFICIENT_BUFFER && result != ERROR_MORE_DATA){
			DefErrorHandler(result, "GetUserName", 42);
			return 1;
		} 
		uinfo->username = (char*) malloc(uinfo->username_size);
	}

	//Lookup account info by username
	//uinfo->principal_sid 		= (SID*)malloc(uinfo->principal_sid_size);
	uinfo->userdomain_size 		= 0;

	if(!uinfo->principal_sid) {
		printf("Could not allocate memory for SID");
		return 1;
	}

	while( !LookupAccountName(0, uinfo->username, 
		uinfo->principal_sid, 
		&uinfo->principal_sid_size, 
		uinfo->userdomain, 
		&uinfo->userdomain_size, &sidtype) ){

		result = GetLastError();
		if(result != ERROR_INSUFFICIENT_BUFFER && result != ERROR_MORE_DATA) {
			DefErrorHandler(result, "LookupAccountName", 55);
			return 1;
		}

		uinfo->principal_sid 	= (SID*)malloc(uinfo->principal_sid_size);
		uinfo->userdomain 		= (char*)malloc(uinfo->userdomain_size);
	}

	

/*
	char* sidstr = malloc(uinfo->principal_sid_size);
	ConvertSidToStringSidA(uinfo->principal_sid, &sidstr);
	printf("user sid is : %s\n", sidstr);
	printf("user account type is : %s\n", GetSidTypeStr(sidtype));
*/

	return 0;
}

int main (int argc, char** argv) {
	struct UserInfo uinfo;
	SID_NAME_USE sidtype = SidTypeUser;

	uinfo.username_size = 0;
	char* sidstr;

	GetCurrentUserAccountInfo(&uinfo);
	LogOnToAdminAccount(&uinfo);


/*
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
*/
	return 0;
}
