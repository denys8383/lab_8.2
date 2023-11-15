#include <iostream>
#include <string>
#include <cwctype> // Включення cwctype для iswalnum
#include <windows.h>
using namespace std;

// Функція для знаходження максимальної довжини слова в рядку
size_t MaxWordLength(const wstring s)
{
    // Ініціалізація змінних для збереження максимальної та поточної довжини слова
    size_t maxLen = 0;
    size_t currentLen = 0;

    // Проходження по кожному символу у рядку
    for (wchar_t c : s)
    {
        // Перевірка, чи символ є буквою чи цифрою (частиною слова)
        if (iswalnum(c))
        {
            currentLen++; // Збільшення поточної довжини слова
        }
        else
        {
            // Якщо зустрічено не буквено-цифровий символ, оновити maxLen, якщо поточна довжина більша
            if (currentLen > maxLen)
            {
                maxLen = currentLen;
            }
            currentLen = 0; // Скидання поточної довжини для наступного слова
        }
    }

    // Перевірка для останнього слова в разі, якщо воно досягло кінця рядка без зустрічі не буквено-цифрового символу
    if (currentLen > maxLen)
    {
        maxLen = currentLen;
    }

    return maxLen; // Повернення максимальної довжини слова
}

int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    wstring str;
    wcout << L"Enter string:" << endl; 
    getline(wcin, str); // Зчитування рядка з консолі

    wcout << L"Length of the longest word: " << MaxWordLength(str) << endl; 

    return 0; 
}
