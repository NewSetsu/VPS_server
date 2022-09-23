#include "BasicClass.h"

BasicClass::BasicClass(const ClassName& name) : m_name(name) {
}

BasicClass::~BasicClass() {
}

//void BasicClass::ComplexInit() {
//    this->LocalInit();
//    this->CombindInit();
//    this->FinishInit();
//}

void BasicClass::DeInit() {
    OnDeInit();
}
