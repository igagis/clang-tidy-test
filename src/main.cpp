#include <iostream>

#include <memory>

void potential_memory_leak_1(){
    auto f = [obj = std::make_shared<std::string>("Hello world!")](){
        std::cout << *obj << std::endl;
    };

    f();
}

int main(int argc, const char** argv){

    potential_memory_leak_1();

    return 0;
}
