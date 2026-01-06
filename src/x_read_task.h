//
// Created by dingrui on 1/3/26.
//

#pragma once

#include <string>
#include <fstream>

#include "xio_stream.h"

class XReadTask : public XIOStream {
public:
    bool Init(const std::string &file_name);

private:
    void StartImpl() override;

private:
    std::ifstream ifs_;
};
