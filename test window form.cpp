#include <windows.h> 
LRESULT CALLBACK XulyMessage (HWND,UNIT,WPARAM,LPARAM); 
char szAppName [ ]= "Vidu"; 
int WINAPI WinMain (HANDLE hInst, HANDLE hPrevInst,LPSTR lpszCmdLine, int nCmdShow) 
{ 
HWND hwnd;  MSG msg; 
WNDCLASSEX wndclass; 
wndclass.cbSize = sizeof(wndclass); 
 wndclass.style = CS_HREDRAW | CS_VREDRAW; 
 wndclass.lpfnWndProc = XulyMessage; 
wndclass.cbClsExtra = 0; 
 wndclass.cbWndExtra = 0; 
 wndclass.hInstance = hInst; 
 wndclass.hIcon = LoadIcon (NULL, IDI_APPLICATION); 
 wndclass.hCursor = LoadCursor (NULL, IDC_ARROW); 
 wndclass.hbrBackground = GetStockObject (WHITE_BRUSH); 
 wndclass.lpszMenuName = NULL; 
wndclass.lpszClassName = szAppName; 
wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION); 
RegisterClassEx(&wndclass); 
 hwnd = CreateWindow(szAppName, 
"vi du", 
WS_OVERLAPPEDWINDOW, 
CW_USEDEFAULT, CW_USEDEFAULT, 
CW_USEDEFAULT, CW_USEDEFAULT, 
HWND_DESKTOP, 
NULL, 
hInst, 
NULL); 
ShowWindow (hwnd, nCmdShow); 
UpdateWindow (hwnd); 
 while (GetMessage (&msg, NULL, 0, 0)) 
{ 
 TranslateMessage (&msg);   DispatchMessage (&msg);  } 
return msg.wParam; 
} 
LRESULT CALLBACK XulyMessage(HWND hwnd, UINT iMsg, 
WPARAM wParam, LPARAM lParam) 
{ 
HDC hdc; 
PAINTSTRUCT ps; 
RECT rect; 
switch (iMsg) 
{ 
 case WM_PAINT:     hdc = BeginPaint (hwnd, &ps); 

GetClientRect (hwnd, &rect);   
   DrawText (hdc, "ada", -1, &rect, 
DT_SINGLELINE | DT_CENTER | DT_VCENTER); 
EndPaint (hwnd, &ps); 
break; 
case WM_DESTROY: 
PostQuitMessage(0); 
break; 
default: 
return DefWindowProc (hwnd, iMsg, wParam, lParam); 
} 
return 0; 
}
