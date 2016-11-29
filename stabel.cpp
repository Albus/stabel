// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <windows.h>
#include <tchar.h>

// ---------------------------------------------------------------------------
USEFORM("form.cpp", SelfTabel);

// ---------------------------------------------------------------------------
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
