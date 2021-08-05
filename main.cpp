/*
 * Разработайте простейший просмотрщик текстовых файлов. В начале программы пользователь вводит
 * путь к текстовому файлу, который требуется открыть и просмотреть. Внутренности файла необходимо
 * вывести в стандартный вывод. Программа должна работать для любых текстовых файлов в формате TXT,
 * но вы можете создать и свой отдельный файл для теста. Главное, чтобы файл был англоязычным, дабы
 * избежать проблем с кодировками.
 */
#include <iostream>
#include <fstream>


int main() {
    std::ifstream txtFile;
    std::string path;
    char buf[256];

    do
    {
        std::cout << "Please, enter file name to open with full path: ";
        std::cin >> path;
        txtFile.open(path, std::ios::binary);
        if(!txtFile.is_open()) std::cout << "Bad file name!" << std::endl;
    } while (!txtFile.is_open());

    while (!txtFile.eof()) {
        txtFile.read(buf, 255);
        buf[txtFile.gcount()] = 0;
        std::cout << buf;

    }
    txtFile.close();
    return 0;
}
