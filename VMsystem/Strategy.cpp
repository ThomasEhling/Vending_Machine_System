#include <utility>

//
// Created by thomas on 28/04/19.
//

#include <iostream>
#include "includes/Strategy.hpp"
#include "includes/Globals.hpp"
#include "includes/AbstractFactory.hpp"


void Storeprice_Int::StorePrice(DataStore *ds) {
    DS_1 *ds1 = (DS_1 *) ds;
    ds1->setPrice(ds1->getTempPrice());
    int p = ds1->getPrice();
    cout << "Price for a drink : " << p << endl;
}

void Storeprice_Float::StorePrice(DataStore *ds) {
    DS_2 *ds2 = (DS_2 *) ds;
    ds2->setPrice(ds2->getTempPrice());
    float p = ds2->getPrice();
    cout << "Price for a drink : " << p << endl;
}

void ZeroCF_Int::ZeroCF(DataStore *ds) {
    DS_1 *ds1 = (DS_1 *) ds;
    ds1->setCoins(0);
    cout << "Reset actual balance" << endl;
}

void ZeroCF_Float::ZeroCF(DataStore *ds) {
    DS_2 *ds2 = (DS_2 *) ds;
    ds2->setCoins(0);
    cout << "Reset actual balance" << endl;
}

void IncreaseCF_Int::IncreaseCF(DataStore *ds) {
    DS_1 *ds1 = (DS_1 *) ds;
    ds1->setCoins(ds1->getCoins() + ds1->getTempValue());
    int b = ds1->getCoins();
    cout << "Current balance : " << b << endl;
    int p = ds1->getPrice();
    cout << "Price for a drink : " << p << endl;
}

void IncreaseCF_Float::IncreaseCF(DataStore *ds) {
    DS_2 *ds2 = (DS_2 *) ds;
    ds2->setCoins(ds2->getCoins() + ds2->getTempValue());
    float b = ds2->getCoins();
    cout << "Current balance : " << b << endl;
    float p = ds2->getPrice();
    cout << "Price for a drink : " << p << endl;
}

void ReturnCoins_Int::ReturnCoins() {
    cout << "return Coins" << endl;
}

void ReturnCoins_Float::ReturnCoins() {
    cout << "return Coins" << endl;
}

void DisposeDrink_1::DisposeDrink(int id) {
    if (id == TEAD_ID) {
        cout << "dispose a cup of tea" << endl;
    } else if (id == CHOCOLATE_ID) {
        cout << "Dispose a cup of hot chocolate" << endl;
    }

}

void DisposeDrink_2::DisposeDrink(int id) {
    if (id == COFFEE_ID) {
        cout << "Dispose a cup of coffee" << endl;
    }
}

void DisposeAdd_1::DisposeAdd(list<int> a) {
    int counter = 0;
    for (int &it : a) {
        if (counter == SUGAR_ID && it) {
            cout << "Add some sugar" << endl;
        }
        counter++;
    }
}

void DisposeAdd_2::DisposeAdd(list<int> a) {
    int counter = 0;
    for (int &it : a) {
        if (counter == SUGAR_ID && it) {
            cout << "Add some sugar" << endl;
        } else if (counter == CREAM_ID && it) {
            cout << "Add some cream" << endl;
        }
        counter++;
    }
}

void OP::init() {
    ds = af->createDS();
    sp = af->createSP();
    zcf = af->createZCF();
    icf = af->createICF();
    rc = af->createRC();
    dd = af->createDD();
    da = af->createDA();
}

OP::~OP() {
    delete sp;
    delete zcf;
    delete icf;
    delete rc;
    delete dd;
    delete da;
}


void OP::StorePrice() {
    sp->StorePrice(ds);
}

void OP::ZeroCF() {
    zcf->ZeroCF(ds);
}

void OP::IncreaseCF() {
    icf->IncreaseCF(ds);
}

void OP::ReturnCoins() {
    rc->ReturnCoins();
}

void OP::DisposeDrink(int id) {
    dd->DisposeDrink(id);
}

void OP::DisposeAdd(list<int> a) {
    da->DisposeAdd(std::move(a));
}
