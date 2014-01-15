#include <windows.h>
#include <ole2.h>
#include <olectl.h>
#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

using namespace std;

bool bTog = false;

/// Taken from http://stackoverflow.com/a/7292773

int screengrab()
{
    int result;

    RECT rc; /// Define rectangle structure - http://msdn.microsoft.com/en-us/library/a5ch4fda.aspx
    HWND hwnd = FindWindow("Chrome_RenderWidgetHostHWND", NULL);    ///the window can't be min
    /// HWND = Handle Window - http://msdn.microsoft.com/en-us/library/tc46f3be.aspx
    if (hwnd == NULL)
    {
        cout << "it can't find any 'note' window" << endl;
        return 0;
    }
    GetClientRect(hwnd, &rc); /// Get the window client area from HWND handle to rc - http://msdn.microsoft.com/en-us/library/windows/desktop/ms633503(v=vs.85).aspx

    ///create
    HDC hdcScreen = GetDC(NULL);
    /// HDC retries handle for device context (DC) for graphics functions -  Windows data type - http://msdn.microsoft.com/en-us/library/windows/desktop/aa383751(v=vs.85).aspx
    /// GetDC - http://msdn.microsoft.com/en-us/library/windows/desktop/dd144871(v=vs.85).aspx
    HDC hdc = CreateCompatibleDC(hdcScreen);
    /// Creates a memory device context (CreateCompatibleDC) - http://msdn.microsoft.com/en-us/library/windows/desktop/dd183489(v=vs.85).aspx
    HBITMAP hbmp = CreateCompatibleBitmap(hdcScreen,
        rc.right - rc.left, rc.bottom - rc.top);
    /// HBITMAP = A handle to a bitmap - http://msdn.microsoft.com/en-us/library/windows/desktop/aa383751(v=vs.85).aspx
    /// CreateCompatible - http://msdn.microsoft.com/en-us/library/windows/desktop/dd183488(v=vs.85).aspx
    SelectObject(hdc, hbmp);
    /// http://msdn.microsoft.com/en-us/library/windows/desktop/dd162957(v=vs.85).aspx

    //Print to memory hdc
    PrintWindow(hwnd, hdc, PW_CLIENTONLY);

    //copy to clipboard
    OpenClipboard(NULL);
    EmptyClipboard();
    SetClipboardData(CF_BITMAP, hbmp);
    CloseClipboard();

    cout << "success copy to clipboard, please paste it to the 'mspaint'" << endl;

       // Set "stdin" to have binary mode:
    result = _setmode( _fileno( stdout ), _O_BINARY );
    if( result == -1 )
      perror( "Cannot set mode" );
    else
      printf( "'stdout' successfully changed to binary mode\n" );

    cout.flush();
    cout << "hbmp " << hbmp << endl;

    //release
    DeleteDC(hdc);
    DeleteObject(hbmp);
    ReleaseDC(NULL, hdcScreen);

    return 0;
}

/// Taken from http://www.dreamincode.net/forums/topic/183750-detect-pressed-keys/

int main () {
	while (true) {
		if (GetAsyncKeyState(VK_INSERT)) {
            screengrab();
			/// if (bTog) bTog = false; else bTog = true;
			/// cout << bTog << endl;
			return 0;
		}
		Sleep (175);
	}
	return 0;
}

