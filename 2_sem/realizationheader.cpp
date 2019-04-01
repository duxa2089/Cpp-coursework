#include "header.h" // Реализация методов и конструкторов
Product :: Product() // Конструктор ввода информации о товаре
{
    cout << "Введите наименование товара:" << endl;
    cin.ignore();  // Игнорирование пробелов
    cin.getline(name,100); // Считывание всей строки
    cout << "Введите артикул товара:" << endl;
    cin.getline(article,100);
    cout << "Введите количество товара (шт.):" << endl;
    while(!(cin >> count) || cin.get() != '\n')
    {
        cout << "Введите число, а не символы !" << endl;
        cin.clear(); // Сбрасывает все биты потока, то есть поток становится "хорошим"
        cin.sync();// Удалим данные из буффера
        cout << "Введите количество товара (шт.):" << endl;
    }
    cout << "Введите цену товара (руб.):" << endl;
    while(!(cin >> price) || cin.get() != '\n')
    {
        cout << "Введите число, а не символы !" << endl;
        cin.clear();
        cin.sync();
        cout << "Введите цену товара (руб.):" << endl;
    }
}
Product :: Product(int empty) {} // Конструктор для обмена
Product :: Product(int empty1, int empty2) // Конструктор для указания артикула
{
    cout << "Введите артикул товара, который нужно изменить:" << endl;
    cin.ignore();
    cin.getline(article,100);
}
Product :: printInfo() // Конструктор ввода информации о товаре
{
    cout << "Наименование товара: " << name << endl;
    cout << "Артикул товара: " << article << endl;
    cout << "Количество товара: " << count << " шт." << endl;
    cout << "Цена товара: " << price << " руб." << endl << endl;
}
