#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <string.h>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <stdexcept>

using namespace std;
//using std::setw;
ofstream f("vanzari.out");
template <class T>// definire template
class Stack {//definire clasa template
   private:
      vector<T> elemente;     // data membra  VECTORUL de elemnte de tip generic T

   public:
      void push(T const&);  // pune un element in varful stivei
      void pop();               // extrage un element din varful stivei
      T top() const;            // returneaza elementul din varful stivei
      bool empty() const{       // returneaza true daca stiva este vida
         return elemente.empty();
      }
};
// definirea metodelor tamplatului in afara acestor
template <class T>
void Stack<T>::push (T const& elem) {
   // adauga o copie a elementului transmis ca parametru
   elemente.push_back(elem);// apeleaza functia predefinita in containerul vector pushback
}

template <class T>
void Stack<T>::pop () {
   if (elemente.empty()) {
      throw out_of_range("Stack<>::pop(): stiva vida");
   }

   // extrage ultimul element
   elemente.pop_back();
}

template <class T>
T Stack<T>::top () const {
   if (elemente.empty()) {
      throw out_of_range("Stack<>::top(): empty stack");
   }

   // return copy of last element
   return elemente.back();
}
Stack<int>         intStack;  // stiva de preturi produse vandute
 Stack<string> stringStack;//stiva de nume produse vandute
 int S;
class Produse
{
public:
//enum {NEAGRA, DECAF,EXPRESOSC , EXPRESOLG, LATTEMACHIATO, NR_PRODUSE};
list <string> numeProduse;
static const int NR_PRODUSE=5;

Produse ()
{//constructor fara parametrii
  this->stmax.setCant(50);// seteaza stoc maxim la 50
  numeProduse.push_back("NEAGRA");// incarca in lista cu numele produselor
  numeProduse.push_back("DECAF");
  numeProduse.push_back("EXPRESO SCURT");
  numeProduse.push_back("EXPRESO LUNG");
  numeProduse.push_back("LATTE MACHIATO");
}
Produse(int a)// constructor cu un parametru intreg = alegere
{
alegere = a;// initializeaza data membra alegere cu valoarea parametrului
}

Produse(const char* s)
{// constructor cu parametru de tip poiner la char(sir de carcztere)
// cauta in lista cu denumirile de produse produsul cu numele precizat prin parametru
// si seteaza data membra alegere cu valoare indicelui produsului
for (int i = 0; i < NR_PRODUSE; ++i)
if (strcmp(numeP[i], s) == 0)
{
    alegere = i;
    return;// determina iesirea din functie
}
}
const char* toString() const {return numeP[alegere];}// formateaza afisarea unui produs
int pretProduse() const {return pret[alegere];}// returneaza pretul produsului coresp alegerii
operator int() const {return alegere;}// conversie explicita la int a alegeri
static int nr;// nr de obiecte
const int  &operator +=(int x)// operator supraincarcat, binar; creste cantitatea(stocul) cu valoarea x
{
    for (int i = 0; i < NR_PRODUSE; ++i)
    return this->st.setCant(x+this->st.getCant(i));
}
const int  &operator -=(int x)// idem doar ca o scade
{
    for (int i = 0; i < NR_PRODUSE; ++i)
    return this->st.setCant(this->st.getCant(i)-x);
}
friend istream& operator>>(istream& in, Produse& p)
{
     in >> setw(5) >> p.nr;// din fluxul de intrare in se preia nr

 return in;// in obiect de tip ifstream( flux de intrare)
}
friend ostream& operator<<(ostream& out, const Produse& p)
// operator<< supraincarcat printr-o functie prietena
// formateaza afisarea datei membre nr a obiectului p de tip produse
 {out <<"Nr produse="<< p.nr << "\n" ;
 return out;// in obiect de tip ofstream( flux de iesire)
}


const int  &operator -(int x)
{//  operator suprancatcat; scade stocurile prod cu cant x
    for (int i = 0; i < NR_PRODUSE; ++i)
    this->st.setCant(this->st.getCant(i)-x);
     return this->st.getCant(1);
}
const int  &operator +(int x)
{
    for (int i = 0; i < NR_PRODUSE; ++i)
     this->st.setCant(this->st.getCant(i)+x);
     return this->st.getCant(1);
}
 const int  &operator >(Produse x)
{// returneaza 1 daca exista un produs cu stocul mai mic decat stocul produsului x
    for (int i = 0; i < NR_PRODUSE; ++i)
    if( this->st.getCant(i)<x.st.getCant(i))
     return 1;
     return 0;
}
const int  &operator <(Produse x)
{
    for (int i = 0; i < NR_PRODUSE; ++i)
    if( this->st.getCant(i)>x.st.getCant(i))
     return 1;
     return 0;
}
const int  &operator <=(Produse x)
{
    for (int i = 0; i < NR_PRODUSE; ++i)
    if( this->st.getCant(i)>x.st.getCant(i))
     return 1;
     return 0;
}
const int  &operator &&(Produse x)
{// returneaza 0 daca exita un produs cu cantitatea 0
    for (int i = 0; i < NR_PRODUSE; ++i)
    if( this->st.getCant(i)*x.st.getCant(i)==0)
     return 0;
     return 1;
}
const int  &operator &(int x)//operator logic pe biti
{// si logic inte nr de produse si parametru
    nr=nr&x;
}
const int  &operator ||(Produse x)
{// returneaza 0 daca exista un produs inexistent, atat in stocul curent cat si in stocul corespunzator obiectului x de tip produse
    for (int i = 0; i < NR_PRODUSE; ++i)
    if(!( this->st.getCant(i)+x.st.getCant(i)))
     return 0;
     return 1;
}
const int  &operator *(int x)
{// inmulteste stocul fiecarui obiect cu valoarea parametrului
    for (int i = 0; i < NR_PRODUSE; ++i)
     this->st.setCant(this->st.getCant(i)*x);
     return this->st.getCant(1);
}
const int  &operator ++(int x)
{// operator de incrementare supraincarcat
    // incrementeaza toate stocurile cu valoarea parametrului
    for (int i = 0; i < NR_PRODUSE; ++i)
    return this->st.setCant(this->st.getCant(i)+x);
}
const int  &operator !()
{//returneaza 1 daca st este gol
    for (int i = 0; i < NR_PRODUSE; ++i)
    if( this->st.getCant(i)!=0)
     return 0;
return 1;
}
const int  &operator --(int x)
{
    for (int i = 0; i < NR_PRODUSE; ++i)
    return this->st.setCant(this->st.getCant(i)-x);
}
// inner clase
class stocuri
{public:


    stocuri()  //constructor implicit
    {
        cant=new int[NR_PRODUSE];// aloca dinamic spatiu pentru data membra cant de tip vector
        for (int i = 0; i < NR_PRODUSE; ++i)
           cant[i]=50;// initializeaza cantitatile initiale ale stocurilor cu valoarea 50
    }
    stocuri(int x)  //constr cu parametru
    {
        cant=new int[NR_PRODUSE];
        for (int i = 0; i < NR_PRODUSE; ++i)
           cant[i]=x;
    }
    stocuri (const stocuri & s)  //constr de copiere
    {
        cant=new int[NR_PRODUSE];
        for (int i = 0; i < NR_PRODUSE; ++i)
           cant[i]=s.cant[i];
    }
    ~stocuri()//  destructor
    {// elibereaza spatiul alocat datei membre cant
        delete cant;//printf ("\nApel destructor");
    }
    int getCant(int i)
    {// functie de tip getter returneaza cant produsului i
        return cant[i];
    }
    int setCant(int x)
    {// functie de tip setter, seteaza cantitatea produselor la valoarea parametrului
     for (int i = 0; i < NR_PRODUSE; ++i)
        // cant[i]=x;
        setCanti(x, i);
        return getCant(0);
    }
void setCanti(int x, int i)
    {
     //for (int i = 0; i < NR_PRODUSE; ++i)
         cant[i]=x;
    }
const int & operator [](int i)
{// operator de indexare supraincarcat
    // se trateaza cu ajutorul unui bloc try-catch
    // exceptia de depasire a numarului curent de produse
    // daca valoarea lui i depaseste numarul de produse se arunca exceptia cu valoarea i
    // altfel se returneaaza cantitatea produsului cu indicele i
    try
    {if(i>NR_PRODUSE)throw i;
        else return this->getCant(i);

    }
    catch(int i)
    {// daca a fost lansata exceptia se afiseaza measajul de mai jos:
        cout<<"Captare exceptie cu valoarea: "<<i<<"\n";


    }
}
const stocuri &operator =(stocuri *s)
{// operator = supraincarcat; returneaza un obiect de tip stocuri( copia parametrului)
    for (int i = 0; i < NR_PRODUSE; ++i)
    this->setCant(s->getCant(i));
    return *this;
}
const int &operator !=(stocuri s)
{// verifica non eggalitatea itner doua obiecte de tip stocuri
   // daca sunt diferite returneaza 1 daca nu returneaza 0
    for (int i = 0; i < NR_PRODUSE; ++i)
    if(this->getCant(i)==s.getCant(i))
    return 0;
    return 1;
}
 const stocuri operator-(const stocuri& s){

   for (int i = 0; i <NR_PRODUSE; ++i)
    setCanti( 200,i);
  }
   private:
    int *cant;// data membra pointer la int( la un tablou de intregi)

};

stocuri st, stmax;
private:
int alegere;

static int pret[NR_PRODUSE];
static const char* numeP[NR_PRODUSE];

};

// datele statice:
int Produse::pret[Produse::NR_PRODUSE] = {35,30,35,35,25};
const char* Produse::numeP[Produse::NR_PRODUSE] =
{
"NEAGRA", "DECAF", "EXPRESO SCURT", "EXPRESO LUNG", "LATTE MACHIATO"
};
int Produse::nr=0;//:: este operatorul de rezolutie


class Vanzare
{
public:
    Vanzare(){credit=0;}
Vanzare(int credit) {}// constructor fara parametrii seteaza creditul la 0

void depozit(int &cantitate)
{
credit += cantitate;// metoda a clasei creste creditul cu cantitatea data de parametru
cout<<"\tVanzare: S-au introdus  "<<cantitate<<" RON.";

cout<<"\tAveti  "<<credit<<" lei credit.\n";
}
void returnRest(int &cantitate)
{// metoda care afiseaza valoarea restului dupa ce a fost scazut din credit costul produsului
    // apoi repune creditul pe 0
cout<<"\tVanzare: Rest:  "<<credit<<" lei\n";
credit =credit-cantitate;
}
bool CreditSuficient(int &cantitate) const
{return credit >= cantitate;}// metoda care returneaza true daca creditul e mai mic decat valoarea solicitata
void scade(int &cantitate)
{// metoda care scade creditul cu valoarea parametrului si apeleaza metoda care returneaza restul
while(credit!=0){
credit -= cantitate;
returnRest(credit);
depozit(credit);
returnRest(credit);
}

}

private:
int credit;// data membra privata credit
};



class Preparare
{
public:

void prepara(const Produse& s)
{// metoda publica care afiseaza produsul care se prepara aepalnd metoda to string supraincarcat
cout<<"\tPreparare: Se prepara  "<<s.toString()<<"\n";
intStack.push(s.pretProduse());stringStack.push(s.toString());
// s-au introdus in stiva de intregi intstack respectiv stringStack pretul si denumirea produsului preparat
}

};



class Selectie:public Preparare// clasa aceasta mostenese pe preparare
{
public:
//Selectie(Vanzare* pV, Preparare* pP)
Selectie(Vanzare* pV)
{
pVanzare = pV;
//pPreparare = pP;
}

void selectie(const Produse& s)
{
int cantitate = s.pretProduse();
if (pVanzare->CreditSuficient(cantitate))
{
//pPreparare->prepara(s);
prepara(s);
pVanzare->scade(cantitate);
}
else
cout<<"\tSuma insuficienta. Mai introduceti...";
}

private:
Vanzare* pVanzare;
//Preparare* pPreparare;
};


void clrscr()
{
    system("@cls||clear");
}


void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
void genereazaRapoarte();

class Automat{
//virtual void say_something() = 0;
   virtual void Functionare() = 0;
   virtual void meniu()=0;
   protected: Produse *pp;
};
class AutomatCafea   :public Automat
{
public:
AutomatCafea()
{
    int cantitate;
    cout<<"\tVanzare: S-au introdus  "<<cantitate<<" RON.";

cout<<"\tAveti  "<<cantitate<<" lei credit.\n";
pVanzare = new Vanzare(cantitate);

pPreparare = new Preparare;
pp=new Produse;
//pSelectie = new Selectie(pVanzare, pPreparare);
pSelectie = new Selectie(pVanzare);
}

virtual void meniu()
{
            cout<< "\t==================================\n";

			cout<< "\t|         ";
			SetColor(13);
			cout<<"Automat de cafea       ";
			SetColor(10);cout<<"|\n";
			cout<< "\t|================================|\n";
			cout<< "\t| 0 Inserati monezile:           |\n";
			cout<< "\t|--------------------------------|\n";

			cout<< "\t|Selectati produsul:             |\n";
			cout<< "\t|--------------------------------|\n";
			/*cout<< "\t| 1  Cafea neagra                | \n";
			cout<< "\t| 2  Cafea decofeinizata         | \n";
			cout<< "\t| 3  Expresso scurt              | \n";
			cout<< "\t| 4  Expresso lung               |\n";
			cout<< "\t| 5  Caffe macchiato             | \n";
			*/
 list<string>::iterator i;int j=1;
         for ( i= pp->numeProduse.begin(); i != pp->numeProduse.end(); ++i)
        {cout <<"              "<<j++<<". " <<*i << endl;
			cout<< "\t|--------------------------------|\n";}
cout<< "\t==================================\n";


}

virtual void Functionare()
{
int ok=1;
while (ok)
{
SetColor(10);
clrscr();
this->meniu();SetColor(13);cout<<"          ";
int alegere;//scanf("%d", &alegere);
cin>>alegere;
if(alegere ==0)
{
int valoare;
cout<<"          ";
		//scanf("%d",&valoare);
		cin>>valoare;
pVanzare->depozit(valoare);getchar();getchar();
}
else
   if(alegere==100)ok=0;
   else if (alegere==50)genereazaRapoarte();
   else if(alegere<0||alegere >5)
   {
cout<<"Alegeti o optiune corecta...";getchar();getchar();
   }
else
  {char tip[30];getchar();
   switch(alegere)
    {
     case 1:strcpy(tip, "NEAGRA");break;
     case 2:strcpy(tip, "DECAF");break;
     case 3:strcpy(tip, "EXPRESO SCURT");break;
     case 4:strcpy(tip, "EXPRESO LUNG");break;
     case 5:strcpy(tip, "LATTE MACHIATO");break;
     }

    pSelectie->selectie(tip);f<<tip<<endl;
    getchar();
   }
}
}

private:
Vanzare* pVanzare;
Preparare* pPreparare;
Selectie* pSelectie;

};

//int AutomatCafea::S=0;
void genereazaRapoarte()
{
cout<<" Se genereaza totalul...";
int sw=1;
while(sw==1)
try{
    S+=intStack.top();
    intStack.pop();
}
catch (exception const& ex){sw=0;
      cerr <<  ex.what() <<endl;
      //return -1;
   }


cout<<"Suma totala vanzari: "<<S;
ofstream g("total.out");
g<<S;g.close();
getchar();getchar();
}
int main()
{
AutomatCafea automat;
automat.Functionare();

return 0;
}

