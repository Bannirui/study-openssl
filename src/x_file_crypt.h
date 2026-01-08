//
// Created by dingrui on 1/9/26.
//

#pragma once

#include <memory>
#include <string>

class XReadTask;
class XCryptTask;
class XWriteTask;

class XFileCrypt
{
public:
    bool Start(const std::string& inFileName, std::string& outFileName, const std::string& pwd, bool isEncrypt);
    void Wait();

private:
    std::shared_ptr<XReadTask>  r_task_;
    std::shared_ptr<XCryptTask> c_task_;
    std::shared_ptr<XWriteTask> w_task_;
};
