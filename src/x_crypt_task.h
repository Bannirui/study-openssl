//
// Created by dingrui on 1/6/26.
//

#pragma once

#include "xio_stream.h"

class XCrypt;

class XCryptTask : public XIOStream {
public:
    void Init(std::string &password);;

    void set_is_encrypt(int encrypt) { this->is_encrypt_ = encrypt; }

private:
    void StartImpl() override;

private:
    std::shared_ptr<XCrypt> enc_;
    bool is_encrypt_ = true;
};
