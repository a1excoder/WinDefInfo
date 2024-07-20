#include <Windows.h>
#include <tchar.h>

#include <cstdio>

#define Exclusions TEXT("SOFTWARE\\Microsoft\\Windows Defender\\Exclusions\\Paths")


int _tmain(int argc, const TCHAR **argv)
{
	if (argc < 2) {
		_tprintf(TEXT("[ERROR] - enter path to file/directory\n"));
		return 1;
	}

	_tprintf(TEXT("adding %s to %s\n"), argv[1], Exclusions);

	HKEY key = NULL;
	LSTATUS res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, Exclusions, 0, KEY_SET_VALUE, &key);

	if (res == ERROR_SUCCESS) {
		RegSetValueEx(key, argv[1], 0, REG_DWORD, nullptr, 0);
	}
	else {
		_tprintf(TEXT("HKEY_LOCAL_MACHINE\\%s cannot opened\n"), Exclusions);
		return 2;
	}

	if (res == ERROR_SUCCESS) {
		_tprintf(TEXT("%s was added to exceptions\n"), argv[1]);
	}
	else {
		_tprintf(TEXT("%s wasn't added to exceptions\n"), argv[1]);
	}

	RegCloseKey(key);

	return 0;
}
