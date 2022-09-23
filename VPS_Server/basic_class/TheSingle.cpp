#include "TheSingle.h"


TheSingle* ins_single;

TheSingle* TheSingle::GetInstance() {
    if (!ins_single) {
        ins_single = new TheSingle();
    }
    return ins_single;
}

void TheSingle::InitInsClass() {
    std::lock_guard<std::mutex> _t(m_mtx);

    for (auto& itor : m_create_f) {
        auto new_obj = itor();
        m_ins_obsj.emplace(new_obj->GetName(), new_obj);
        LOG(INFO) << "Class:" << new_obj->GetName() << "Init";
    }

    for (auto& itor : m_ins_obsj) {
        itor.second->LocalInit();
    }

    for (auto& itor : m_ins_obsj) {
        itor.second->CombindInit();
    }

    for (auto& itor : m_ins_obsj) {
        itor.second->FinishInit();
    }
}

void TheSingle::DeinitInsClass() {
    std::lock_guard<std::mutex> _t(m_mtx);
    for (auto& itor : m_ins_obsj) {
        itor.second->DeInit();
    }
}

TheSingle::TheSingle() {

}