#include<iostream>
#include<cmath>
#include<complex>
using namespace std;

 class numar_complex
{
    private:
    double *v;
    public:

    numar_complex()//constrcutor initializare 1
    {
        v=new double[2];
        v[1]=0;
        v[2]=0;
    }
    numar_complex(double a, double b)//constructor initializare 2
    {
        v=new double[2];

        set_real(a);
        set_imag(b);

    }
    numar_complex(const numar_complex & ob)//constructor copiere
    {
        v[1]=ob.v[1];
        v[2]=ob.v[2];
    }
    ~numar_complex()//destructor
    {
        delete []v;
    }
    void set_real(double a);
    void set_imag(double b);
    double furniz_real();
    double furniz_imag();
    void afisare();
    double modul ();

    numar_complex operator + (const numar_complex & c);
    numar_complex operator * (const numar_complex & c);
    numar_complex operator / (const numar_complex & c);
    friend  istream &operator >> (istream &os, numar_complex &ob);
    friend ostream &operator <<(ostream &os, numar_complex &ob);
    template <class numar_complex> complex<numar_complex>sqrt(const complex<numar_complex>& z);



};

ostream &operator <<(ostream &os, numar_complex &ob)
{
    if (ob.v[1] && ob.v[2])
     {
         os<<ob.v[1];
         if (ob.v[2]<0)
            os<<"-i*"<<ob.v[2]*-1<<endl;
         else
            os<<"+i*"<<ob.v[2]<<endl;
     }

        if(ob.v[1]==0 && ob.v[2])
     {
         if (ob.v[2]<0)
            os<<"-i*"<<ob.v[2]*-1<<endl;
         else
            os<<"i*"<<ob.v[2]<<endl;
     }
     if (ob.v[2]==0 && ob.v[1])
        os<<ob.v[1]<<endl;
     if(!ob.v[1] && !ob.v[2])
        os<<0<<endl;
        return os;
}
istream &operator >> (istream &os, numar_complex &ob)
{

    os>>ob.v[1];

        os>>ob.v[2];
    return os;
}

numar_complex numar_complex:: operator / (const numar_complex & c)
{
    numar_complex nou;
    //(a+bi)/(c+di)=(a+bi)(c-di)/(c*c+d*d)

    double numitor;
    numitor=c.v[1]*c.v[1]+c.v[2]*c.v[2];
    c.v[2]*=-1;
    nou.v[1]=v[1]*c.v[1]-v[2]*c.v[2];
    nou.v[2]=v[1]*c.v[2]+v[2]*c.v[1];
    nou.v[1]=nou.v[1]/numitor;
    nou.v[2]=nou.v[2]/numitor;
    return nou;
}

numar_complex numar_complex:: operator * (const numar_complex & c)
{
    numar_complex nou;
    //(a+bi)(c+di)=ac+adi+bci-bd
    nou.v[1]=v[1]*c.v[1]-v[2]*c.v[2];
    nou.v[2]=v[1]*c.v[2]+v[2]*c.v[1];
    return nou;

}
 numar_complex numar_complex:: operator + (const numar_complex & c)
 {

     numar_complex nou;
     nou.v[1]=v[1]+c.v[1];
     nou.v[2]=v[2]+c.v[2];
     return nou;

 }
double numar_complex :: modul()
{
    double s;
    s=v[1]*v[1] + v[2]*v[2];
    return pow(s,0.5);
}
void numar_complex:: set_real (double a)
{
    v[1]=a;
}
void numar_complex:: set_imag (double b)
{
    v[2]=b;
}
 double numar_complex:: furniz_real()
 {
     return v[1];
 }

 double numar_complex:: furniz_imag()
 {
     return v[2];
 }

 void numar_complex ::afisare()
 {
     if (v[1] && v[2])
     {
         cout<<v[1];
         if (v[2]<0)
            cout<<"-i*"<<v[2]*-1<<endl;
         else
            cout<<"+i*"<<v[2]<<endl;
     }

        if(v[1]==0 && v[2])
     {
         if (v[2]<0)
            cout<<"-i*"<<v[2]*-1<<endl;
         else
            cout<<"i*"<<v[2]<<endl;
     }
     if (v[2]==0 && v[1])
        cout<<v[1]<<endl;
     if(!v[1] && !v[2])
        cout<<0<<endl;

 }

 void ecuatie(double a, double b, double c)
 {
      double delta=b*b-4*a*c;
     //discutie dupa delta
     if (delta==0)
        cout<<"x1=x2="<<double(-b/2*a);
     else
        if(delta>0)
        {cout<<"x1="<<double((-b+sqrt(delta))/2*a)<<endl;
        cout<<"x2="<<double((-b-sqrt(delta))/2*a);
        }
        else
        {
            numar_complex x1(double(-b/2*a),sqrt(-delta)/2*a),x2(double(-b/2*a),-sqrt(-delta)/2*a);
            cout<<"x1="<<x1;
            cout<<"x2="<<x2;
        }

 }
 int main()
 {
     numar_complex a(5,2),b(1,-2);
     cout<<sqrt(complex<double>(-9, 0))<<endl;
     cout<<"probez citire:(a,b)"<<endl;
     numar_complex nr;
     cin>>nr;
     cout<<"sa speram ca merge";
     nr.afisare();
     cout<<"afisez a si b: "<<endl;
     a.afisare();
     b.afisare();
     cout<<a.furniz_real()<<" "<<a.furniz_imag();
     cout<<endl<<a.modul();
     cout<<endl;
     (a+b).afisare();
     (a*b).afisare();
     (a/b).afisare();

    // numar_complex a,b,c,delta;
     //ecuatie de gradul 2: ax^2+bx+c=0, a,b,c e C;
/*
     double a,b,c;
     cout<<"Citeste a pentru ecutatie ";
     cin>>a;
     cout<<"Citeste b pentru ecutatie ";
     cin>>b;
     cout<<"Citeste c pentru ecutatie ";
     cin>>c;

     ecuatie(a,b,c);
*/

 }

