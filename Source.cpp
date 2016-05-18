#include <windows.h>
#include "Resource.h"
#include<stdio.h>
//---------------------------------------------------------------------------
HWND hWnd,second;
char textSaved[1000];
LRESULT CALLBACK DlgProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
//---------------------------------------------------------------------------
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1),
		hWnd, reinterpret_cast<DLGPROC>(DlgProc));

	return FALSE;
}
//---------------------------------------------------------------------------
LRESULT CALLBACK DlgProc(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_CREATE:
	{		
					  second = CreateWindowEx(WS_EX_CLIENTEDGE,
						  "EDIT",
						  "",
						  WS_CHILD | WS_VISIBLE |
						  ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
						  100,
						  100,
						  200,
						  100,
						  hWnd,
						 NULL,
						  GetModuleHandle(NULL),
						  NULL);

	}
		break;
	case WM_CLOSE:
		EndDialog(hWndDlg, 0);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:
		{
					
					return TRUE;
		}
		case IDCANCEL:
		{
			
		}
		break;
		}
	

	}

	return FALSE;
}
//---------------------------------------------------------------------------