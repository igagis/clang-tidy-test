#include <iostream>

#include <memory>

void potential_memory_leak_1(){
    auto f = [obj = std::make_shared<std::string>("Hello world!")](){
        std::cout << *obj << std::endl;
    };

    f();
}

struct result{
    std::shared_ptr<std::string> p;
    bool some_other_field;
};

result potential_memory_leak_2(bool arg){
    result ret{.p = std::make_shared<std::string>("Hello world!")};

    if(arg){
        throw std::runtime_error("error");
    }

    return ret;
}

int main(int argc, const char** argv){
    try{

        potential_memory_leak_1();

        // NOTE:
        // uncommenting the next line makes "potential memory leak" warnings go away.

        // potential_memory_leak_2(true);

    }catch(...){}

    return 0;
}
