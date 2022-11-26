// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <iostream>
#include "Headers/HackManager.h"
//Change this for the close key
#define CLOSE_KEY VK_DELETE
#define BEGIN_KEY VK_INSERT

bool doHack = false;
DWORD WINAPI HackThread(HMODULE hModule)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	//Initilize our hack manager
	HackManager* hackManager = new HackManager();
	//We run all of our main hack stuff here
	while (!(GetAsyncKeyState(CLOSE_KEY) & 1))
	{
		if (GetAsyncKeyState(BEGIN_KEY) & 1)
			doHack = !doHack;
		if (doHack)
			hackManager->updateHacks();
	}
	fclose(f);
	FreeConsole();
	//release our hack
	hackManager->~HackManager();
	FreeLibraryAndExitThread(hModule, 0);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)HackThread, hModule, NULL, NULL);
	}
	return TRUE;
}