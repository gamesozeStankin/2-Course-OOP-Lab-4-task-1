#include <vector>

//
// Created by Kostantin Alaev on 29.11.2020.
//
template<typename T>
class Interface {
public:
    std::vector<T *> add();
};

class Detail {
    friend std::vector<Detail *> Interface<Detail>::add();

protected:
    Detail() = default;

public:
    virtual ~Detail() = default;
};

class Factory : public Detail {
    friend std::vector<Detail *> Interface<Detail>::add();

protected:
    Factory() = default;

public:
    friend Factory *ptrFactory() {
        return new Factory;
    }
};

template<typename T>
std::vector<T *> Interface<T>::add() {
    std::vector<T *> vector;
    vector.push_back(new Detail);
    vector.push_back(new Factory);

    return vector;
}

int main() {

    Interface<Detail> one;
    auto vec = one.add();

    for (auto item : vec) {
        delete item;
    }

    return 0;
}