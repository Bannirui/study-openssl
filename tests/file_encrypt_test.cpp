//
// Created by dingrui on 1/9/26.
//

#include <iostream>
#include <string>

#include "../src/x_file_crypt.h"

int main()
{
    std::string pwd         = "12345678";
    std::string inFilePath  = "asset/tmp.txt";
    std::string outFilePath = "asset/file_encrypt.txt";

    XFileCrypt xfc;
    xfc.Start(inFilePath, outFilePath, pwd, true);
    xfc.Wait();
    return 0;
}