#pragma once

#include "env/cpp_comon.h"

class TheSingle;

class BasicClass {
    friend class TheSingle;
public:
    explicit BasicClass(const ClassName& name);
    BasicClass(const BasicClass&) = delete;
    BasicClass(BasicClass&&) = delete;
    virtual ~BasicClass();

    // void ComplexInit();

    // ��ʼ��˽������
    virtual void LocalInit() {};

    // ��������ģ��
    virtual void CombindInit() {};

    // ��ɳ�ʼ����������Ҫ����ģ������ݣ�
    virtual void FinishInit() {};


    void DeInit();
    virtual void OnDeInit() {};


public:
    const ClassName& GetName() const { return m_name; }
private:
    ClassName m_name;
};

