#include <iostream>

#include "x_crypt.h"
#include"x_read_task.h"
#include "x_crypt_task.h"
#include "x_write_task.h"

int main() {
    std::string pwd = "12345678";

    // crypt
    {
        std::shared_ptr<std::pmr::memory_resource> memPool(new std::pmr::synchronized_pool_resource);
        std::string inFilePath = "asset/tmp.txt";
        std::string outFilePath = "asset/tmp_out.txt";

        std::shared_ptr<XReadTask> r_task = std::make_shared<XReadTask>();
        r_task->Init(inFilePath);
        r_task->set_mem_pool(memPool);

        std::shared_ptr<XCryptTask> c_task = std::make_shared<XCryptTask>();
        c_task->Init(pwd);
        c_task->set_mem_pool(memPool);
        c_task->set_is_encrypt(true);

        std::shared_ptr<XWriteTask> w_task = std::make_shared<XWriteTask>();
        w_task->set_mem_pool(memPool);
        w_task->Init(outFilePath);

        r_task->set_next(c_task);
        c_task->set_next(w_task);

        r_task->Start();
        c_task->Start();
        w_task->Start();

        r_task->Wait();
        c_task->Wait();
        w_task->Wait();
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));

    // dcrypt
    {
        std::shared_ptr<std::pmr::memory_resource> memPool(new std::pmr::synchronized_pool_resource);
        std::string inFilePath = "asset/tmp_out.txt";
        std::string outFilePath = "asset/tmp_recover.txt";

        std::shared_ptr<XReadTask> r_task = std::make_shared<XReadTask>();
        r_task->Init(inFilePath);
        r_task->set_mem_pool(memPool);

        std::shared_ptr<XCryptTask> c_task = std::make_shared<XCryptTask>();
        c_task->Init(pwd);
        c_task->set_mem_pool(memPool);
        c_task->set_is_encrypt(false);

        std::shared_ptr<XWriteTask> w_task = std::make_shared<XWriteTask>();
        w_task->set_mem_pool(memPool);
        w_task->Init(outFilePath);

        r_task->set_next(c_task);
        c_task->set_next(w_task);

        r_task->Start();
        c_task->Start();
        w_task->Start();

        r_task->Wait();
        c_task->Wait();
        w_task->Wait();
    }
    return 0;
}
