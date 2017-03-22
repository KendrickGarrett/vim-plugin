#include "winerrors.h"
#include <stdio.h>

void DefErrorHandler(int, char*);
void GetWinError(unsigned long, char**);

void DefErrorHandler(int err_code, char* fn_name) {
	char* err_name = 0;
	//int err_code = GetLastError();
	GetWinError(err_code, &err_name);
	printf("Error in function %s: %s (Code: %d)\n", fn_name, err_name, err_code);
}

void GetWinError (unsigned long errcode, char** name) {
	switch (errcode) {
		case ERROR_SUCCESS: 										//0x00000000
		*name = "ERROR_SUCCESS";
		//The operation completed successfully
		break;
		case ERROR_INVALID_FUNCTION: 								//0x00000001
		*name = "ERROR_INVALID_FUNCTION";
		//Incorrect Function
		break;
		case ERROR_FILE_NOT_FOUND:									//0x00000002
		*name = "ERROR_FILE_NOT_FOUND";
		//The system cannot find the specified file
		break;
		case ERROR_PATH_NOT_FOUND:									//0x00000003
		*name = "ERROR_PATH_NOT_FOUND";
		//The system cannot find the specified path
		break;
		case ERROR_TOO_MANY_OPEN_FILES:								//0x00000004
		*name = "ERROR_TOO_MANY_OPEN_FILES";
		//The system cannot open the file
		break;
		case ERROR_ACCESS_DENIED:									//0x00000005
		*name = "ERROR_ACCESS_DENIED";
		//Access is denied
		break;
		case ERROR_INVALID_HANDLE:									//0x00000006
		*name = "ERROR_INVALID_HANDLE";
		//The handle is invalid
		break;
		case ERROR_ARENA_TRASHED:									//0x00000007
		*name = "ERROR_ARENA_TRASHED";
		//The storage control blocks were destroyed
		break;
		case ERROR_NOT_ENOUGH_MEMORY:								//0x00000008
		*name = "ERROR_NOT_ENOUGH_MEMORY";
		//Not enough storage is available to process this command
		break;
		case ERROR_INVALID_BLOCK:									//0x00000009
		*name = "ERROR_INVALID_BLOCK";
		//The storage control block address is invalid
		break;
		case ERROR_BAD_ENVIRONMENT:									//0x0000000A
		*name = "ERROR_BAD_ENVIRONMENT";
		//The environment is bad
		break;
		case ERROR_BAD_FORMAT:										//0x0000000B
		*name = "ERROR_BAD_FORMAT";
		//An attempt was made to load a program with an incorrect format
		break;
		case ERROR_INVALID_ACCESS:									//0x0000000C
		*name = "ERROR_INVALID_ACCESS";
		break;
		case ERROR_INVALID_DATA:									//0x0000000D
		*name = "ERROR_INVALID_DATA";
		break;
		case ERROR_OUTOFMEMORY:										//0x0000000E
		*name = "ERROR_OUTOFMEMORY";
		break;
		case ERROR_INVALID_DRIVE:									//0x0000000F
		*name = "ERROR_INVALID_DRIVE";
		break;
		case ERROR_CURRENT_DIRECTORY:								//0x00000010
		*name = "ERROR_CURRENT_DIRECTORY";
		break;
		case ERROR_NOT_SAME_DEVICE:									//0x00000011
		*name = "ERROR_NOT_SAME_DEVICE";
		break;
		case ERROR_FILE_EXISTS:										//0x00000050
		*name = "ERROR_FILE_EXISTS";
		break;
		case ERROR_CANNOT_MAKE:										//0x00000052
		*name = "ERROR_CANNOT_MAKE";
		break;
		case ERROR_OUT_OF_STRUCTURES:								//0x00000054
		*name = "ERROR_OUT_STRUCTURES";
		break;
		case ERROR_ALREADY_ASSIGNED:								//0x00000055
		*name = "ERROR_ALREADY_ASSIGNED";
		break;
		case ERROR_INVALID_PASSWORD:								//0x00000056
		*name = "ERROR_INVALID_PASSWORD";
		break;
		case ERROR_INVALID_PARAMETER:								//0x00000057
		*name = "ERROR_INVALID_PARAMETER";
		break;
		case ERROR_NO_PROC_SLOTS:									//0x00000059
		*name = "ERROR_NO_PROC_SLOTS";
		break;
		case ERROR_OPEN_FAILED:										//0x0000006E
		*name = "ERROR_OPEN_FAILED";
		break;
		case ERROR_BUFFER_OVERFLOW:									//0x0000006F
		*name = "ERROR_BUFFER_OVERFLOW";
		break;
		case ERROR_DISK_FULL:										//0x00000070
		*name = "ERROR_DISK_FULL";
		break;
		case ERROR_NO_MORE_SEARCH_HANDLES:							//0x00000071
		*name = "ERROR_NO_MORE_SEARCH_HANDLES";
		break;
		case ERROR_CALL_NOT_IMPLEMENTED:							//0x00000078
		*name = "ERROR_CALL_NOT_IMPLEMENTED";
		break;
		case ERROR_INSUFFICIENT_BUFFER:								//0x0000007A
		*name = "ERROR_INSUFFICIENT_BUFFER";
		break;
		case ERROR_INVALID_NAME:									//0x0000007B
		*name = "ERROR_INVALID_NAME";
		break;
		case ERROR_INVALID_LEVEL:									//0x0000007C
		*name = "ERROR_INVALID_LEVEL";
		break;
		case ERROR_PROC_NOT_FOUND:									//0x0000007F
		*name = "ERROR_PROC_NOT_FOUND";
		break;
		case ERROR_IS_JOINED:										//0x00000086
		*name = "ERROR_IS_JOINED";
		break;
		case ERROR_IS_SUBSTED:										//0x00000087
		*name = "ERROR_IS_SUBSTED";
		break;
		case ERROR_NOT_JOINED:										//0x00000088
		*name = "ERROR_NOT_JOINED";
		break;
		case ERROR_NOT_SUBSTED:										//0x00000089
		*name = "ERROR_NOT_SUBSTED";
		break;
		case ERROR_DIR_NOT_EMPTY:									//0x00000091
		*name = "ERROR_DIR_NOT_EMPTY";
		break;
		case ERROR_BAD_PATHNAME:									//0x000000A1
		*name = "ERROR_BAD_PATHNAME";
		break;
		case ERROR_ALREADY_EXISTS:									//0x000000B7
		*name = "ERROR_ALREADY_EXISTS";
		break;
		case ERROR_MORE_DATA:										//0x000000EA
		*name = "ERROR_MORE_DATA";
		break;
		case ERROR_FAIL_SHUTDOWN:									//0x0000015F
		*name = "ERROR_FAIL_SHUTDOWN";
		break;
		case ERROR_FAIL_RESTART:									//0x00000160
		*name = "ERROR_FAIL_RESTART";
		break;
		case ERROR_INVALID_ADDRESS:									//0x000001E7
		*name = "ERROR_INVALID_ADDRESS";
		break;
		case ERROR_SYSTEM_SHUTDOWN:									//0x00000281
		*name = "ERROR_SYSTEM_SHUTDOWN";
		break;
		case ERROR_NOACCESS:										//0x000003E6
		*name = "ERROR_NOACCESS";
		//Invalid access to memory
		break;
		case ERROR_STACK_OVERFLOW:									//0x000003E9
		*name = "ERROR_STACK_OVERFLOW";
		break;
		case ERROR_INVALID_MESSAGE:									//0x000003EA
		*name = "ERROR_INVALID_MESSAGE";
		break;
		case ERROR_CAN_NOT_COMPLETE:								//0x000003EB
		*name = "ERROR_CAN_NOT_COMPLETE";
		break;
		case ERROR_INVALID_FLAGS:									//0x000003EC
		*name = "ERROR_INVALID_FLAGS";
		break;
		case ERROR_FILE_INVALID:									//0x000003EE
		*name = "ERROR_FILE_INVALID";
		break;
		case ERROR_NO_TOKEN:										//0x000003F0
		*name = "ERROR_NO_TOKEN";
		break;
		case ERROR_BADKEY:											//0x000003F2
		*name = "ERROR_BADKEY";
		break;
		case ERROR_CANTOPEN:										//0x000003F3
		*name = "ERROR_CANTOPEN";
		break;
		case ERROR_CANTREAD:										//0x000003F4
		*name = "ERROR_CANTREAD";
		break;
		case ERROR_NOT_REGISTRY_FILE:								//0x000003F9
		*name = "ERROR_NOT_REGISTRY_FILE";
		break;
		case ERROR_KEY_DELETED:										//0x000003FA
		*name = "ERROR_KEY_DELETED";
		break;
		case ERROR_DEPENDENT_SERVICES_RUNNING:						//0x0000041B
		*name = "ERROR_DEPENDENT_SERVICES_RUNNNING";
		break;
		case ERROR_INVALID_SERVICE_CONTROL:							//0x0000041C
		*name = "ERROR_INVALID_SERVICE_CONTROL";
		break;
		case ERROR_SERVICE_REQUEST_TIMEOUT:							//0x0000041D
		*name = "ERROR_SERVICE_REQUEST_TIMEOUT";
		break;
		case ERROR_SERVICE_NO_THREAD:								//0x0000041E
		*name = "ERROR_SERVICE_NO_THREAD";
		break;
		case ERROR_DATABASE_DOES_NOT_EXIST:							//0x00000429
		*name = "ERROR_DATABASE_DOES_NOT_EXIST";
		break;
		case ERROR_PROCESS_ABORTED:									//0x0000042B
		*name = "ERROR_PROCESS_ABORTED";
		break;
		case ERROR_INVALID_COMPUTERNAME:							//0x000004BA
		*name = "ERROR_INVALID_COMPUTERNAME";
		break;
		case ERROR_SERVICE_DEPENDENCY_FAIL:							//0x0000042C
		*name = "ERROR_SERVICE_DEPENDENCY_FAIL";
		break;
		case ERROR_SERVICE_LOGON_FAILED:							//0x0000042D
		*name = "ERROR_SERVICE_LOGON_FAILED";
		break;
		case ERROR_SERVICE_START_HANG:								//0x0000042E
		*name = "ERROR_SERVICE_START_HANG";
		break;
		case ERROR_INVALID_SERVICE_LOCK:							//0x0000042F
		*name = "ERROR_INVALID_SERVICE_LOCK";
		break;
		case ERROR_SERVICE_MARKED_FOR_DELETE:						//0x00000430
		*name = "ERROR_SERVICE_MARKED_FOR_DELETE";
		break;
		case ERROR_SERVICE_EXISTS:									//0x00000431
		*name = "ERROR_SERVICE_EXISTS";
		break;
		case ERROR_ALREADY_RUNNING_LKG:								//0x00000432
		*name = "ERROR_ALREADY_RUNNING_LKG";
		break;
		case ERROR_SERVICE_DEPENDENCY_DELETED:						//0x00000433
		*name = "ERROR_SERVICE_DEPENDENCY_DELTED";
		break;
		case ERROR_BOOT_ALREADY_ACCEPTED:							//0x00000434
		*name = "ERROR_BOOT_ALREADY_ACCEPTED";
		break;
		case ERROR_SERVICE_NEVER_STARTED:							//0x00000435
		*name = "ERROR_SERVICE_NEVER_STARTED";
		break;
		case ERROR_DUPLICATE_SERVICE_NAME:							//0x00000436
		*name = "ERROR_DUPLICATE_SERVICE_NAME";
		break;
		case ERROR_DIFFERENT_SERVICE_ACCOUNT:						//0x00000437
		*name = "ERROR_DIFFERENT_SERVICE_ACCOUNT";
		break;
		case ERROR_CANNOT_DETECT_DRIVER_FAILURE:					//0x00000438
		*name = "ERROR_CANNOT_DETECT_DRIVER_FAILURE";
		break;
		case ERROR_CANNOT_DETECT_PROCESS_ABORT:						//0x00000439
		*name = "ERROR_CANNOT_DETECT_PROCESS_ABORT";
		break;
		case ERROR_NO_RECOVERY_PROGRAM:								//0x0000043A
		*name = "ERROR_NO_RECOVERY_PROGRAM";
		break;
		case ERROR_SERVICE_NOT_IN_EXE:								//0x0000043B
		*name = "ERROR_SERVICE_NOT_IN_EXE";
		break;
		case ERROR_DLL_INIT_FAILED:									//0x0000045A
		*name = "ERROR_DLL_INIT_FAILED";
		break;
		case ERROR_SHUTDOWN_IN_PROGRESS:							//0x0000045B
		*name = "ERROR_SHUTDOWN_IN_PROGRESS";
		break;
		case ERROR_NO_SHUTDOWN_IN_PROGRESS:							//0x0000045C
		*name = "ERROR_NO_SHUTDOWN_IN_PROGRESS";
		break;
		case ERROR_IO_DEVICE:										//0x0000045D
		*name = "ERROR_IO_DEVICE";
		break;
		case ERROR_SERIAL_NO_DEVICE:								//0x0000045E
		*name = "ERROR_SERIAL_NO_DEVICE";
		break;
		case ERROR_COUNTER_TIMEOUT:									//0x00000461
		*name = "ERROR_COUNTER_TIMEOUT";
		break;
		case ERROR_DISK_OPERATION_FAILED:							//0x00000467
		*name = "ERROR_DISK_OPERATION_FAILED";
		break;
		case ERROR_OLD_WIN_VERSION:									//0x0000047E
		*name = "ERROR_OLD_WIN_VERSION";
		break;
		case ERROR_INVALID_DLL:										//0x00000482
		*name = "ERROR_INVALID_DLL";
		break;
		case ERROR_DLL_NOT_FOUND:									//0x00000485
		*name = "ERROR_DLL_NOT_FOUND";
		break;
		case ERROR_NOT_FOUND:										//0x00000490
		*name = "ERROR_NOT_FOUND";
		break;
		case ERROR_SHUTDOWN_USERS_LOGGED_ON:						//0x000004A7
		*name = "ERROR_SHUTDOWN_USERS_LOGGED_ON";
		break;
		case ERROR_BAD_PROFILE:										//0x000004B6
		*name = "ERROR_BAD_PROFILE";
		break;
		case ERROR_INVALID_GROUPNAME:								//0x000004B9
		*name = "ERROR_INVALID_GROUPNAME";
		break;
		case ERROR_INVALID_COMPUTERNAME:							//0x000004BA
		*name = "ERROR_INVALID_COMPUTERNAME";
		break;
		case ERROR_NO_NETWORK:										//0x000004C6
		*name = "ERROR_NO_NETWORK";
		break;
		case ERROR_CANCELLED:										//0x000004C7
		*name = "ERROR_CANCELLED";
		break;
		case ERROR_CANCELLED:										//0x000004C7
		*name = "ERROR_CANCELLED";
		break;
		case ERROR_LOGIN_TIME_RESTRICTION:							//0x000004D7
		*name = "ERROR_LOGIN_TIME_RESTRICTION";
		break;
		case ERROR_BAD_USER_PROFILE:								//0x000004E5
		*name = "ERROR_BAD_USER_PROFILE";
		break;
		case ERROR_HOST_DOWN:										//0x000004E8
		*name = "ERROR_HOST_DOWN";
		break;
		case ERROR_NON_ACCOUNT_SID:									//0x000004E9
		*name = "ERROR_NON_ACCOUNT_SID";
		break;
		case ERROR_NON_DOMAIN_SID:									//0x000004EA
		*name = "ERROR_NON_DOMAIN_SID";
		break;
		case ERROR_MACHINE_LOCKED:									//0x000004F7
		*name = "ERROR_MACHINE_LOCKED";
		break;
		case ERROR_NOT_ALL_ASSIGNED:								//0x00000514
		*name = "ERROR_NOT_ALL_ASSIGNED";
		break;
		case ERROR_SOME_NOT_MAPPED:									//0X00000515
		*name = "ERROR_SOME_NOT_MAPPED";
		break;
		case ERROR_NO_QUOTAS_FOR_ACCOUNT:							//0x00000516
		*name = "ERROR_NO_QUOTAS_FOR_ACCOUNT";
		break;
		case ERROR_LOCAL_USER_SESSION_KEY:							//0x00000517
		*name = "ERROR_LOCAL_USER_SESSION_KEY";
		break;
		case ERROR_NULL_LM_PASSWORD:								//0x00000518
		*name = "ERROR_NULL_LM_PASSWORD";
		break;
		case ERROR_UNKNOWN_REVISION:								//0x00000519
		*name = "ERROR_UNKNOWN_REVISION";
		break;
		case ERROR_INVALID_PRIMARY_GROUP:							//0x0000051C
		*name = "ERROR_INVALID_PRIMARY_GROUP";
		break;
		case ERROR_NO_IMPERSONATION_TOKEN:							//0x0000051D
		*name = "ERROR_NO_IMPERSONATION_TOKEN";
		break;
		case ERROR_NO_LOGON_SERVERS:								//0x0000051F
		*name = "ERROR_NO_LOGON_SERVERS";
		break;
		case ERROR_NO_SUCH_LOGON_SESSION:							//0x00000520
		*name = "ERROR_NO_SUCH_LOGON_SESSION";
		break;
		case ERROR_NO_SUCH_PRIVLEGE:								//0x00000521
		*name = "ERROR_NO_SUCH_PRIVLEGE";
		break;
		case ERROR_PRIVILEGE_NOT_HELD:								//0x00000522
		*name = "ERROR_PRIVILEGE_NOT_HELD";
		break;
		case ERROR_INVALID_ACCOUNT_NAME:							//0x00000523
		*name = "ERROR_INVALID_ACCOUNT_NAME";
		break;
		case ERROR_USER_EXISTS:										//0x00000524
		*name = "ERROR_USER_EXISTS";
		break;
		case ERROR_NO_SUCH_USER:									//0x00000525
		*name = "ERROR_NO_SUCH_USER";
		break;
		case ERROR_GROUP_EXISTS:									//0x00000526
		*name = "ERROR_GROUP_EXISTS";
		break;
		case ERROR_NO_SUCH_GROUP:									//0x00000527
		*name = "ERROR_NO_SUCH_GROUP";
		break;
		case ERROR_MEMBER_IN_GROUP:									//0x00000528
		*name = "ERROR_MEMBER_IN_GROUP";
		break;
		case ERROR_LAST_ADMIN:										//0x0000052A
		*name = "ERROR_LAST_ADMIN";
		break;
		case ERROR_WRONG_PASSWORD:									//0x0000052B
		*name = "ERROR_WRONG_PASSWORD";
		break;
		case ERROR_ILL_FORMED_PASSWORD:								//0x0000052C
		*name = "ERROR_ILL_FORMED_PASSWORD";
		break;
		case ERROR_LOGON_FAILURE:									//0x0000052E
		*name = "ERROR_LOGON_FAILURE";
		break;
		case ERROR_ACCOUNT_RESTRICTION:								//0x0000052F
		*name = "ERROR_ACCOUNT_RESTRICTION";
		break;
		case ERROR_INVALID_LOGON_HOURS:								//0x00000530
		*name = "ERROR_INVALID_LOGON_HOURS";
		break;
		case ERROR_INVALID_WORKSTATION:								//0x00000531
		*name = "ERROR_INVALID_WORKSTATION";
		break;
		case ERROR_PASSWORD_EXPIRED:								//0x00000532
		*name = "ERROR_PASSWORD_EXPIRED";
		break;
		case ERROR_ACCOUNT_DISABLED:								//0x00000533
		*name = "ERROR_ACCOUNT_DISABLED";
		break;
		case ERROR_INVALID_ACL:										//0x00000538
		*name = "ERROR_INVALID_ACL";
		break;
		case ERROR_INVALID_SID:										//0x00000539
		*name = "ERROR_INVALID_SID";
		break;
		case ERROR_INVALID_SECURITY_DESCR:							//0x0000053A
		*name = "ERROR_INVALID_SECURITY_DESCR";
		break;
		case ERROR_BAD_IMPERSONATION_LEVEL:							//0x00000542
		*name = "ERROR_BAD_IMPERSONATION_LEVEL";
		//Either a required impersonation level was not provided, or the provided impersonation level is invalid
		break;
		case ERROR_BAD_TOKEN_TYPE:									//0x00000545
		*name = "ERROR_BAD_TOKEN_TYPE";
		//The type of the token is inappropriate for its attempted use
		break;
		case ERROR_NO_SUCH_DOMAIN:									//0x0000054B
		*name = "ERROR_NO_SUCH_DOMAIN";
		//The specified domain either does not exist or could not be contacted
		break;
		case ERROR_DOMAIN_EXISTS:									//0x0000054C
		*name = "ERROR_DOMAIN_EXISTS";
		//The specified domain already exists
		break;
		case ERROR_INTERNAL_DB_CORRUPTION:							//0x0000054E
		*name = "ERROR_INTERNAL_DB_CORRUPTION";
		//Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk
		break;
		case ERROR_INTERNAL_ERROR:									//0x0000054F
		*name = "ERROR_INTERNAL_ERROR";
		//An internal error occured
		break;
		case ERROR_BAD_LOGON_SESSION_STATE:							//0X00000555
		*name = "ERROR_BAD_LOGON_SESSION_STATE";
		//The logon session is not in a state that is consistent with the requested operation
		break;
		case ERROR_INVALID_LOGON_TYPE:								//0x00000557
		*name = "ERROR_INVALID_LOGON_TYPE";
		break;
		case ERROR_CANNOT_IMPERSONATE:								//0x00000558
		*name = "ERROR_CANNOT_IMPERSONATE";
		//Unable to impersonate using a named pipe until data has been read from that pipe
		break;
		case ERROR_SPECIAL_ACCOUNT:									//0x0000055B
		*name = "ERROR_SPECIAL_ACCOUNT";
		//Cannot perform this operation on accounts
		break;
		case ERROR_NO_SUCH_MEMBER:									//0x0000056B
		*name = "ERROR_NO_SUCH_MEMBER";
		break;
		case ERROR_TOO_MANY_SIDS:									//0x0000056D
		*name = "ERROR_TOO_MANY_SIDS";
		break;
		case ERROR_NO_INHERITANCE:									//0x0000056F
		*name = "ERROR_NO_INHERITANCE";
		break;
		case ERROR_FILE_CORRUPT:									//0x00000570
		*name = "ERROR_FILE_CORRUPT";
		break;
		case ERROR_DISK_CORRUPT:									//0x00000571
		*name = "ERROR_DISK_CORRUPT";
		break;
		case ERROR_INVALID_WINDOW_HANDLE:							//0x00000578
		*name = "ERROR_INVALID_WINDOW_HANDLE";
		break;
		case ERROR_INVALID_MENU_HANDLE:								//0x00000579
		*name = "ERROR_INVALID_MENU_HANDLE";
		break;
		case ERROR_HOTKEY_ALREADY_REGISTERED:						//0x00000581
		*name = "ERROR_HOTKEY_ALREADY_REGISTERED";
		break;
		case ERROR_CLASS_ALREADY_EXISTS:							//0x00000582
		*name = "ERROR_CLASS_ALREADY_EXISTS";
		break;
		case ERROR_CLASS_DOES_NOT_EXIST:							//0x00000583
		*name = "ERROR_CLASS_DOES_NOT_EXIST";
		break;
		case ERROR_CLASS_HAS_WINDOWS:								//0x00000584
		*name = "ERROR_CLASS_HAS_WINDOWS";
		break;
		case ERROR_HOTKEY_NOT_REGISTERED:							//0x0000058B
		*name = "ERROR_HOTKEY_NOT_REGISTERED";
		break;
		case ERROR_INVALID_COMBOBOX_MESSAGE:						//0x0000058E
		*name = "ERROR_INVALID_COMBOBOX_MESSAGE";
		break;
		case ERROR_WINDOW_NOT_COMBOBOX:								//0x0000058F
		*name = "ERROR_WINDOW_NOT_COMBOBOX";
		break;
		case ERROR_DC_NOT_FOUND:									//0x00000591
		*name = "ERROR_DC_NOT_FOUND";
		break;
		case ERROR_NO_SYSTEM_MENU:									//0x0000059D
		*name = "ERROR_NO_SYSTEM_MENU";
		break;
		case ERROR_INVALID_MSGBOX_STYLE:							//0x0000059E
		*name = "ERROR_INVALID_MSGBOX_STYLE";
		break;
		case ERROR_INVALID_THREAD_ID:								//0x000005A4
		*name = "ERROR_INVALID_THREAD_ID";
		break;
		case ERROR_TIMEOUT:											//0x000005B4
		*name = "ERROR_TIMEOUT";
		break;
		case ERROR_INVALID_MONITOR_HANDLE:							//0x000005B5
		*name = "ERROR_INVALID_MONITOR_HANDLE";
		break;
		case ERROR_INCORRECT_SIZE:									//0x000005B6
		*name = "ERROR_INCORRECT_SIZE";
		break;
		case ERROR_XML_PARSE_ERROR:									//0x000005B9
		*name = "ERROR_XML_PARSE_ERROR";
		break;
		case ERROR_RESTART_APPLICATION:								//0x000005BB
		*name = "ERROR_RESTART_APPLICATION";
		break;
		case ERROR_PRODUCT_UNINSTALLED:								//0x0000064E
		*name = "ERROR_PRODUCT_UNINSTALLED";
		break;
		case ERROR_BAD_QUERY_SYNTAX:								//0x0000064F
		*name = "ERROR_BAD_QUERY_SYNTAX";
		break;
		case ERROR_DEVICE_REMOVED:									//0x00000651
		*name = "ERROR_DEVICE_REMOVED";
		break;
		case ERROR_INSTALL_ALREADY_RUNNING:							//0x00000652
		*name = "ERROR_INSTALL_ALREADY_RUNNING";
		break;
		case ERROR_FUNCTION_FAILED:									//0x0000065B
		*name = "ERROR_FUNCTIONFAILED";
		break;
		case ERROR_DATATYPE_MISMATCH:								//0x0000065D
		*name = "ERROR_DATATYPE_MISMATCH";
		break;
		case ERROR_INVALID_COMMAND_LINE:							//0x00000667
		*name = "ERROR_INVALID_COMMAND_LINE";
		break;
		case DNS_ERROR_BAD_PACKET:									//0x0000251E
		*name = "DNS_ERROR_BAD_PACKET";
		break;
		case DNS_ERROR_NO_PACKET:									//0x0000251F
		*name = "DNS_ERROR_NO_PACKET";
		break;
		case DNS_REQUEST_PENDING:									//0x00002522
		*name = "DNS_REQUEST_PENDING";
		break;
		case WSAEWOULDBLOCK:										//0x00002733
		*name = "WSAEWOULDBLOCK";
		break;
		case WSAEINPROGRESS:										//0x00002734
		*name = "WSAEINPROGRESS";
		break;
		case WSAEALREADY:											//0x00002735
		*name = "WSAEALREADY";
		break;
		case WSAENOTSOCK:											//0x00002736
		*name = "WSAENOTSOCK";
		break;
		case WSAEMSGSIZE:											//0x00002738
		*name = "WSAEMSGSIZE";
		break;
		case WSAEISCONN:											//0x00002748
		*name = "WSAEISCONN";
		break;
		case WSAENOTCONN:											//0x00002749
		*name = "WSAENOTCONN";
		break;
		case WSAESHUTDOWN:											//0x0000274A
		*name = "WSAESHUTDOWN";
		break;
		case WSAETIMEDOUT:											//0x0000274C
		*name = "WSAETIMEDOUT";
		break;
		case WSAECONNREFUSED:										//0x0000274D
		*name = "WSAECONNREFUSED";
		break;
		case WSAEHOSTDOWN:											//0x00002750
		*name = "WSAEHOSTDOWN";
		break;
		case WSAENOTEMPTY:											//0x00002752
		*name = "WSAENOTEMPTY";
		break;
		case WSAVERNOTSUPPORTED:									//0x0000276C
		*name = "WSAVERNOTSUPPORTED";
		break;
		case WSANOTINITIALISED:										//0x0000276D
		*name = "WSANOTINITIALISED";
		break;
		case WSAHOST_NOT_FOUND:										//0x00002AF9
		*name = "WSAHOST_NOT_FOUND";
		break;
		case ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION:			//0x000032DB
		*name = "ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION";
		break;
		case ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED:		//0x000035FF
		*name = "ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED";
		break;
		case ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY:		//0x0003637
		*name = "ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY";
		break;
		case ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING: //0x0000364D
		*name = "ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING";
		break;
		case ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE: //0x00003654
		*name = "ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE";
		break;
		case ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT:	//0x000036C4
		*name = "ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT";
		break;
		case ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT:	//0x00003715
		*name = "ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT";
		break;
		case ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL:	//0x00003AAE
		*name = "ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL";
		break;
		default:
		*name = "ERROR_UNKNOWN";
	}
}
