#include <windows.h>
#define GREY 	0x60656C
#define BLACK 	0x000000
#define GREEN 	0x0F2C18
# define ID_TIMER 1
enum LightState
{
	Green,
	Yellow,
	Red
};
struct TrafficInfo{
	bool stopFlag = 0; 
	int i = 0;
	bool lightState[3] = {1,0,0};
	char times[2] = {'1','0'};
	COLORREF timesColor = RGB(0,255,0);
}traffic;
void getKeybord(WPARAM wParam)
{
	switch(wParam)
	{
		case ' ':
		{
			traffic.stopFlag = true;
			MessageBox(NULL, "空白鍵已按下程式即將關閉","通知!",MB_OK);
			PostQuitMessage(0);
			break;	
		};
	}
}
//draw line
static void DrawLine(HDC hDC, int x0, int y0, int x1, int y1, int style, int width, COLORREF color)
{
HPEN hPen = CreatePen(style, width, color);
HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
MoveToEx(hDC, x0, y0, NULL);
LineTo(hDC, x1, y1);
SelectObject(hDC, hOldPen);
DeleteObject(hPen);
}
//draw circle
void DrawCircle(HDC hDC, int x, int y, int len, COLORREF colorIn, COLORREF colorOut)
{
	HBRUSH hBrush = CreateSolidBrush(colorIn);//inside
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	HPEN hPen = CreatePen(PS_SOLID, 1, colorOut);//outside
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
	Ellipse(hDC, x-len/2, y-len/2, x+len/2, y+len/2);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	
	
	SelectObject(hDC, hOldPen);
	DeleteObject(hOldBrush);
}
//draw Rect
void DrawRect(HDC hDC, int left, int top, int width, int height, COLORREF colorIn, COLORREF colorOut)
{
	HBRUSH hBrush = CreateSolidBrush(colorIn);//inside
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	HPEN hPen = CreatePen(PS_SOLID, 1, colorOut);//outside
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
	Rectangle(hDC, left, top, left+width, top+height);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	SelectObject(hDC, hOldPen);
	DeleteObject(hBrush);
}
void DrawText(HDC hDC,int x,int y, int size , char *str, COLORREF colorIn, COLORREF colorOut)
{
	HFONT hFont = CreateFont
    (
        100,0,
        0, 0,
        FW_HEAVY,
        0,0,0,
        0, 
        OUT_DEFAULT_PRECIS,        
        CLIP_DEFAULT_PRECIS,        
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_DONTCARE,    
        "Console" 
    );
    SetBkColor(hDC, colorOut);
    SetTextColor(hDC,colorIn);
	HFONT hOldFont = (HFONT)SelectObject(hDC,hFont);
    TextOut(hDC, x,y,str, strlen(str));
    SelectObject(hDC,hOldFont);
    DeleteObject(hFont);
}
void printTrafficLight(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd,&ps);
	DrawRect(hdc,100,26,30,700,BLACK,BLACK);
	DrawCircle(hdc,100,100,150,GREEN,BLACK);
	DrawRect(hdc,100,25,400,150,GREEN,BLACK);
	DrawCircle(hdc,500,100,150,GREEN,BLACK);
	DrawRect(hdc,100,26,400,148,GREEN,GREEN);
	DrawCircle(hdc,100,100,100,(traffic.lightState[0])?RGB(0,255,0):GREY,BLACK);
	DrawCircle(hdc,225,100,100,(traffic.lightState[1])?RGB(255,255,0):GREY,BLACK);
	DrawCircle(hdc,350,100,100,(traffic.lightState[2])?RGB(255,0,0):GREY,BLACK);
	DrawText(hdc,425,50,100,traffic.times,traffic.timesColor,GREY);
	EndPaint(hwnd,&ps);
}
void runTraffic(HWND hwnd,LightState state,int s)
{
	switch (state)
	{
	case Green:
		traffic.lightState[0] = 1;
		traffic.lightState[1] = 0;
		traffic.lightState[2] = 0;
		traffic.times[0] = (10 - s)/10+0x30;
		traffic.times[1] = (10 - s)%10+0x30;
		traffic.timesColor = RGB(0,255,0);
		break;
	case Yellow:
		traffic.lightState[0] = 0;
		traffic.lightState[1] = 1;
		traffic.lightState[2] = 0;
		traffic.times[0] = (14- s)/10+0x30;
		traffic.times[1] = (14- s)%10+0x30;
		traffic.timesColor = RGB(255,255,0);
		break;
	case Red:
		traffic.lightState[0] = 0;
		traffic.lightState[1] = 0;
		traffic.lightState[2] = 1;
		traffic.times[0] = (25 - s)/10+0x30;
		traffic.times[1] = (25 - s)%10+0x30;
		traffic.timesColor = RGB(255,0,0);
		break;
	}
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_CREATE:
		{
        	SetTimer(hwnd, ID_TIMER, 1000, NULL);
        	break;
    	}
		case WM_DESTROY: {
			KillTimer(hwnd, ID_TIMER);
			PostQuitMessage(0);
			break;
		}
		case WM_TIMER:
		{
			LightState state = (traffic.i <= 10) ? Green : ((traffic.i <= 14) ? Yellow : Red);
			runTraffic(hwnd,state,traffic.i);
			if(!traffic.stopFlag)traffic.i = (traffic.i < 25) ? traffic.i + 1 : 0;
	        InvalidateRect(hwnd, NULL, TRUE);
	        break;
	    } 
		case WM_PAINT:
		{
			printTrafficLight(hwnd);
			break;
		}
		case WM_KEYDOWN:
		{
			getKeybord(wParam);
			break;	
		}
		
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd; 
	MSG msg;
	memset(&wc,0,sizeof(wc));
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","紅綠燈模擬器",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);
	
	
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	else MessageBox(hwnd,"使用英文輸入法按下空白鍵可退出程式", "紅綠燈已啟動!", MB_OK);
	while(GetMessage(&msg, NULL, 0, 0) > 0){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
