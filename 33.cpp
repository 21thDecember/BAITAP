#include<iostream>
using namespace std;
class HS
{
private:
    string hoten;
    float d_toan,d_van;
public:
    HS(string hoten="",float d_van=0,float d_toan=0);
    HS(const HS &a);
    ~HS();
    void nhap();
    void xuat();
    void gan_toan(float a);
    void gan_van(float a);
    void gan_hoten(string a);
    string lay_hoten();
    float lay_toan();
    float lay_van();
    float TB();
    string xeploai();
};
HS::HS(string hoten,float d_van,float d_toan)
{
    this->hoten = hoten;
    this->d_van = d_van;
    this->d_toan = d_toan;
}
HS::HS(const HS &a)
{
    this->hoten = a.hoten;
    this->d_toan = a.d_toan;
    this->d_van = a.d_van;
}
void HS::nhap()
{
    cout << "Nhap ho va ten hs:" ; cin >> hoten;
    cout << "Nhap diem toan:" ; cin >> d_toan;
    cout << "Nhap diem van:" ; cin >> d_van;
}
void HS::xuat()
{
    cout << "Ho va ten: " << hoten <<endl;
    cout << "Diem toan: " << d_toan << endl;
    cout << "Diem van: " << d_van << endl;
}
void HS::gan_hoten(string a)
{
    hoten = a;
}
void HS::gan_toan(float a)
{
    d_toan = a;
}
void HS::gan_van(float a)
{
    d_van = a;
}
string HS::lay_hoten()
{
    return this->hoten;
}
float HS::lay_toan()
{
    return this->d_toan;
}
float HS::lay_van()
{
    return this->d_van;
}

float HS::TB()
{
    return (d_toan+d_van)/2;
}
string HS::xeploai()
{
    if(this->TB()>=8) return "Gioi";
    if(this->TB()>=7) return "Kha";
    if(this->TB()>=5) return "TB";
    return "Yeu";
}
HS::~HS() 
{
	cout << "Deleted" << endl;
}
int main()
{
    HS a;
    a.nhap();
    cout << "Xep loai: " << a.xeploai() << endl;
    a.gan_toan(10);
    a.gan_van(10);
    a.xuat();
    return 0;
}
