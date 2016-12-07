// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <windows.h>
#include <tchar.h>
#include "memory"

// ---------------------------------------------------------------------------
USEFORM("form.cpp", SelfTabel);
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int) {

	WCHAR* MutexName = UnicodeString("SelfTabel").w_str();

	HANDLE hMutex = OpenMutexW(MUTEX_ALL_ACCESS, 0, MutexName);
	if (!hMutex)
		hMutex = CreateMutex(0, 0, MutexName);
	else {
		HWND hWnd = FindWindow(0, MutexName);
		SetForegroundWindow(hWnd);
		ShowWindow(hWnd, SW_SHOW);
		return 0;
	}

	HANDLE hEmbededFont = 0;
	DWORD dwFontsInstalled = 0;
	try {

		std::auto_ptr<TResourceStream>ResourceFont1
			(new TResourceStream((int)HInstance, 1, RT_FONT));
		std::auto_ptr<TResourceStream>ResourceFont2
			(new TResourceStream((int)HInstance, 2, RT_FONT));
		std::auto_ptr<TResourceStream>ResourceFont3
			(new TResourceStream((int)HInstance, 3, RT_FONT));

		AddFontMemResourceEx(ResourceFont1->Memory, ResourceFont1->Size, 0,
			&dwFontsInstalled);
		AddFontMemResourceEx(ResourceFont2->Memory, ResourceFont2->Size, 0,
			&dwFontsInstalled);
		AddFontMemResourceEx(ResourceFont3->Memory, ResourceFont3->Size, 0,
			&dwFontsInstalled);



	}
	catch (...) {
	}

	try {
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "Табель учета рабочего времени";
		Application->CreateForm(__classid(TSelfTabel), &SelfTabel);
		Application->Run();
	}
	catch (Exception &exception) {
		Application->ShowException(&exception);
	}
	catch (...) {
		try {
			throw Exception("");
		}
		catch (Exception &exception) {
			Application->ShowException(&exception);
		}
	}

	ReleaseMutex(hMutex);
	CloseHandle(hMutex);

	return 0;
}

// ---------------------------------------------------------------------------
