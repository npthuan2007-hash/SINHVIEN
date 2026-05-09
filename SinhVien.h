#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>


class SinhVien {
protected:
    int maSo, tongTC;
    std::string hoTen;
    std::string diaChi;
    double diemTB;
public:
    SinhVien();
    SinhVien(int, std::string, std::string, int, double);
    virtual ~SinhVien();
    virtual void nhap();
    virtual void xuat();
    virtual double getDTB() = 0;   
    virtual int getSoTC() = 0; 
    virtual bool totNghiep() = 0;
};

class SVCaoDang: public SinhVien {
private:
    double diemThiTN;
public: 
    void nhap() override;
    void xuat() override;
    double getDTB() override;
    int getSoTC() override;
    bool totNghiep() override;
};

class SVDaiHoc: public SinhVien {
private: 
    std::string tenLuanVan;
    double diemLuanVan;
public:
    void nhap() override;
    void xuat() override;
    double getDTB() override;
    int getSoTC() override;
    bool totNghiep() override;
};
#endif