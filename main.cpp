#include <iostream>
#include<vector>
using namespace std;
class Lant{
protected:
    int id;
public:
    Lant(){id=0;}
    Lant(int i)
        {id=0;}
    ~Lant()
        {id=-1;}
    virtual void afisare(){cout<<id;}

    int get_id() {return id;}
    friend istream &operator>>(istream&in, Lant &l);

};
istream &operator>>(istream&in, Lant &l)
{
    int iD;
    cout<<"Id:"<<endl;
    in>>iD;
    l.id=iD;
    return in;
}
///Farmacie
class Farmacie: public Lant
{
protected:
    string denumire;
    unsigned int nr_angajati;
    float profit[12];
public:
    Farmacie();
    Farmacie( int id, string denumire, unsigned int nr_angajati, float profit[12]);
    Farmacie(const Farmacie& f);
    ~Farmacie();
    Farmacie operator=(const Farmacie &f);
    friend istream &operator>>(istream &i, Farmacie &f);
    void afisare();
};
Farmacie::Farmacie():Lant()
{
    nr_angajati=0;
    for(int i=0;i<12;i++)
        profit[i]=0;
}

Farmacie::Farmacie(int id, string den, unsigned int nr_ang, float prof[12]):Lant(id)
{
    denumire=den;
    nr_angajati=nr_ang;
    for(int i=0;i<12;i++)
        profit[i]=prof[i];
}
Farmacie::Farmacie(const Farmacie &f)
{
    this->id=f.id;
    this->denumire=f.denumire;
    this->nr_angajati=f.nr_angajati;
    for(int i=0;i<12;i++)
        this->profit[i]=f.profit[i];

}
Farmacie::~Farmacie()
{
    id=-1;
    denumire.clear();
    nr_angajati=-1;
    for(int i=0;i<12;i++)
    {
        profit[i]=-1;
    }
}

istream& operator>>(istream &in,Farmacie &f)
{
    try{
            int id;
            string denumire;
            unsigned int nr_angajati;       ///EXCEPTIE 0 ANGAJATI
            float profit[12];
            cout<<"Id, denumire, nr angajati, profit(ianuarie-decembrie);"<<endl;
            in>>id>>denumire>>nr_angajati;
            if(nr_angajati==0)
                throw 0;
            for(int i=0;i<12;i++)
                in>>profit[i];
            f.id=id;
            f.denumire=denumire;
            f.nr_angajati=nr_angajati;
            for(int i=0;i<12;i++)
                f.profit[i]=profit[i];

    }
    catch(int x)
    {
        cout<<"Farmacia nu poate avea 0 angajati.\n";
    }
    return in;

}
Farmacie Farmacie:: operator=(const Farmacie &f)
{
    this->id=f.id;
    this->denumire=f.denumire;
    this->nr_angajati=f.nr_angajati;
    for(int i=0;i<12;i++)
        this->profit[i]=f.profit[i];
    return *this;
}
void Farmacie::afisare()
{                                           ///EXCEPTIE 0 ANGAJATI
    try{
        if(nr_angajati==0)
            throw 0;
        else{
            cout<<"Id: "<<id<<endl;
            cout<<"Denumire: "<<denumire<<endl;
            cout<<"Nr angajati: "<<nr_angajati<<endl;
            cout<<"Profit:"<<endl;
            for(int i=0;i<12;i++)
                cout<<"Luna "<<i+1<<" profit "<<profit[i]<<endl;
    }
    }
    catch(int x)
    {
        cout<<"Farmacia are 0 angajati.\n";
    }


}


///ONLINE
class Farmacie_online: public Farmacie{
    string adresa_web;
    unsigned int nr_vizitatori;
    int discount;
public:
    Farmacie_online():Farmacie(){nr_vizitatori=0; discount=0;}
    Farmacie_online(int id, string den,unsigned int nr_ang,float prof[12],string adresa_web,unsigned int nr_vizitatori,int discout);
    ~Farmacie_online();
    Farmacie_online operator =(const Farmacie_online &fo);
    friend istream &operator >>(istream &in,Farmacie_online &fo);
    void afisare();
    unsigned int get_viz(){return nr_vizitatori;}
};
Farmacie_online::Farmacie_online(int id, string den,unsigned int nr_ang,float prof[12],string adresa_web,unsigned int nr_vizitatori,int discount):Farmacie(id,den, nr_ang, prof)
{
    this->adresa_web=adresa_web;
    this->nr_vizitatori=nr_vizitatori;
    this->discount=discount;
}
Farmacie_online::~Farmacie_online()
{
    id=-1;
    denumire.clear();
    nr_angajati=-1;
    for(int i=0;i<12;i++)
    {
        profit[i]=-1;
    }
    adresa_web.clear();
    nr_vizitatori=-1;
    discount=-1;
}
Farmacie_online Farmacie_online:: operator=(const Farmacie_online &fo)
{
    id=fo.id;
    denumire=fo.denumire;
    nr_angajati=fo.nr_angajati;
    for(int i=0;i<12;i++)
        profit[i]=fo.profit[i];
    adresa_web=fo.adresa_web;
    nr_vizitatori=fo.nr_vizitatori;
    discount=fo.discount;
    return *this;

}
istream &operator>>(istream &in, Farmacie_online &fo)
{
    string denumire,adresa_web;
    unsigned int nr_angajati,nr_vizitatori;
    int id,discount;
    float profit[12];
    cout<<"Id,denumire, nr angajati, profit(ianuarie-decembrie), adresa web, nr vizitatori, discount"<<endl;
    in>>id>>denumire>>nr_angajati;
    for(int i=0;i<12;i++)
        in>>profit[i];
    in>>adresa_web>>nr_vizitatori>>discount;
    fo.id=id;
    fo.denumire=denumire;
    fo.nr_angajati=nr_angajati;
    for(int i=0;i<12;i++)
        fo.profit[i]=profit[i];
    fo.nr_vizitatori=nr_vizitatori;
    fo.adresa_web=adresa_web;
    fo.discount=discount;
    return in;
}
void Farmacie_online::afisare()
{
    cout<<"Id: "<<id<<endl;
    cout<<"Denumire: "<<denumire<<endl;
    cout<<"Nr angajati: "<<nr_angajati<<endl;
    cout<<"Profit:"<<endl;
    for(int i=0;i<12;i++)
        cout<<"\t Luna "<<i+1<<" profit "<<profit[i]<<endl;
    cout<<"Adresa web: "<<adresa_web<<endl;
    cout<<"Nr vizitatori: "<<nr_vizitatori<<endl;
    cout<<"Discount: "<<discount<<endl;
}

///template
template<typename T>class GestionareFarmacii{
    static int index;
    T *v;
public:
    GestionareFarmacii(){index=0;v=NULL;}
   ~GestionareFarmacii()
   {
       delete[] v;
       index=-1;
   }
   GestionareFarmacii& operator +=(T&obj)
   {   int ID=obj.get_id();
       try{                             ///EXCEPTIE-> farmacie deja existenta(acelasi id)
           for(int i=0;i<index;i++)
           {
               if(v[i].get_id()==ID)
                throw 1;
           }

           index++;
           T *aux=v;
           v=new T[index];
           for(int i=0;i<index-1;i++)
               v[i]=aux[i];
           v[index-1]=obj;
       }
       catch(int x)
                {
                    cout<<"Farmacia exista deja in lista."<<endl;
                }
        return *this;
   }

   void afis()
   {
       try{
            if(index==0)
                throw 2;
            else
                {
                    for(int i=0;i<index;i++)
                    {   cout<<"Farmacia "<<i+1<<endl;
                        v[i].afisare();
                    cout<<endl;
                    }
                }
       }
       catch(int x)
       {
           cout<<"Lista de farmacii e goala."<<endl;

       }
   }

};

///specializare
template<>class GestionareFarmacii<unsigned>
{
     int nr_vizi;
public:
    GestionareFarmacii(){nr_vizi=0;}

    void inserare(Farmacie_online &obj) {
		nr_vizi+=obj.get_viz();
	}
	void afis_viz(){cout<<"Nr total de vizitatori: "<<nr_vizi<<endl;}
};


template<typename T>
int GestionareFarmacii<T>:: index=0;

int main()
{
    vector<Lant*>v;
    int x;
    for(int i=0;i<2;i++)
    {
        cin>>x;
        if(x==0)
            {
                Farmacie *f;
                f=new Farmacie;
                cin>>*f;
                v.push_back(f);

            }
        if(x==1)
            {
                Farmacie_online *fa;
                fa=new Farmacie_online;
                cin>>*fa;
                v.push_back(fa);
            }
    }
    for(int i=0;i<2;i++)
        v[i]->afisare();


    /*
    float p[12];
    for(int i=0;i<12;i++)
        cin>>p[i];                  ///clasa FARMACIE
    Farmacie t(40,"dona",10,p);

    Farmacie d,m;
    cin>>d;
    d.afisare();
    m=d;
    m.afisare();
    */


    /*
    float p[12];
    for(int i=0;i<12;i++)
        cin>>p[i];                  ///CLASA FARMACIE ONLINE
    Farmacie_online g,h;
    cin>>g;
    h=g;
    h.afisare();
        */


    /*
    Farmacie_online g;
    Farmacie f;
    cin>>f;
    cin>>g;                             ///TEMPLATE
    GestionareFarmacii<Farmacie> A;
    A+=g;
    A+=f;
    A.afis();
    */


    /*
    Farmacie_online f,g;
    cin>>f;                                  ///SPECIALIZARE
    cin>>g;
    GestionareFarmacii<unsigned>A;
    A.inserare(f);
    A.inserare(g);
    A.afis_viz();
    */

    /*
    Farmacie f;
    cin>>f;
    Lant &l=f;
    Farmacie *fa=dynamic_cast<Farmacie*>(&l);          ///DYNAMIC CAST
    fa->afisare();
    */
    return 0;
}
