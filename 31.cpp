#include<iostream>
using namespace std;
class phanso
{
private:
    int tu,mau;
public:
    phanso();
    phanso(int tu,int mau);
    phanso(int a);
    phanso(const phanso &p);
    void nhap();
    void xuat();
    int lay_tu();
    int lay_mau();
    void gan_tu(int a);
    void gan_mau(int a);
    void nghich_dao();
    void rut_gon();
    phanso operator+(phanso &a);
	phanso operator-(phanso &a);
    phanso operator/(phanso &a);
    phanso operator*(phanso &a);
};
phanso::phanso()
{
    this->tu = 0;
    this->mau = 1;
}
phanso::phanso(int tu,int mau)
{
    this->tu = tu;
    this->mau = mau;
}
phanso::phanso(int a)
{
    this->tu = a;
    this->mau = 1;
}
phanso::phanso(const phanso &p)
{
    this->tu = p.tu;
    this->mau = p.mau;
}
void phanso::nhap()
{
	cout << "Nhap tu so:" ; cin >> tu;
    cout << "Nhap mau so:"; cin >> mau;
    while(mau==0)
    {
        cout << "mau so phai khac 0." <<endl;
        cout << "Nhap mau so:" ; cin >> mau;
    }
}
void phanso::xuat()
{
	if(mau==1)
	{
		cout << tu << endl;
		return;
	}
	if(mau==-1)
	{
		cout << -tu << endl;
		return;
	}
	if(tu==0)
	{
		cout << 0 << endl;
		return;
	}
	if(mau<0) cout << -tu << "/" << -mau <<endl;
	else cout << tu << "/" << mau << endl;
}
int phanso::lay_tu()
{
    return this->tu;
}
int phanso::lay_mau()
{
    return this->mau;
}
void phanso::gan_tu(int a)
{
    this->tu = a;
}
void phanso::gan_mau(int a)
{
    this->mau = a;
}
void phanso::nghich_dao()
{
    if(tu==0)
    {
        cout << "phan so khong the nghich dao."<<endl;
        return;
    }
    int temp = tu;
        tu = mau;
        mau = temp;
}
int UCLN(int A, int B) {
    if (B == 0)
        return A;
    return UCLN(B, A%B);
}
void phanso::rut_gon()
{
    int ucln = UCLN(tu,mau);
    tu/=ucln;
    mau/=ucln;
}
phanso phanso::operator+(phanso &a)
{
	phanso c(tu*a.mau+a.tu*mau,mau*a.mau);
	c.rut_gon();
	return c;
}
phanso phanso::operator-(phanso &a)
{
	phanso c(tu*a.mau-a.tu*mau,mau*a.mau);
	c.rut_gon();
	return c;
}
phanso phanso::operator*(phanso &a)
{
    int t_tu = tu*a.tu;
    int t_mau = mau*a.mau;
    phanso c(t_tu,t_mau);
    c.rut_gon();
    return c;
}
phanso phanso::operator/(phanso &a)
{
    if(a.tu==0)
    {
        cout << "khong the thuc hien phep chia." << endl;
        return phanso();
    }
    int t_tu = tu*a.mau;
    int t_mau = mau*a.tu;
    phanso c(t_tu,t_mau);
    c.rut_gon();
    return c;
}
int main()
{
    phanso a;
    a.nhap();
    a.xuat();
    a.nghich_dao();
    cout << "phan so sau khi nghich dao:" ; a.xuat();
    a.rut_gon();
    cout << "phan so sau khi rut gon: " ; a.xuat();
    phanso b(10,3);
    cout << "a + b =" ; (a+b).xuat();
    cout << "a - b =" ; (a-b).xuat();
    cout << "a * b =" ; (a*b).xuat();
    cout << "a / b =" ; (a/b).xuat();
    return 0;
}
