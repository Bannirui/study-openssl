//
// Created by dingrui on 1/3/26.
//

#include "xio_stream.h"

void XIOStream::Start() {
    th_ = std::thread(&XIOStream::StartImpl, this);
}

void XIOStream::Wait() {
    if (th_.joinable()) {
        th_.join();
    }
}
