//
// Created by dingrui on 1/3/26.
//

#include "x_read_task.h"

#include <iostream>

bool XReadTask::Init(std::string file_name) {
    if (file_name.empty()) {
        return false;
    }
    ifs_.open(file_name, std::ios::binary);
    if (!ifs_) {
        std::cerr << "Failed to open file " << file_name << std::endl;
        return false;
    }
    std::cout << file_name << " open succ" << std::endl;
    ifs_.seekg(0, std::ios::end);
    data_byte_ = ifs_.tellg();
    ifs_.seekg(0, std::ios::beg);
    std::cout << "file size is " << data_byte_ << std::endl;
    return true;
}

void XReadTask::StartImpl() {
    while (!is_exit) {
        if (ifs_.eof()) {
            break;
        }
        char buf[1024] = {0};
        ifs_.read(buf, sizeof(buf));
        std::cout << ifs_.gcount() << ", " << buf << std::endl;
    }
}
