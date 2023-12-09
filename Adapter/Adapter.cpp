#include <iostream>
#include <string>


class Target {
public:
    virtual void request() const = 0;
    virtual ~Target() = default;
};


class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Specific Request\n";
    }
};


class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* a) : adaptee(a) {}

    void request() const override {
        adaptee->specificRequest();
    }
};

int main() {
    
    Adaptee adapteeObject;

    
    Adapter adapter(&adapteeObject);

   
    adapter.request();

    return 0;
}