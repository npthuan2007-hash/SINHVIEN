#include "SinhVien.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

SinhVien:: SinhVien() {
    maSo = diemTB = tongTC = 0;
    hoTen = diaChi = "";
}
SinhVien:: SinhVien(int maSo, string hoTen, string diaChi, int tongTC, double diemTB) {
    this-> maSo = maSo;
    this-> hoTen = hoTen;
    this-> diaChi = diaChi;
    this->tongTC = tongTC;
    this-> diemTB = diemTB;
}
SinhVien:: ~SinhVien() {}

void SinhVien:: nhap() {
    cout << "Nhap MSSV: "; cin >> maSo;
    cout << '\n';
    cout << "Nhap ho ten sinh vien: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap dia chi sinh vien: ";
    getline(cin, diaChi);
    cout << "Nhap tong so tin chi cua sinh vien: ";
    cin >> tongTC;
    cout << '\n';
    cout << "Nhap diem trung binh cua sinh vien: ";
    cin >> diemTB;
}
void SinhVien:: xuat() {
    cout << maSo << " " << hoTen << ". Dia chi: " << ". Tong so tin chi: " << tongTC << ". Diem trung binh: " << fixed << setprecision(2) << diemTB; 
}
void SVCaoDang:: nhap() {
    SinhVien:: nhap();
    cout << "Nhap diem thi tot nghiep: "; cin >> diemThiTN;
    cout << '\n';
}
void SVCaoDang:: xuat() {
    SinhVien:: xuat();
    cout << ". Diem thi tot nghiep: " << diemThiTN << '\n';
}
int SVCaoDang:: getSoTC() {
    return this->tongTC;
}
double SVCaoDang:: getDTB() {
    return this->diemTB;
}
bool SVCaoDang:: totNghiep() {
    return (this-> tongTC >= 120 && this-> diemThiTN >= 5 &&  this->diemTB >= 5);
}
void SVDaiHoc:: nhap() {
    SinhVien:: nhap();
    cout << "Nhap ten luan van: ";
    cin.ignore();
    getline(cin, tenLuanVan);
    cout << "\n";
    cout << "Nhap diem luan van: ";
    cin >> diemLuanVan;
}
void SVDaiHoc:: xuat() {
    SinhVien:: xuat();
    cout << ". Ten luan van: " << tenLuanVan << ". Diem luan van: " << diemLuanVan << endl;
}
double SVDaiHoc:: getDTB() {
    return this->diemTB;
}
int SVDaiHoc:: getSoTC() {
    return this->tongTC;
}
bool SVDaiHoc:: totNghiep() {
    return (this->tongTC >= 170 && this-> diemLuanVan >= 5 && this-> diemTB >= 5);
}