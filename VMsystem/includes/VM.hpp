//
// Created by thomas on 28/04/19.
//

#ifndef VMSYSTEM_VM_HPP
#define VMSYSTEM_VM_HPP

#include <string>
#include "DataStore.hpp"
#include "MDA.hpp"

class AbstractFactory;

class VM_1 {
private:
    MDA *mda;
    DS_1 *ds{};
    AbstractFactory *af;
public:
    VM_1(AbstractFactory *a, MDA *m):
            af(a), mda(m) {};
    virtual ~VM_1() {
        delete ds;
    }

    // all operations on VM1
    void init();
    void create(int p);
    void coin(int v);
    void card(float x);
    void sugar();
    void tea();
    void chocolate();
    void insert_cups(int n);
    void set_price(int p);
    void cancel();
};// end VM_1


class VM_2 {
private:
    MDA *mda;
    DS_2 *ds{};
    AbstractFactory *af;
public:
    VM_2(AbstractFactory *a, MDA *m):
            af(a), mda(m){};
    virtual ~VM_2() {
        delete ds;
    }

    // all operations on VM1
    void init();
    void CREATE(float p);
    void COIN(float v);
    void SUGAR();
    void CREAM();
    void COFFEE();
    void InsertCups(int n);
    void SetPrice(float p);
    void CANCEL();
};// end VM_2



#endif //VMSYSTEM_VM_HPP
