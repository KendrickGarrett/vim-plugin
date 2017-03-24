#include <stdarg.h>
#include <stdio.h>
#include "StringLib.h"

uint string_concat(char* dest, uint count, ...) {
	char* str = (char*)0;
	uint i = 0;
	va_list arg;

	while(*dest) { dest++; i++; }

	va_start(arg, count);
	while(count--) {
		str = va_arg(arg, char*);
		while(*str) {
			*dest++ = *str++;
			i++; 
		}
	}
	va_end(arg);
	return i;
}

uint string_append(char* dest, uint size,  ...) {
	uint i = 0;
	va_list arg;
	//Move to the end of the destination string
	while(*dest) { dest++; i++; }
	va_start(arg, size);
	while(1) {
		char* param = va_arg(arg, char*);
		if(*param == '\0' && *(++param) == '\0') break;
		while(*param)
			if(i++ < size) *dest++ = *param++;	
			else goto LEAVE_STRING_CONCAT;
	}
LEAVE_STRING_CONCAT:
	//*dest = '\0';
	va_end(arg);
	return i;
}

uint __cdecl string_prepend(char* dest, uint size, ...) {
	char* param = (char*)0;
	char* str = (char*)malloc(size);
	if(!str) return 0;
	uint i = 0;
	uint ii = 0;

	while(*dest++) ii++;
	va_list arg;
	va_start(arg, size);
	while(1) {
		param = va_arg(arg, char*);
		if((*param == '\0' && *(++param) == '\0') || *param == 0) break;
		while(*param) {
			*str++ = *param++;
			i++;
		}
	}
	//size - ii
	*str = '\0'; str-=i;
	printf("String is %s", str);
	va_end(arg);
	free(str);
	return i;
}

uint __cdecl string_out(uint count, ...) {
	uint i = 0;
	char* str = (char*)0;
	va_list arg; va_start(arg, count);
	while(count--) { 
		str = va_arg(arg, char*);
		fputs(str, stdout);
		i+=strlen(str);
	}
	va_end(arg);
	return i; 
}
