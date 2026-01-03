//
// Created by dingrui on 1/3/26.
//

#pragma once

#include <thread>

class XIOStream {
public:
    void Start();

    void Wait();

    void Stop() { is_exit = true; };

protected:
    virtual void StartImpl() =0;

protected:
    bool is_exit{false};
    long long data_byte_{0};

private:
    std::thread th_;
};
