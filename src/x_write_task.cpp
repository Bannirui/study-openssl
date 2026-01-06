//
// Created by dingrui on 1/6/26.
//

#include "x_write_task.h"

#include <iostream>

#include "x_data.h"

bool XWriteTask::Init(const std::string &fileName) {
    this->ofs_.open(fileName, std::ios::binary);
    if (!this->ofs_) {
        std::cerr << "file open failed, file is " << fileName << std::endl;
        return false;
    }
    std::cout << "file, " << fileName << " open succ" << std::endl;
    return true;
}

void XWriteTask::StartImpl() {
    std::cout << "XWriteTask::StartImpl() start" << std::endl;
    while (!this->is_exit) {
        std::shared_ptr<XData> data = PopFront();
        if (!data) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }
        this->ofs_.write((char *) data->data(), data->size());
        if (data->end()) {
            break;
        }
    }
    this->ofs_.flush();
    this->ofs_.close();
    std::cout << "XWriteTask::StartImpl() end" << std::endl;
}
