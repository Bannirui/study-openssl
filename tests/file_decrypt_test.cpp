//
// Created by dingrui on 1/9/26.
//

#include <iostream>
#include <string>

#include "../src/x_file_crypt.h"

int main()
{
    std::string pwd         = "12345678";
    std::string inFilePath  = "asset/file_encrypt.txt";
    std::string outFilePath = "asset/file_decrypt.txt";

    XFileCrypt xfc;
    xfc.Start(inFilePath, outFilePath, pwd, false);
    xfc.Wait();
    return 0;
}