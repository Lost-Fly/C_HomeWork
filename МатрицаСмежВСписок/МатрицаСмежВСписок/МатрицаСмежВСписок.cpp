﻿//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <list>
//
//using namespace std;
//
//void PrintList(list<int>);
//
//int main() {
//    int matrix_size;
//    ifstream fin("matrix.txt");
//    fin >> matrix_size;
//
//    vector<vector<int>> matrix(matrix_size, vector<int>(matrix_size));
//    for (int i = 0; i < matrix_size; i++) {
//        for (int j = 0; j < matrix_size; j++) {
//            fin >> matrix[i][j];
//            cout << matrix[i][j];
//            cout << ' ';
//        }
//        cout << endl;
//    }
//    fin.close();
//
//    vector<list<int>> list_data(matrix_size);
//
//    for (int i = 0; i < matrix_size; i++) {
//        list<int> tmp_data;
//        for (int j = 0; j < matrix_size; j++) {
//            if (matrix[i][j] == 1) {
//                tmp_data.push_front(j+1);
//            }
//        }
//        cout << i + 1 << " -> ";
//        PrintList(tmp_data);
//        cout << endl;
//
//    }
//
//    return 0;
//}
//
//void PrintList(list<int> list) {
//    while (!list.empty()) {
//        cout << list.back();
//        list.pop_back();
//        if (!list.empty()) {
//            cout << " , ";
//        }
//    }
//}

#include <SFML/Graphics.hpp>

int main()
{
    // Создание окна размером 800x600 пикселей
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");

    // Создание круга радиусом 50 пикселей
    sf::CircleShape circle(50.f);

    // Установка цвета заливки круга
    circle.setFillColor(sf::Color::Green);

    // Позиционирование круга в центре окна
    circle.setPosition(window.getSize().x / 2 - circle.getRadius(), window.getSize().y / 2 - circle.getRadius());

    // Главный цикл программы
    while (window.isOpen())
    {
        // Обработка событий
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Отрисовка объектов на экране
        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}