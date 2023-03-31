// testwin3.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "testwin3.h"
#include <cmath>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
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

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TESTWIN3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TESTWIN3));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TESTWIN3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TESTWIN3);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//

// Угол поворота планет
float mercuryAngle = 0;
float venusAngle = 0;
float earthAngle = 0;
float marsAngle = 0;
float jupiterAngle = 0;
float saturnAngle = 0;
float uranusAngle = 0;
float neptuneAngle = 0;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_CREATE:

        SetTimer(hWnd, 1, 10, NULL);
        return 0;

    case WM_TIMER:
        // Обновляем углы поворота планет


        mercuryAngle += 0.05;
        venusAngle += 0.03;
        earthAngle += 0.02;
        marsAngle += 0.01;
        jupiterAngle += 0.005;
        saturnAngle += 0.0025;
        uranusAngle += 0.00125;
        neptuneAngle += 0.000625;

        // Обновляем изображение
        InvalidateRect(hWnd, NULL, FALSE);
        return 0;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Координаты центра окна
        int centerX = ps.rcPaint.right / 2;
        int centerY = ps.rcPaint.bottom / 2;

        // Радиус орбиты планет
        int orbitRadius = 100;

        // Радиус планет
        int mercuryRadius = 5;
        int venusRadius = 10;
        int earthRadius = 15;
        int marsRadius = 12;
        int jupiterRadius = 30;
        int saturnRadius = 25;
        int uranusRadius = 20;
        int neptuneRadius = 18;

        

        // Отрисовка планет
        SelectObject(hdc, GetStockObject(DC_BRUSH));

        // Меркурий
        SetDCBrushColor(hdc, RGB(192, 192, 192));
        Ellipse(hdc, centerX + orbitRadius * cos(mercuryAngle) - mercuryRadius, centerY - orbitRadius * sin(mercuryAngle) - mercuryRadius,
            centerX + orbitRadius * cos(mercuryAngle) + mercuryRadius, centerY - orbitRadius * sin(mercuryAngle) + mercuryRadius);

        // Венера
        SetDCBrushColor(hdc, RGB(255, 222, 173));
        Ellipse(hdc, centerX + orbitRadius * cos(venusAngle) - venusRadius, centerY - orbitRadius * sin(venusAngle) - venusRadius,
            centerX + orbitRadius * cos(venusAngle) + venusRadius, centerY - orbitRadius * sin(venusAngle) + venusRadius);

        // Земля
        SetDCBrushColor(hdc, RGB(0, 0, 255));
        Ellipse(hdc, centerX + orbitRadius * cos(earthAngle) - earthRadius, centerY - orbitRadius * sin(earthAngle) - earthRadius,
            centerX + orbitRadius * cos(earthAngle) + earthRadius, centerY - orbitRadius * sin(earthAngle) + earthRadius);

        // Марс
        SetDCBrushColor(hdc, RGB(255, 165, 0));
        Ellipse(hdc, centerX + orbitRadius * cos(marsAngle) - marsRadius, centerY - orbitRadius * sin(marsAngle) - marsRadius,
            centerX + orbitRadius * cos(marsAngle) + marsRadius, centerY - orbitRadius * sin(marsAngle) + marsRadius);

        // Юпитер
        SetDCBrushColor(hdc, RGB(238, 232, 170));
        Ellipse(hdc, centerX + orbitRadius * cos(jupiterAngle) - jupiterRadius, centerY - orbitRadius * sin(jupiterAngle) - jupiterRadius,
            centerX + orbitRadius * cos(jupiterAngle) + jupiterRadius, centerY - orbitRadius * sin(jupiterAngle) + jupiterRadius);

        // Сатурн
        SetDCBrushColor(hdc, RGB(210, 180, 140));
        Ellipse(hdc, centerX + orbitRadius * cos(saturnAngle) - saturnRadius, centerY - orbitRadius * sin(saturnAngle) - saturnRadius,
            centerX + orbitRadius * cos(saturnAngle) + saturnRadius, centerY - orbitRadius * sin(saturnAngle) + saturnRadius);
        SelectObject(hdc, GetStockObject(DC_PEN));
        SetDCPenColor(hdc, RGB(210, 180, 140));
        Arc(hdc, centerX + orbitRadius * cos(saturnAngle) - saturnRadius, centerY - orbitRadius * sin(saturnAngle) - saturnRadius,
            centerX + orbitRadius * cos(saturnAngle) + saturnRadius, centerY - orbitRadius * sin(saturnAngle) + saturnRadius, saturnRadius - 5, saturnRadius - 5, saturnRadius - 5, saturnRadius - 5);
        SetDCBrushColor(hdc, RGB(255, 255, 0));
        Ellipse(hdc, centerX + orbitRadius * cos(saturnAngle) - saturnRadius + (saturnRadius - 5) * cos(saturnAngle * 3), centerY - orbitRadius * sin(saturnAngle) - saturnRadius + (saturnRadius - 5) * sin(saturnAngle * 3),
            centerX + orbitRadius * cos(saturnAngle) + saturnRadius + (saturnRadius - 5) * cos(saturnAngle * 3), centerY - orbitRadius * sin(saturnAngle) + saturnRadius + (saturnRadius - 5) * sin(saturnAngle * 3));

        // Уран
        SetDCBrushColor(hdc, RGB(173, 216, 230));
        Ellipse(hdc, centerX + orbitRadius * cos(uranusAngle) - uranusRadius, centerY - orbitRadius * sin(uranusAngle) - uranusRadius,
            centerX + orbitRadius * cos(uranusAngle) + uranusRadius, centerY - orbitRadius * sin(uranusAngle) + uranusRadius);

        // Нептун
        SetDCBrushColor(hdc, RGB(0, 191, 255));
        Ellipse(hdc, centerX + orbitRadius * cos(neptuneAngle) - neptuneRadius, centerY - orbitRadius * sin(neptuneAngle) - neptuneRadius,
            centerX + orbitRadius * cos(neptuneAngle) + neptuneRadius, centerY - orbitRadius * sin(neptuneAngle) + neptuneRadius);


        EndPaint(hWnd, &ps);
        break;
    }
    

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
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
