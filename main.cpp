#include "SinhVien.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
    cout << "Nhap so sinh vien Cao Dang: ";
    int nCD; cin >> nCD;
    cout << '\n';
    vector<SinhVien*> ds;
    for (int i = 0; i < nCD; i++) {
        SinhVien* cd = new SVCaoDang;
        cout << "Nhap sinh vien Cao Dang thu " << i + 1 << ": ";
        cd->nhap();
        ds.push_back(cd);
        cout << '\n';
    }
    cout << "Nhap so sinh vien Dai Hoc: ";
    int nDH; cin >> nDH;
    cout << '\n';
    for (int i = 0; i < nDH; i++) {
        SinhVien* dh = new SVDaiHoc;
        cout << "Nhap sinh vien Dai Hoc thu " << i + 1 << ": ";
        dh->nhap();
        ds.push_back(dh);
        cout << '\n';
    }
    cout << "\nDanh Sach sinh vien DU DIEU KIEN TOT NGHIEP:\n";
    for (SinhVien* sv : ds) {
        if (sv->totNghiep()) {
            sv->xuat();
        }
    }
    int demCD = 0; int demDH = 0;
    cout << "\nDanh Sach sinh vien KHONG DU DIEU KIEN TOT NGHIEP:\n";
    for (SinhVien* sv : ds) {
        if (!sv->totNghiep()) {
            sv->xuat();
            if (dynamic_cast<SVCaoDang*>(sv)) {
                demCD++;
            }
            else demDH++;
        }
    }
    
    SinhVien* maxDH = nullptr;
    for (SinhVien* sv: ds) {
        SVDaiHoc* dh = dynamic_cast <SVDaiHoc*> (sv);
        if (dh != nullptr) {
            if (maxDH == nullptr || dh->getDTB() > maxDH->getDTB()) {
                maxDH = dh;
            }
        }
    }
    if (maxDH != nullptr) {
        cout << "\nSinh vien DAI HOC co DIEM TRUNG BINH cao nhat la: \n";
        maxDH->xuat();
    }
    else {
        cout << "Khong co sinh vien DAI HOC" << '\n';
    }
    SinhVien* maxCD = nullptr;
    for (SinhVien* sv : ds) {
        SVCaoDang* cd = dynamic_cast <SVCaoDang*> (sv);
        if (cd != nullptr) {
            if (maxCD == nullptr || maxCD-> getDTB() < cd -> getDTB()) {
                maxCD = cd;
            }
        }
    }
    cout << "\nSinh vien CAO DANG co DIEM TRUNG BINH cao nhat la: \n";
    if (maxCD != nullptr) {
        maxCD-> xuat();
    }
    else {
        cout << "Khong co sinh vien CAO DANG\n";
    }
    cout << "Tong sinh vien KHONG DU DIEU KIEN TOT NGHIEP he CAO DANG: " << demCD << endl;
    cout << "Tong sinh vien KHONG DU DIEU KIEN TOT NGHIEP he DAI HOC: " << demDH << endl;
    return 0;
}