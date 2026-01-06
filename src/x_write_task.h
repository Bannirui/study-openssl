//
// Created by dingrui on 1/6/26.
//

#pragma once

#include <fstream>

#include "xio_stream.h"


class XWriteTask : public XIOStream {
public:
    bool Init(const std::string &fileName);

private:
    void StartImpl() override;

private:
    std::ofstream ofs_;
};
