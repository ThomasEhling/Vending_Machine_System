//
// Created by thomas on 28/04/19.
//

#ifndef VMSYSTEM_AFOPERATIONS_HPP
#define VMSYSTEM_AFOPERATIONS_HPP


/*
 * All Ooperations of the State pattern and The Output Processor
 */

#include "DataStore.hpp"
#include <list>

class AbstractFactory;

// --- Store price information ----
class A_StorePrice {
public:
    A_StorePrice() = default;;
    virtual ~A_StorePrice() = default;;
    virtual void StorePrice(DataStore *ds) = 0;
};// end A_StorePrice

class Storeprice_Int : public A_StorePrice {
public:
    void StorePrice(DataStore *ds) override;
};// end Storeprice_Int

class Storeprice_Float : public A_StorePrice {
public:
    void StorePrice(DataStore *ds) override;
};// end Storeprice_Float



// --- Clear coins information ---
class A_ZeroCF {
public:
    A_ZeroCF() = default;;
    virtual ~A_ZeroCF() = default;;
    virtual void ZeroCF(DataStore *ds)=0;
};// end A_ZeroCF

class ZeroCF_Int : public A_ZeroCF {
public:
    void ZeroCF(DataStore *ds) override;
};// end ZeroCF_Int

class ZeroCF_Float : public A_ZeroCF {
public:
    void ZeroCF(DataStore *ds) override;
};// end ZeroCF_Float



// --- Increase coins information ---
class A_IncreaseCF {
public:
    A_IncreaseCF() = default;;
    virtual ~A_IncreaseCF() = default;;
    virtual void IncreaseCF(DataStore *ds)=0;
};// end A_IncreaseCF

class IncreaseCF_Int : public A_IncreaseCF {
public:
    void IncreaseCF(DataStore *ds) override;
};// end IncreaseCF_Int

class IncreaseCF_Float : public A_IncreaseCF {
public:
    void IncreaseCF(DataStore *ds) override;
};// end IncreaseCF_Float



// --- Return coins  ---
class A_ReturnCoins {
public:
    A_ReturnCoins() = default;;
    virtual ~A_ReturnCoins() = default;;
    virtual void ReturnCoins()=0;
};// end A_ReturnCoins

class ReturnCoins_Int : public A_ReturnCoins {
public:
    void ReturnCoins() override;
};// end ReturnCoins_Int

class ReturnCoins_Float : public A_ReturnCoins {
public:
    void ReturnCoins() override;
};// end ReturnCoins_Float



// --- Dispose Drink  ---
class A_DisposeDrink {
public:
    A_DisposeDrink() = default;;
    virtual ~A_DisposeDrink() = default;;
    virtual void DisposeDrink(int id)=0;
};// end A_DisposeDrink

class DisposeDrink_1 : public A_DisposeDrink {
public:
    void DisposeDrink(int id) override;
};// end DisposeDrink_1

class DisposeDrink_2 : public A_DisposeDrink {
public:
    void DisposeDrink(int id) override;
};// end DisposeDrink_2



// --- Dispose Addiditves  ---
class A_DisposeAdd {
public:
    A_DisposeAdd() = default;;
    virtual ~A_DisposeAdd() = default;;
    virtual void DisposeAdd(list<int> a)=0;
};// end A_DisposeAdd

class DisposeAdd_1 : public A_DisposeAdd {
public:
    void DisposeAdd(list<int> a) override;
};// end DisposeAdd_1

class DisposeAdd_2 : public A_DisposeAdd {
public:
    void DisposeAdd(list<int> a) override;
};// end DisposeAdd_2



// OP class
class OP {
private:
    DataStore *ds{};
    A_StorePrice *sp{};
    A_ZeroCF *zcf{};
    A_IncreaseCF *icf{};
    A_ReturnCoins *rc{};
    A_DisposeDrink *dd{};
    A_DisposeAdd *da{};
    AbstractFactory *af;
public:
    explicit OP(AbstractFactory *a) : af(a) {};

    virtual ~OP();

    void init();

    void StorePrice();

    void ZeroCF();

    void IncreaseCF();

    void ReturnCoins();

    void DisposeDrink(int id);

    void DisposeAdd(list<int> a);
};


#endif //VMSYSTEM_AFOPERATIONS_HPP
