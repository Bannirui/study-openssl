//
// Created by dingrui on 1/9/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "../src/x_file_crypt.h"

int main()
{
    std::string pwd              = "12345678";
    std::string inFileDirectory  = "asset/encrypt";
    std::string outFileDirectory = "asset/decrypt";

    std::vector<std::shared_ptr<XFileCrypt>> fes;
    for (auto& f : std::filesystem::directory_iterator(inFileDirectory))
    {
        if (!f.is_regular_file())
        {
            continue;
        }
        auto        xfc         = std::make_shared<XFileCrypt>();
        std::string outFilePath = outFileDirectory + "/" + f.path().filename().string();
        xfc->Start(f.path().string(), outFilePath, pwd, false);
        fes.push_back(xfc);
    }
    for (auto& fe : fes)
    {
        fe->Wait();
    }
    return 0;
}