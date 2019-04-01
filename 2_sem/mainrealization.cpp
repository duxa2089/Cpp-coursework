#include "header.h" // реализация меню программы

void FileInput(vector <Product*> &productvector) //проверка файла на уже имеющиеся в нём товары
{
    string n;
    int i = 0; //счётчик для объектов вектора
    ifstream fin("File.txt"); //открытие файла для считывания
    while (fin >> n) //если текстовый файл содержит информацию, то провести считывание
    {
        productvector.push_back (new Product(0)); //создать объект, для записи в него информации
        fin >> n; //игнорирование лишних слов
        fin >> n;
        fin.ignore(); //игнорирование пробела
        fin.getline(productvector[i]->name,100); // считали строку из файла
        fin >> n;
        fin >> n;
        fin.ignore();
        fin.getline(productvector[i]->article,100);
        fin >> n;
        fin >> n;
        fin >> productvector[i]->count;
        fin >> n;
        fin >> n;
        fin >> productvector[i]->price;
        i++; //счётчик новых объектов вектора
    }
    fin.close(); //закрытие файла
}
void FileOutput(vector <Product*> &productvector){  //Запись товаров в файл
ofstream fout;
  fout.open("File.txt",ios_base::out | ios_base::trunc); //открыть для записи, предварительно очистив его
  for (int i = 0; i < productvector.size(); i++) //запись всех объектов в файл
            {
                fout<<i + 1<<")"<<endl;
                fout<<"Нименование товара: " << productvector[i]->name<<endl;
                fout<<"Артикул товара: " << productvector[i]->article<<endl;
                fout<<"Количество товара: " << productvector[i]->count<<endl;
                fout<<"Цена товара: " << productvector[i]->price<<endl;
            }
  fout.close(); //закрытие файла
}

void Main(vector <Product*> &productvector)  //Меню
{
    char choice; //переменная выбора
    int flag = 0; //флаг while
    while (flag != 1) //для цикличности выпадения меню
    {
        cout << "Программа для управления деятельностью склада." << endl;
        cout << "1.Добавить товар в систему учёта." << endl;
        cout << "2.Редактировать запись о товаре в системе учёта." << endl;
        cout << "3.Удаление записи о товаре." << endl;
        cout << "4.Отсортировать товары в алфавитном порядке" << endl;
        cout << "5.Вывести актуальный список товаров" << endl;
        cout << "6.Выход из программы" << endl;
        cout << "Сделайте выбор:" << endl;
        cin >> choice; //инициализация переменной выбора
        int ClearConsole = 0; //переменная контроля отчистки консоли
        system("cls"); //очистка консоли
        switch (choice) //переменная выбора действия
        {
        case '1':
        {
            Case1(productvector); //первая функция кейса
            break;
        }
        case '2':
        {
            int case2;
            case2 = Case2(productvector);   //вторая функция в кейсе
            if (case2 == 3) //проверка на пустоту вектора
            {
                cout << "Список товаров пуст" << endl;
                ClearConsole = 1; //задержать удаление, чтобы было видно сообщение выше
            }
            if (case2 == 2) //проверка на наличие такого артикула в векторе
            {
                cout << "Товара с таким артикулом нет в списке" << endl;
                ClearConsole = 1; //задержать удаление, чтобы было видно сообщение выше
            }
            break;
        }
        case '3':
        {
            int case3;
            case3 = Case3(productvector); //третья функция в кейсе
            if (case3 == 3)   //проверка на пустоту вектора
            {
                cout << "Список товаров пуст" << endl;
                ClearConsole = 1; //задержать удаление, чтобы было видно сообщение выше
            }
            if (case3 == 2)   //проверка на наличие такого артикула в векторе
            {
                cout << "Товара с таким артикулом нет в списке" << endl;
                ClearConsole = 1; //задержать удаление, чтобы было видно сообщение выше
            }
            break;
        }
        case '4':
        {
            Case4(productvector); //четвёртая функция в кейсе
            break;
        }
        case '5':
        {
            ClearConsole = 1; //задержать удаление, чтобы вывести список товаров
            Case5(productvector); //пятая функция в кейсе
            break;
        }
        case '6':
        {
            flag = 1; //для выхода из цикла While
            break;
        }
        default: //в случае указания другого, сделать подменю продолжения работы
        {
            char choice_exit; //инициализация переменной выбора подменю
            int flag1 = 1; //флаг while
            cout << "Ошибка ввода, продолжить работу с программой?(Y/N)" << endl;
            while (flag1!=0)
            {
                cin >> choice_exit;
                switch (choice_exit)
                {
                case 'Y':
                case 'y':
                {
                    flag1 = 0; //если пользователь хочет выйти, измением флаг
                    break;
                }
                case 'N':
                case 'n':
                {
                    flag1 = 0; //иначе продолжаем работу с меню
                    flag = 1;
                    break;
                }
                default:
                {
                    cout << "Неверный запрос, повторите снова" << endl; //при неверном указании, попросить повторного ввода
                    break;
                }
                }
            }
            break;
        }
        }
        if (ClearConsole == 0) //если очистку не задержали, то очистить консоль
            system("cls"); //очистка консоли
    }
}
