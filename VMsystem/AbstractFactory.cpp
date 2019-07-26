//
// Created by thomas on 28/04/19.
//

#include <cstddef>
#include "includes/AbstractFactory.hpp"

// init all our caches to NULL
AbstractFactory::AbstractFactory() :
        cacheDS(nullptr), cacheSP(nullptr), cacheZCF(nullptr), cacheICF(nullptr), cacheRC(nullptr), cacheDD(nullptr),
        cacheDA(nullptr) {
}// end AbstractFactory

// AbstractFactory does not hadnle the destruction of these variables.
AbstractFactory::~AbstractFactory() {
}// end AbstractFactory


// Init the datastores so there is only one instance for OP and AbstractFactory both
DataStore *Fact_VM_1::createDS() {
    if (!cacheDS) {
        cacheDS = new DS_1();
    }
    return cacheDS;
}// end Fact_VM_1

DataStore *Fact_VM_2::createDS() {
    if (!cacheDS) {
        cacheDS = new DS_2();
    }
    return cacheDS;
} // Fact_VM_2

// --- init all operations for the right class :
A_StorePrice *Fact_VM_1::createSP() {
    if (!cacheSP) {
        cacheSP = new Storeprice_Int();
    }
    return cacheSP;
}// end Fact_VM_1

A_StorePrice *Fact_VM_2::createSP() {
    if (!cacheSP) {
        cacheSP = new Storeprice_Float();
    }
    return cacheSP;
} // Fact_VM_2

A_ZeroCF *Fact_VM_1::createZCF() {
    if (!cacheZCF) {
        cacheZCF = new ZeroCF_Int();
    }
    return cacheZCF;
}// end Fact_VM_1

A_ZeroCF *Fact_VM_2::createZCF() {
    if (!cacheZCF) {
        cacheZCF = new ZeroCF_Float();
    }
    return cacheZCF;
} // Fact_VM_2

A_IncreaseCF *Fact_VM_1::createICF() {
    if (!cacheICF) {
        cacheICF = new IncreaseCF_Int();
    }
    return cacheICF;
}// end Fact_VM_1

A_IncreaseCF *Fact_VM_2::createICF() {
    if (!cacheICF) {
        cacheICF = new IncreaseCF_Float();
    }
    return cacheICF;
} // Fact_VM_2

A_ReturnCoins *Fact_VM_1::createRC() {
    if (!cacheRC) {
        cacheRC = new ReturnCoins_Int();
    }
    return cacheRC;
}// end Fact_VM_1

A_ReturnCoins *Fact_VM_2::createRC() {
    if (!cacheRC) {
        cacheRC = new ReturnCoins_Float();
    }
    return cacheRC;
} // Fact_VM_2

A_DisposeDrink *Fact_VM_1::createDD() {
    if (!cacheDD) {
        cacheDD = new DisposeDrink_1();
    }
    return cacheDD;
}// end Fact_VM_1

A_DisposeDrink *Fact_VM_2::createDD() {
    if (!cacheDD) {
        cacheDD = new DisposeDrink_2();
    }
    return cacheDD;
} // Fact_VM_2

A_DisposeAdd *Fact_VM_1::createDA() {
    if (!cacheDA) {
        cacheDA = new DisposeAdd_1();
    }
    return cacheDA;
}// end Fact_VM_1

A_DisposeAdd *Fact_VM_2::createDA() {
    if (!cacheDA) {
        cacheDA = new DisposeAdd_2();
    }
    return cacheDA;
} // Fact_VM_2

