//
// Created by dingrui on 1/9/26.
//

#include "x_file_crypt.h"

#include "x_read_task.h"
#include "x_crypt_task.h"
#include "x_write_task.h"

bool XFileCrypt::Start(const std::string& inFileName, std::string& outFileName, const std::string& pwd, bool isEncrypt)
{
    std::shared_ptr<std::pmr::memory_resource> memPool(new std::pmr::synchronized_pool_resource);

    this->r_task_ = std::make_shared<XReadTask>();
    this->r_task_->Init(inFileName);
    this->r_task_->set_mem_pool(memPool);

    this->c_task_ = std::make_shared<XCryptTask>();
    this->c_task_->Init(pwd);
    this->c_task_->set_mem_pool(memPool);
    this->c_task_->set_is_encrypt(isEncrypt);

    this->w_task_ = std::make_shared<XWriteTask>();
    this->w_task_->set_mem_pool(memPool);
    this->w_task_->Init(outFileName);

    this->r_task_->set_next(this->c_task_);
    this->c_task_->set_next(this->w_task_);

    this->r_task_->Start();
    this->c_task_->Start();
    this->w_task_->Start();
    return true;
}

void XFileCrypt::Wait()
{
    if (this->r_task_)
    {
        this->r_task_->Wait();
    }
    if (this->c_task_)
    {
        this->c_task_->Wait();
    }
    if (this->w_task_)
    {
        this->w_task_->Wait();
    }
}
