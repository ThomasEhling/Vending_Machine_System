//
// Created by thomas on 29/04/19.
//

#include <iostream>
#include "scenario.hpp"
#include "../includes/AbstractFactory.hpp"
#include "../includes/Strategy.hpp"
#include "../includes/VM.hpp"


void testScenario_VM1() {

    auto *af1 = new Fact_VM_1();
    auto *op = new OP(af1);
    auto *mda = new MDA(op);
    auto *vm1 = new  VM_1(af1, mda);
    op->init();
    vm1->init();

    vm1->create(10); // set price to 10
    vm1->coin(5); // should return coins as we want cups
    vm1->insert_cups(1);
    vm1->coin(5);
    vm1->insert_cups(1); // total od 2
    vm1->coin(5); // Enough to order a drink
    vm1->sugar(); // Add sugar
    vm1->tea(); //display tea and sugar
    vm1->card(10.5);
    vm1->cancel();// should reset the balance
    vm1->sugar(); // should print nothing as in Idle State
    vm1->coin(10);
    vm1->sugar();
    vm1->sugar();// should remove the sugar
    vm1->chocolate(); // dispose chocolate without sugar
    vm1->coin(10); // should return the coins as we are in NoCups

    delete af1;
    delete op;
    delete mda;
    delete vm1;
}

void testScenario_VM2() {
    auto *af2 = new Fact_VM_2();
    auto *op = new OP(af2);
    auto *mda = new MDA(op);
    auto *vm2 = new VM_2(af2, mda);
    op->init();
    vm2->init();

    vm2->CREATE(10.5); // set price to 10
    vm2->COIN(5.5); // should return coins as we want cups
    vm2->InsertCups(1);
    vm2->COIN(5.5);
    vm2->InsertCups(1); // total od 2
    vm2->COIN(5.5); // Enough to order a drink
    vm2->SUGAR(); // Add sugar
    vm2->COFFEE(); //display coffee and sugar
    vm2->COIN(10.5);
    vm2->CANCEL();// should reset the balance
    vm2->CREAM(); // should print nothing as in Idle State
    vm2->COIN(10.5);
    vm2->CREAM();
    vm2->CREAM();// should remove the cream
    vm2->COFFEE(); // dispose coffee without cream
    vm2->COIN(10.5); // should return the coins as we are in NoCups

    delete af2;
    delete op;
    delete mda;
    delete vm2;
}

void testAll() {

    cout<<"Test Scenario VM1\n";
    testScenario_VM1();

    cout<<"Test Scenario VM2\n";
    testScenario_VM2();
}