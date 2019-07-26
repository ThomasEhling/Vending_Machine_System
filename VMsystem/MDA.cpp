//
// Created by thomas on 28/04/19.
//

#include <iostream>
#include "includes/MDA.hpp"
#include "includes/Globals.hpp"

// MDA with all states declared in the corrected MDA-EFSM
MDA::MDA(OP *op) {

    list<int> l ;
    for(int i=0; i<NB_ADD_ID; i++){
        l.push_back(0);
    }

    auto *sd = new StatesData(l);

    auto *ss = new StateStart(this, op, sd);
    auto *scn = new StateNoCups(this, op, sd);
    auto *si = new StateIdle(this, op, sd);
    auto *sci = new StateCoinInserted(this, op, sd);

    states.push_back(ss);
    states.push_back(scn);
    states.push_back(si);
    states.push_back(sci);

    current = states[0];
}// end MDA

// delete all states
MDA::~MDA() {
    for (int i = 0; i < states.size(); ++i) {
        if (states[i]) {
            delete states[i];
        }
    }
}// end MDA

void MDA::changeState(states_e stateID) {
    switch (stateID) {
        case START:
            current = states[0];
            break;
        case NO_CUPS:
            current = states[1];
            break;
        case IDLE:
            current = states[2];
            break;
        case COIN_INSERTED:
            current = states[3];
            break;
        default:
            break;
    }
}// end ChangeState


// define all states :

// Start start
void StateStart::create() {
#ifdef DEBUG_MODE
    cout << "State Start : CREATE" << endl;
#endif
    context->changeState(NO_CUPS);
    op->StorePrice();
}

// No Cups State
void StateNoCups::coin(int f) {
#ifdef DEBUG_MODE
    cout << "State NoCups : COIN" << endl;
#endif
    op->ReturnCoins();
}

void StateNoCups::insert_cups(int n) {
#ifdef DEBUG_MODE
    cout << "State NoCups : INSERT_CUPS" << endl;
#endif
    if (n > 0) {
        context->changeState(IDLE);
        sd->setK(n);
        op->ZeroCF();
    }
    int nb = sd->getK();
    cout << "Number of Cups : " << nb << endl;
}

// Idle State
void StateIdle::coin(int f) {
#ifdef DEBUG_MODE
    cout << "State Idle : COIN" << endl;
#endif
    if (f == 1) {
        context->changeState(COIN_INSERTED);

        // reset additive list
        list<int> l ;
        for(int i=0; i<NB_ADD_ID; i++){
            l.push_back(0);
        }
        sd->setA(l);

    }
    op->IncreaseCF();
}

void StateIdle::insert_cups(int n) {
#ifdef DEBUG_MODE
    cout << "State Idle : INSERT_CUPS" << endl;
#endif
    if (n > 0) {
        sd->setK(sd->getK() + n);
    }
    int nb = sd->getK();
    cout << "Number of Cups : " << nb << endl;
}

void StateIdle::set_price() {
#ifdef DEBUG_MODE
    cout << "State Idle : SET_PRICE" << endl;
#endif
    op->StorePrice();
}

void StateIdle::card() {
#ifdef DEBUG_MODE
    cout << "State Idle : CARD" << endl;
#endif
    context->changeState(COIN_INSERTED);
    // reset additive list
    list<int> l ;
    for(int i=0; i<NB_ADD_ID; i++){
        l.push_back(0);
    }
    sd->setA(l);
    op->ZeroCF();
}

// CoinInserted State
void StateCoinInserted::coin(int f) {
#ifdef DEBUG_MODE
    cout << "State CoinInserted : COIN" << endl;
#endif
    op->ReturnCoins();
}

void StateCoinInserted::additive(int id) {
#ifdef DEBUG_MODE
    cout << "State CoinInserted : ADDITIVE" << endl;
#endif
    list<int> a = sd->getA();
    int counter = 0;
    list<int>::iterator it;
    for(it = a.begin(); it != a.end(); ++it){
        if (counter == id) {
            if(*it){
                *it = 0;
            }else{
                *it = 1;
            }
        }
        counter++;
    }
    sd->setA(a);

    cout<<"List of Current Additives : ";
    counter = 0;
    bool found = false;
    for (int &it : a) {
        if (counter == SUGAR_ID && it) {
            cout << " SUGAR ";
            found = true;
        } else if (counter == CREAM_ID && it) {
            cout << " CREAM ";
            found = true;
        }
        counter++;
    }
    if(found){
        cout<<endl;
    }else{
        cout<<" None "<<endl;
    }

}

void StateCoinInserted::dispose_drink(int id) {
#ifdef DEBUG_MODE
    cout << "State CoinInserted : DISPOSE DRINK" << endl;
#endif
    if (sd->getK() <= 1) {
        context->changeState(NO_CUPS);
    } else {
        context->changeState(IDLE);
        sd->setK(sd->getK() - 1);
        op->ZeroCF();
    }
    op->DisposeDrink(id);
    op->DisposeAdd(sd->getA());
}

void StateCoinInserted::cancel() {
#ifdef DEBUG_MODE
    cout << "State CoinInserted : Cancel" << endl;
#endif
    cout<<"Cancel the transaction"<<endl;
    context->changeState(IDLE);
    op->ReturnCoins();
    op->ZeroCF();
}


//Decentralized State Pattern :our MDA call State to perform the action
void MDA::create() {
    current->create();
}

void MDA::insert_cups(int n) {
    current->insert_cups(n);
};

void MDA::coin(int f) {
    current->coin(f);
};

void MDA::card() {
    current->card();
};

void MDA::cancel() {
    current->cancel();
};

void MDA::set_price() {
    current->set_price();
};

void MDA::dispose_drink(int id) {
    current->dispose_drink(id);
};

void MDA::additive(int id) {
    current->additive(id);
};
