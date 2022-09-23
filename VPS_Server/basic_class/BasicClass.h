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

    // 初始化私有数据
    virtual void LocalInit() {};

    // 连接其他模块
    virtual void CombindInit() {};

    // 完成初始化（可能需要其他模块的数据）
    virtual void FinishInit() {};


    void DeInit();
    virtual void OnDeInit() {};


public:
    const ClassName& GetName() const { return m_name; }
private:
    ClassName m_name;
};

