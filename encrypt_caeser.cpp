#include <iostream>

std::string caesar_encrypt (std::string line, int key)          //функция принимает сообщение и ключ смещения для шифрования
{
    std::string result = "";                                    //создаём строку, которую будем возвращать (зашифрованная/итоговая строка)
    key %=26;                                                   //определяем, на сколько смещается символ
    for (char i: line)                                          //посимвольно анализируем входную строку
    {
        if (i >= 'a' && i <= 'z')
        {
            i -= 96;                                            //присваиваем значение буквам как в алфавите a=1 ... z=26

                if (key >= 0)
                {
                    result += (i+key)%26 >=1 ? ((i+key)%26)+96 : (i+key)+96;   //определяем, есть ли переход начало алфавита и добавляем соответствующую букву в result и возвращаем готовое значение буквы
                }
                else
                {
                    result += (i+key)%26 <=0 ? (26+(i+key))+96 : ((i+key)%26)+96;   //определяем, есть ли переход конец алфавита и добавляем соответствующую букву в result и возвращаем готовое значение буквы
                }
        }
        else if (i >= 'A' && i <= 'Z')
        {
            i -= 64;                                            //присваиваем значение буквам как в алфавите A=1 ... Z=26
                if (key >= 0)
                {
                    result += (i+key)%26 >=1 ? ((i+key)%26)+64 : (i+key)+64;   //определяем, есть ли переход начало алфавита и добавляем соответствующую букву в result и возвращаем готовое значение буквы
                }
                else
                {
                    result += (i+key)%26 <=0 ? (26+(i+key))+64 : ((i+key)%26)+64;   //определяем, есть ли переход конец алфавита и добавляем соответствующую букву в result и возвращаем готовое значение буквы
                }
        }
        else                                                    //символ не является буквой английского алфавита, оставляем, как есть
        {
            result += i;
        }

    }
    return result;
}

std::string caesar_decrypt (std::string line, int key)
{
    return caesar_encrypt (line, -key);
}

int main ()
{
    std::string message;
    int key = 0;

    std::cout << "Input the message:\n";
    std::getline(std::cin,message);
    std::cout << std::endl;

    std::cout << "Input the encryption key (any integer): ";
    std::cin >> key;
    std::cout << std::endl;
    
    std::cout << caesar_encrypt (message, key) << std::endl << std::endl; //шифруем и выводим результат
    std::cout << caesar_decrypt (caesar_encrypt(message, key), key) << std::endl; //расшифровываем и выводим результат
}