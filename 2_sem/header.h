#ifndef headerh // Header file. Connection of necessary libraries, creation of classes and functions
#define headerh
#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class  Product // Class of goods 
{
 public:
    char name[100]; // Name of goods
    char article[100]; // Article of goods
    int count; // Amount of goods
    double price; // Price of goods
    ~Product() {};// The destructor of the product
    Product(); // Designer input information about the product
    Product(int empty); // The constructor for the exchange
    Product(int empty1, int empty2); // Constructor to specify the article
    printInfo(); // A function display information about the product
    friend istream& operator >> (istream &s,Product &v); // Input operation overload
};
void FileInput(vector <Product*> &productvector); // Checking a file for products already in it
void FileOutput(vector <Product*> &productvector); // The entry of goods into a file
void Main(vector <Product*> &productvector); // Menu
void Case1(vector <Product*> &productvector);
int Case2(vector <Product*> &productvector);
int Case3(vector <Product*> &productvector); 
void Case4(vector <Product*> &productvector);
void Case5(vector <Product*> &productvector);
#endif
