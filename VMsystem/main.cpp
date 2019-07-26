#include<iostream>
#include <string>
#include "includes/VM.hpp"
#include "test/scenario.hpp"
#include "includes/AbstractFactory.hpp"

using namespace std;

void clearScreen(){
  cout << string( 1, '\n' );
}// end clearScreen


void print_menu(char vm_id) {
    if (vm_id == '1') {
        cout << " Vending Machine-1" << endl;
        cout << " MENU of Operations" << endl;
        cout << " 0. create(int)" << endl;
        cout << " 1. coin(int)" << endl;
        cout << " 2. sugar()" << endl;
        cout << " 3. tea()" << endl;
        cout << " 4. chocolate()" << endl;
        cout << " 5. insert_cups(int)" << endl;
        cout << " 6. set_price(int)" << endl;
        cout << " 7. cancel()" << endl;
        cout << " 8. card(float)" << endl;
        cout << " q. Quit the demo program" << endl;
        cout << " Please make a note of these operations" << endl;
        cout << " Vending Machine-1 Execution" << endl;
    } else if (vm_id == '2') {
        cout << " Vending Machine-2" << endl;
        cout << " MENU of Operations" << endl;
        cout << " 0. CREATE(float)" << endl;
        cout << " 1. COIN(float)" << endl;
        cout << " 2. SUGAR()" << endl;
        cout << " 3. COFFEE()" << endl;
        cout << " 4. CREAM()" << endl;
        cout << " 5. InsertCups(int)" << endl;
        cout << " 6. SetPrice(float)" << endl;
        cout << " 7. CANCEL()" << endl;
        cout << " q. Quit the demo program" << endl;
        cout << " Please make a note of these operations" << endl;
        cout << " Vending Machine-2 Execution" << endl;
    }

}


int main() { // partial driver
#ifdef TEST_MODE
    testAll();
#else
    char key = '\0';

    while (key != 'q') {

        cout << " Enter 1 for VM1 or 2 for VM2  or q to quit: "<<endl;
        cin >> key;

        print_menu(key);

        if (key == '1') { // VM_1
            // ponters

            auto *af1 = new Fact_VM_1();

            // initialize OP here, there is no direct contradiction to it
            auto *op = new OP(af1);

            auto *mda = new MDA(op);
            auto *vm1 = new  VM_1(af1, mda);
            op->init();
            vm1->init();

            // variables
            int p, v, n;
            float x;

            char ch = '\0';
            while (ch != 'q') {
                clearScreen();
                cout << " Select Operation: " << endl;

                cout << "0-create,1-coin,2-sugar,3-tea,4-chocolate,5-insert_cups,6-set_price,7-cancel,8-card,q-quit"
                     << endl;
                cin >> ch;
                cout << "number entered : " << ch << endl;
                switch (ch) {
                    case '0': //create
                        cout << " Operation: create(int p)" << endl;
                        cout << " Enter value of parameter p:" << endl;
                        cin >> p;
                        vm1->create(p);
                        break;
                    case '1'://coin
                        cout << " Operation: coin(int v)" << endl;
                        cout << " Enter value of parameter v:" << endl;
                        cin >> v;
                        vm1->coin(v);
                        break;
                    case '2': //sugar
                        cout << " Operation: sugar()" << endl;
                        vm1->sugar();
                        break;

                    case '3': // tea
                        cout << " Operation: tea()" << endl;
                        vm1->tea();
                        break;
                    case '4': // chocolate
                        cout << " Operation: chocolate()" << endl;
                        vm1->chocolate();
                        break;
                    case '5': // insert_cups
                        cout << " Operation: insert_cups(int n)" << endl;
                        cout << " Enter value of parameter n:" << endl;
                        cin >> n;
                        vm1->insert_cups(n);
                        break;
                    case '6': // set_price
                        cout << " Operation: set_price(int p)" << endl;
                        cout << " Enter value of parameter p:" << endl;
                        cin >> p;
                        vm1->set_price(p);
                        break;
                    case '7': // cancel
                        cout << " Operation: cancel()" << endl;
                        vm1->cancel();
                        break;
                    case '8': // card
                        cout << " Operation: card(float x)" << endl;
                        cout << " Enter value of parameter x:" << endl;
                        cin >> x;
                        vm1->card(x);
                        break;
                    case 'q': // quit
                        cout << "Quit VM_1" << endl;
                        break;
                    default:
                        cout << " Operation: Unknown" << endl;
                        break;

                };// endswitch
            }; //endwhile

            delete af1;
            delete vm1;


        } else if (key == '2') { // VM_2

            // pointers
            auto *af2 = new Fact_VM_2();

            // initialize OP here, there is no direct contradiction to it
            auto *op = new OP(af2);

            auto *mda = new MDA(op);
            auto *vm2 = new VM_2(af2, mda);
            op->init();
            vm2->init();

            // variables
            int n;
            float p, v, x;

            char ch = '\0';
            while (ch != 'q') {
                clearScreen();
                cout << " Select Operation: " << endl;

                cout << "0-CREATE,1-COIN,2-SUGAR,3-CREAM,4-COFFEE,5-InsertCups,6-SetPrice,7-CANCEL,q-quit" << endl;
                cin >> ch;
                cout << "number entered : " << ch << endl;
                switch (ch) {
                    case '0': //CREATE
                        cout << " Operation: CREATE(float p)" << endl;
                        cout << " Enter value of parameter p:" << endl;
                        cin >> p;
                        vm2->CREATE(p);
                        break;
                    case '1'://coin
                        cout << " Operation: COIN(float v)" << endl;
                        cout << " Enter value of parameter v:" << endl;
                        cin >> v;
                        vm2->COIN(v);
                        break;
                    case '2': //sugar
                        cout << " Operation: SUGAR()" << endl;
                        vm2->SUGAR();
                        break;

                    case '3': // cream
                        cout << " Operation: CREAM()" << endl;
                        vm2->CREAM();
                        break;
                    case '4': // COFFEE
                        cout << " Operation: COFFEE()" << endl;
                        vm2->COFFEE();
                        break;
                    case '5': // InsertCups
                        cout << " Operation: insert_cups(int n)" << endl;
                        cout << " Enter value of parameter n:" << endl;
                        cin >> n;
                        vm2->InsertCups(n);
                        break;
                    case '6': // SetPrice
                        cout << " Operation: SetPrice(float p)" << endl;
                        cout << " Enter value of parameter p:" << endl;
                        cin >> p;
                        vm2->SetPrice(p);
                        break;
                    case '7': // CANCEL
                        cout << " Operation: CANCEL()" << endl;
                        vm2->CANCEL();
                        break;
                    case 'q': // quit
                        cout << "Quit VM_1" << endl;
                        break;
                    default:
                        cout << " Operation: Unknown" << endl;
                        break;
                };// endswitch
            }; //endwhile

            delete af2;
            delete vm2;
        }//endif
    };//endwhile
#endif
    return 0;
};