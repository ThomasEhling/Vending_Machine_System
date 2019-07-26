//
// Created by thomas on 28/04/19.
//

#ifndef VMSYSTEM_ABSTRACTFACTORY_HPP
#define VMSYSTEM_ABSTRACTFACTORY_HPP

#include "DataStore.hpp"
#include "Strategy.hpp"

// Abstract factory main class
// this class is abstract
class AbstractFactory {
protected:
    // All pointers that would be init
    DataStore *cacheDS;
    A_StorePrice *cacheSP;
    A_ZeroCF *cacheZCF;
    A_IncreaseCF *cacheICF;
    A_ReturnCoins *cacheRC;
    A_DisposeDrink *cacheDD;
    A_DisposeAdd *cacheDA;

public:
    AbstractFactory();

    virtual ~AbstractFactory();

    virtual DataStore *createDS() = 0;

    virtual A_StorePrice *createSP() = 0;

    virtual A_ZeroCF *createZCF() = 0;

    virtual A_IncreaseCF *createICF() = 0;

    virtual A_ReturnCoins *createRC() = 0;

    virtual A_DisposeDrink *createDD() = 0;

    virtual A_DisposeAdd *createDA() = 0;

};// end AbstractFactory


// Abstract Factory instance for VM_1
class Fact_VM_1 : public AbstractFactory {
public:
    Fact_VM_1() = default;;

    ~Fact_VM_1() override {};

    DataStore *createDS() override;

    A_StorePrice *createSP() override;

    A_ZeroCF *createZCF() override;

    A_IncreaseCF *createICF() override;

    A_ReturnCoins *createRC() override;

    A_DisposeDrink *createDD() override;

    A_DisposeAdd *createDA() override;
};// end Fact_VM_1

// Abstract Factory instance for VM_2
class Fact_VM_2 : public AbstractFactory {
public:
    Fact_VM_2() = default;;

    ~Fact_VM_2() override = default;;

    DataStore *createDS() override;

    A_StorePrice *createSP() override;

    A_ZeroCF *createZCF() override;

    A_IncreaseCF *createICF() override;

    A_ReturnCoins *createRC() override;

    A_DisposeDrink *createDD() override;

    A_DisposeAdd *createDA() override;
};// end Fact_VM_2



#endif //VMSYSTEM_ABSTRACTFACTORY_HPP
