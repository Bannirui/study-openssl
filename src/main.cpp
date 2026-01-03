#include <iostream>

#include"x_read_task.h"
#include "x_crypt.h"

int main() {
    XReadTask r_task;
    r_task.Init("asset/tmp.txt");
    r_task.Start();
    r_task.Wait();

    XCrypt crypt;
    crypt.Init("12345678");
    char en_out[1024] = {0};
    int en_size = crypt.Encrypt("abcdefg", 7, en_out, true);
    std::cout << "en_size=" << en_size << std::endl;
    char de_out[1024] = {0};
    int de_size = crypt.Decrypt(en_out, en_size, de_out, true);
    std::cout << "de_size=" << de_size << std::endl;
    std::cout << "de_data=" << de_out << std::endl;
    return 0;
}
