#pragma once

#include "BasicClass.h"

// �����ٵ�ʹ�õ������ģʽ
// �����Ҫʹ�����Ƶ����Ľṹ���̳�BasicClass ��ͨ�����Ψһ�������г�ʼ���������Ĺ���
class TheSingle {
public:
    ~TheSingle() {}
    TheSingle();

    static TheSingle* GetInstance();

public:
    void InitInsClass();
    void DeinitInsClass();
    
    template<typename T, typename... Args>
    void RegClass(Args&&... args) {
        std::lock_guard<std::mutex> _t(m_mtx);
        m_create_f.push_back([=]() -> sptr<BasicClass> {
            return sptr<BasicClass>(new T(args...));
            });
    }

    const sptr<BasicClass> GetClass(const std::string& name) {
        std::lock_guard<std::mutex> _t(m_mtx);
        if (m_ins_obsj.count(name) == 0) {
            LOG(ERROR) << "Can't get class: " << name;
            return nullptr;
        }
        return m_ins_obsj.at(name);
    }


private:
    std::vector<std::function<sptr<BasicClass>()>> m_create_f;
    dict<ClassName, sptr<BasicClass>> m_ins_obsj;

private:
    std::mutex m_mtx;
};

template<typename T>
class ObjectCreator {
public:
    template<typename... Args>
    ObjectCreator(Args&&... args) {
        TheSingle::GetInstance()->RegClass<T>(args...);
    }
};

template<typename T>
sptr<T> GetClass(const std::string& name) {
    return std::dynamic_pointer_cast<T>(TheSingle::GetInstance()->GetClass(name));
}

#define DECLARE_OBJ(type) auto _x##type = ObjectCreator<type>();