#include <windows.h>
#include <cmath>

const double PI = 3.14159265358979323846;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetDC(hwnd);
    RECT rect;
    GetClientRect(hwnd, &rect);

    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;

    int xCenter = width / 2;
    int yCenter = height / 2;

    double a = width / 4.0; // большая полуось
    double b = height / 6.0; // малая полуось
    double t = 0; // начальный угол

    while (true)
    {
        double x = xCenter + a * cos(t);
        double y = yCenter + b * sin(t);

        SelectObject(hdc, GetStockObject(WHITE_BRUSH));
        Ellipse(hdc, x - 10, y - 10, x + 10, y + 10); // рисуем круг

        t += 0.01; // увеличиваем угол

        if (t >= 2 * PI) // если угол больше 2*PI, то обнуляем его
            t = 0;

        Sleep(10); // задержка
        InvalidateRect(hwnd, NULL, TRUE); // перерисовываем окно
    }

    ReleaseDC(hwnd, hdc);
    return 0;
}