// Graphics2D.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "Graphics2D.h"
#include "Graphics2DLibrary.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GRAPHICS2D, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GRAPHICS2D));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GRAPHICS2D));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GRAPHICS2D);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 800, 600, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            Graphics2DLibrary library;
            library.SetHDC(hdc);
            library.SetColor(RGB(255, 0, 0));
            double PI = 3.1415926535;

            // 绘制直线段
            //library.DrawLine({ 100, 100 }, { 500, 500 });
            //library.DrawLine({ 200, 100 }, { 400, 500 });
            //library.DrawLine({ 300, 100 }, { 300, 500 });
            //library.DrawLine({ 400, 100 }, { 200, 500 });
            //library.DrawLine({ 500, 100 }, { 100, 500 });
            //library.DrawLine({ 500, 200 }, { 100, 400 });
            //library.DrawLine({ 500, 300 }, { 100, 300 });
            //library.DrawLine({ 500, 400 }, { 100, 200 });

            // 绘制任意圆弧
            //library.SetColor(RGB(0, 0, 255));
            //library.DrawCircle_Bresenham({ 300,300 }, 50);
            //library.DrawCircle_Polygon({ 100, 100 }, 100, -PI / 4, 5 * PI / 8, 0.01);
            //library.DrawCircle_Polygon({ 300, 100 }, 100, PI / 4, 7 * PI / 8, 0.01);

            // 绘制椭圆弧
            //library.SetColor(RGB(0, 0, 255));
            //library.DrawEllipse({ 400,200 }, 100, 50, 0, 2 * PI, 0.01);
            //library.DrawEllipse({ 200,200 }, 100, 50, 3 * PI / 4, 3 * PI / 2, 0.01);
            //library.DrawEllipse({ 300,200 }, 80, 200, 1 * PI / 4, 3 * PI / 4, 0.01);

            // 多边形区域的阴影填充
            //library.LineFill(PI / 4, 10, { {{0,0}, {100,0}}, {{100,0}, {100,100}}, {{100,100}, {0,100}}, {{0,100}, {0,0}} });
            //library.LineFill(-PI / 3, 5, { {{200,200}, {500,200}}, {{500,200}, {300,300}}, {{300,300}, {200,300}}, {{200,300}, {200,200}} });

            // 多边形区域的颜色填充
            //library.ColorFill_Flood4({ 291,320 }, RGB(255, 0, 255));
            //library.ColorFill_Flood4({ 321,320 }, RGB(255, 255, 0));

            // 绘制姓名
            library.DrawEllipse({ 200,200 }, 100, 50, PI / 2, 14 * PI / 8, 0.01);
            library.DrawCircle_Polygon({ 200, 350 }, 100, -PI / 2, PI, 0.01);
            library.DrawLine({ 300, 200 }, { 500, 200 });
            library.DrawLine({ 500, 200 }, { 300, 400 });
            library.DrawLine({ 300, 400 }, { 500, 400 });
            library.DrawCircle_Polygon({ 600, 300 }, 100, PI / 4, 7 * PI / 4, 0.01);
            library.DrawLine({ 670, 50 }, { 670, 400 });

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
