#include <iostream>
using namespace std;
#include <random>
#include <chrono>
#include <cmath>
int max_num(int arr[]){

        int max = 0;
        for (int i = 0; i <= 197; i++){
            if (arr[i]> max){
            max = arr[i];
            }
        }
        return max;
}


int min_num(int arr[]){

        int min = 1000;
        for (int i = 0; i < 197; i++){
            if (arr[i] < min){
            min = arr[i];
            }
        }
        return min;
}

// 1 задание 
int main(){

int nums [100];

for (int i = 0; i <= 99; i ++){
    std::random_device rd;                         
    std::mt19937 gen(rd());                        
    std::uniform_int_distribution<> dist(-99, 99); 
    int rand_num = dist(gen);
    nums[i] = rand_num;
}
for (int i = 0; i <= 99; i++){
    cout<<nums[i]<<" ";
}
cout<<endl<<endl;

//2 задание

int nums1 [100];

for (int i = 0;i <= 99; i ++){
    nums1[i] = nums[i];

}

{
auto start = std::chrono::high_resolution_clock::now();

    
for (int i = 0; i <= 99; i++) {
    for (int j = 0; j <= 99 - i -1 ; j++) {
        if (nums1[j] > nums1[j + 1]) {
            int temp = nums1[j];
            nums1[j] = nums1[j + 1];
            nums1[j + 1] = temp;
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    
    for (int i = 0; i <= 99; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    
    cout << "время сортировки: " << duration.count() << " секунд" << endl << endl;
}
//3 задание 

cout<<"максимальный элемент в отс. массиве: " << max_num(nums1) << endl;
cout<<"минимальный элемент в отс. массиве: " << min_num(nums1) << endl<<endl;

{   
auto start = std::chrono::high_resolution_clock::now();

max_num(nums);


auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration = end - start;
     
cout<<"время нахождения макс элемента в неотс. массиве: " << duration.count() << " секунд" << endl << endl;

}

{
auto start = std::chrono::high_resolution_clock::now();

max_num(nums1);


auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration = end - start;
     
cout<<"время нахождения макс элемента в отс. массиве: " << duration.count() << " секунд" << endl << endl;

}

{
auto start = std::chrono::high_resolution_clock::now();

min_num(nums);


auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration = end - start; 

cout<<"время нахождения мин элемента в неотс. массиве: " << duration.count() << " секунд" << endl << endl;
}

{
auto start = std::chrono::high_resolution_clock::now();

min_num(nums1);

auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration = end - start;
    

cout<<"время нахождения мин элемента в отс. массиве: " << duration.count() << " секунд" << endl << endl ;  
}

//4 задание 
{
int avgnum = (min_num(nums1) + max_num(nums1))/2;
avgnum = round(avgnum);
cout<< "среднее значение:" << avgnum<<endl;
int mass[200];
int z = 0;
int count = 0;

auto start = std::chrono::high_resolution_clock::now();

for (int i = 0; i <= 99; i++){
    if (nums1[i] == avgnum){
        mass[z] = i;
        z++;
        count++;

    }

}


auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration = end - start;

cout<<"время поиска индексов: " << duration.count() << " секунд" << endl << endl ;

cout<< "индексы :";
for (int i = 0; i <= count - 1; i++){
    cout<<mass[i];
    cout<<" ";
}
cout<<endl;
cout<<"кол-во совпадений: "<<count<<endl<<endl;
}
//5 задание 
{
int a;
cout<< "введите число: ";
cin>>a;
int count = 0;
for (int i =0; i <= 99; i ++){
    if (nums1[i] < a){
        count ++;
    }
}
cout<<count<<endl<<endl;
}


//6 задание
{
  int b;
cout<< "введите число: ";
cin>>b;
int count = 0;
for (int i =0; i <= 99; i ++){
    if (nums1[i] > b){
        count ++;
    }
}
cout<<count<<endl<<endl;  
}

//7 задание 
{
int a;
cout<< "введите индекс: ";
cin>> a;

int b;
cout<<"введите индекс: ";
cin>> b;
int temp;
auto start = std::chrono::high_resolution_clock::now();
temp = nums1[a];
nums1[a] = nums1[b];
nums1[b] = temp;

auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration = end - start;
cout<<"время обмена: " << duration.count() << " секунд" << endl << endl ;

for (int i = 0; i <= 99; i++) {
        cout << nums1[i] << " ";
    }
}
cout<<endl<<endl;

//идз 3 
{ 
int user_value;
    cout << "Введите значение для обработки массива: ";
    cin >> user_value;

    int divisible_count[9] = {0}; // Для подсчета делений на числа от 1 до 9
    for (int i = 0; i <= 99; i++) {
        if (nums[i] % 2 != 0) {
            nums[i] -= user_value; // Уменьшить нечетный элемент на значение пользователя
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(1, 9);
            int multiplier = dist(gen);
            nums[i] *= multiplier; // Умножить нечетный элемент на случайную величину
        }
        // Подсчет элементов, делящихся нацело на числа от 1 до 9
        for (int j = 1; j <= 9; j++) {
            if (nums[i] % j == 0) {
                divisible_count[j - 1]++;
            }
        }
    }

    // Вывод результата обработки массива
    cout << "Массив после обработки:\n";
    for (int i = 0; i <= 99; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "\nКоличество элементов, которые делятся нацело:\n";
    for (int i = 1; i <= 9; i++) {
        cout << "На " << i << ": " << divisible_count[i - 1] << endl;
    }

    return 0;
}
}



