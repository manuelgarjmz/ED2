#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>                          
#include <string>
#include <stdlib.h>
#include <fstream>
#include<CommCtrl.h>              
#include "resource.h"
#include <iostream>

using namespace std;         


HINSTANCE GlobalhInstance;

HWND hAP, hAM, hNOM, hCURP, hRFC, hDATIP, hCALLE, hCOL, hCIU, hEST, hESC, hTEL, hS, hGO, hPR;
HWND hTIPO, hMAR, hPRE, hNDOS, hCVAC, hDESC;
HWND hUS, hCON;
HWND hRUS, hRCON, hRCON2, hRNOM, hRAP, hRAM;
HWND hBusqueda, hBusqueda2, hInfo, hNumero, hInfo2, hInfo3, hInfo4, hInfo5, hInfoV, hNUM;
wchar_t* auxiliarfoto = 0;
int carnet = 0;
wchar_t AP[100], AMA[100], NOM[100], CURP[100], RFC[100], DATIP[100], CALLE[100], COL[100], CIU[100], EST[100], ESC[100], TEL[100], S[100], GO[100], PR[100];
wchar_t TIPO[100], MAR[100], PRE[100], NDOS[100], CVAC[100], DESC[100];
wchar_t US[100], CON[100];
wchar_t RUS[100], RCON[100], RCON2[100], RNOM[100], RAP[100], RAM[100];
bool mostrarlista = false, fotov = false, fotov2 = false, fotov3 = false, validacion = true, listabv = false, validacionp = false, fotov4 = false, validacionmc = false;
wchar_t BUS[100], BCURP[100], BVAC[100], BCAR[100], BUSP[100];
string busqueda, brfc, bvac, busquedap, vacunaauxil;

INT_PTR CALLBACK fRV(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fRP(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fRC(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fEV(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fEP(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fEC(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fMV(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fMP(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fMC(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fInicioS(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK fREG(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
wchar_t* fExpBMP(HWND hwnd, wchar_t* ubicacion);
void fCBMP2(HWND hwnd, wchar_t* ubicacion);
void fEscribirC();
void fLeerC();
void fEscribirP();
void fLeerP();
void fLeerU();
void fEscribirU();
void fEscribirV();
void leerArchivo();
void fHacerA();
void fListaVacuna(HWND hwnd);
bool fComprobarS(string comprobar);
bool fComprobarD(string prueba);
void hMenu(HWND hwnd, WPARAM wparam);

string fCharToS(wchar_t* wch) {
    wstring ws = wstring(wch);
    string str(ws.begin(), ws.end());
    return str;
}

wchar_t* fStoW(string s) {
    wstring ws = wstring(s.begin(), s.end());
    wchar_t* wcdynamic = new wchar_t[s.length()];
    int i = 0;
    for (; i < s.length(); i++)
    {
        wcdynamic[i] = ws[i];
    }
    wcdynamic[i] = 0;

    return wcdynamic;
}

struct Vacuna {
    string tipo;
    string nombre;
    string dosis;
    string clabev;
    string descripcion;
    string precio;
    void setTipo(string tipo_) {
        tipo = tipo_;
    }
    void setNombre(string nombre_) {
        nombre = nombre_;
    }
    void setDosis(string dosis_) {
        dosis = dosis_;
    }
    void setClave(string clave_) {
        clabev = clave_;
    }
    void setDescripcion(string descripcion_) {
        descripcion = descripcion_;
    }
    void setPrecio(string precio_) {
        precio = precio_;
    }
    static Vacuna* nuevaVacuna(string tipo, string nombre_n, string ndosis_n, string clabev_n, string descripcion_n, string precio_n) {
        Vacuna* nueva = new Vacuna;
        nueva->tipo = tipo;
        nueva->nombre = nombre_n;
        nueva->dosis = ndosis_n;
        nueva->clabev = clabev_n;
        nueva->descripcion = descripcion_n;
        nueva->precio = precio_n;

        return nueva;
    };

};

struct Persona {
    string AP;
    string AM;
    string N;
    string CURP;
    string RFC;
    string nacimiento;
    string DCA;
    string DCO;
    string DCI;
    string DE;
    string DEC;
    string tel;
    string DocI;
    string se;
    string GPO;
    string PR;
    string DirFoto;
    void setAP(string AP_) {
        AP = AP_;
    }
    void setAM(string AM_) {
        AM = AM_;
    }
    void setN(string N_) {
        N = N_;
    }
    void setCURP(string CURP_) {
        CURP = CURP_;
    }
    void setRFC(string RFC_) {
        RFC = RFC_;
    }
    void setNacimiento(string nacimiento_) {
        nacimiento = nacimiento_;
    }
    void setDCA(string DCA_) {
        DCA = DCA_;
    }
    void setDCO(string DCO_) {
        DCO = DCO_;
    }
    void setDCI(string DCI_) {
        DCI = DCI_;
    }
    void setDE(string DE_) {
        DE = DE_;
    }
    void setDEC(string DEC_) {
        DEC = DEC_;
    }
    void setTel(string tel_) {
        tel = tel_;
    }
    void setDocI(string DocI_) {
        DocI_ = DocI_;
    }
    void setSe(string se_) {
        se = se_;
    }
    void setGPO(string GPO_) {
        GPO = GPO_;
    }
    void setPR(string PR_) {
        PR = PR_;
    }
    void setDirFoto(string DirFoto_) {
        DirFoto = DirFoto_;
    }
    static Persona* nuevaPersona(string _AP, string _AMA, string _NOM, string _CURP, string fecha, string _RFC, string _CALLE, string _COL, string _CIU, string _EST, string _ESC, string _TEL, string _S, string _GO, string _PR, string _DirFoto) {
        Persona* Nueva = new Persona;
        Nueva->nacimiento = fecha;
        Nueva->AP = _AP;
        Nueva->AM = _AMA;
        Nueva->N = _NOM;
        Nueva->CURP = _CURP;
        Nueva->RFC = _RFC;
        Nueva->DCA = _CALLE;
        Nueva->DCO = _COL;
        Nueva->DCI = _CIU;
        Nueva->DE = _EST;
        Nueva->DEC = _ESC;
        Nueva->tel = _TEL;
        Nueva->se = _S;
        Nueva->GPO = _GO;
        Nueva->PR = _PR;
        Nueva->DirFoto = _DirFoto;
        return Nueva;
    }
};

struct Usuario {
    string usuario;
    string contrasena;
    string nombre;
    string ap;
    string am;
    void setUsuario(string _usuario) {
        usuario = _usuario;
    }
    void setConstraseña(string _contrasena) {
        contrasena = _contrasena;
    }
    void setNombre(string _nombre) {
        nombre = _nombre;
    }
    void setAP(string _ap) {
        ap = _ap;
    }
    void setAM(string _am) {
        am = _am;
    }
    static Usuario* NuevoUsuario(string usuario, string contrasena, string nombre, string ap, string am) {
        Usuario* nuevo = new Usuario;
        nuevo->usuario = usuario;
        nuevo->contrasena = contrasena;
        nuevo->nombre = nombre;
        nuevo->ap = ap;
        nuevo->am = am;
        return nuevo;
    }
};

struct NODOSIMPLE {
    Vacuna* vacuna = NULL;
    NODOSIMPLE* siguiente = NULL;
    NODOSIMPLE* anterior = NULL;
    static NODOSIMPLE* nuevoNodo(Vacuna* dato) {
        NODOSIMPLE* nuevo = new NODOSIMPLE;
        if (nuevo == NULL) return NULL;
        nuevo->siguiente = NULL;
        nuevo->vacuna = dato;
        nuevo->anterior = NULL;
        return nuevo;
    }
};

struct NODOSIMPLEP {
    Persona* person = NULL;
    NODOSIMPLEP* siguiente = NULL;
    NODOSIMPLEP* anterior = NULL;
    static NODOSIMPLEP* nuevoNodo(Persona* dato) {
        NODOSIMPLEP* nuevo = new NODOSIMPLEP;
        if (nuevo == NULL) return NULL;
        nuevo->siguiente = NULL;
        nuevo->person = dato;
        nuevo->anterior = NULL;
        return nuevo;
    }

};

struct NODOSIMPLEU {
    Usuario* usuario = NULL;
    NODOSIMPLEU* siguiente = NULL;
    NODOSIMPLEU* anterior = NULL;
    static NODOSIMPLEU* nuevoNodo(Usuario* dato) {
        NODOSIMPLEU* nuevo = new NODOSIMPLEU;
        if (nuevo == NULL) return NULL;
        nuevo->siguiente = NULL;
        nuevo->usuario = dato;
        nuevo->anterior = NULL;
        return nuevo;
    }
};

struct LISTAPERSONA {
    NODOSIMPLEP* ORIGENP = NULL;
    NODOSIMPLEP* FINP = NULL;
    void agregarNodoFinal(Persona* nuevos) {
        if (ORIGENP == NULL) {
            ORIGENP = NODOSIMPLEP::nuevoNodo(nuevos);
            FINP = ORIGENP;
        }
        else {
            FINP->siguiente = NODOSIMPLEP::nuevoNodo(nuevos);
            FINP->siguiente->anterior = FINP;
            FINP = FINP->siguiente;
        }
    }
    NODOSIMPLEP* buscarNodoPersona(string nombre) {
        NODOSIMPLEP* indice = ORIGENP;
        while (indice != NULL) {
            if (nombre == indice->person->N)
                return indice;
            indice = indice->siguiente;
        }
        return indice;
    }
    Persona* eliminarPersona(string nombreBuscar) {
        NODOSIMPLEP* persona = buscarNodoPersona(nombreBuscar);
        Persona* p = NULL;
        if (persona != NULL) {
            if (persona->anterior == NULL) {
                ORIGENP = persona->siguiente;
                if (persona == FINP) FINP = NULL;
                else ORIGENP->anterior = NULL;
                p = persona->person;
                delete persona;
            }
            else if (persona->siguiente == NULL) {
                FINP = persona->anterior;
                if (FINP != NULL)
                    FINP->siguiente = NULL;
                p = persona->person;
                delete persona;
            }
            else {
                NODOSIMPLEP* anterior = persona->anterior,
                    * siguiente = persona->siguiente;
                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;
                p = persona->person;
                delete persona;
            }
            return p;
        }
        return p;
    }
    bool modificarPersona(Persona* persona, wchar_t AP[100], wchar_t AMA[100], wchar_t NOM[100], wchar_t CURP[100], wchar_t RFC[100], string sfecha, wchar_t CALLE[100], wchar_t COL[100], wchar_t CIU[100], wchar_t EST[100], wchar_t ESC[100], wchar_t TEL[100], wchar_t S[100], wchar_t GO[100], wchar_t PR[100], wchar_t DirFoto[100]) {
        if (persona != NULL) {
            persona->AP = fCharToS(AP);
            persona->AM = fCharToS(AMA);
            persona->N = fCharToS(NOM);
            persona->CURP = fCharToS(CURP);
            persona->RFC = fCharToS(RFC);
            persona->DCA = fCharToS(CALLE);
            persona->DCO = fCharToS(COL);
            persona->DCI = fCharToS(CIU);
            persona->DE = fCharToS(EST);
            persona->DEC = fCharToS(ESC);
            persona->tel = fCharToS(TEL);
            persona->se = fCharToS(S);
            persona->GPO = fCharToS(GO);
            persona->PR = fCharToS(PR);
            persona->DirFoto = fCharToS(DirFoto);
            return true;
        }
        return false;
    }
}LISTA_P;

struct LISTAVACUNA {
    NODOSIMPLE* ORIGEN = NULL;
    NODOSIMPLE* FIN = NULL;
    void agregarNodoFinal(Vacuna* nuevo) {
        if (ORIGEN == NULL) {
            ORIGEN = NODOSIMPLE::nuevoNodo(nuevo);
            FIN = ORIGEN;
        }
        else {
            FIN->siguiente = NODOSIMPLE::nuevoNodo(nuevo);
            FIN->siguiente->anterior = FIN;
            FIN = FIN->siguiente;
        }
    }
    NODOSIMPLE* buscarNodoVacuna(string clave) {
        NODOSIMPLE* indice = ORIGEN;
        while (indice != NULL) {
            if (clave == indice->vacuna->clabev)
                return indice;
            indice = indice->siguiente;
        }
        return indice;
    }
    Vacuna* eliminarVacuna(string clave) {
        NODOSIMPLE* vacuna = buscarNodoVacuna(clave);
        Vacuna* p = NULL;
        if (vacuna != NULL) {
            if (vacuna->anterior == NULL) {
                ORIGEN = vacuna->siguiente;
                if (vacuna == FIN) FIN = NULL;
                else ORIGEN->anterior = NULL;
                p = vacuna->vacuna;
                delete vacuna;
            }
            else if (vacuna->siguiente == NULL) {
                FIN = vacuna->anterior;
                if (FIN != NULL)
                    FIN->siguiente = NULL;
                p = vacuna->vacuna;
                delete vacuna;
            }
            else {
                NODOSIMPLE* anterior = vacuna->anterior,
                    * siguiente = vacuna->siguiente;
                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;
                p = vacuna->vacuna;
                delete vacuna;
            }
            return p;
        }
        return p;
    }
    bool modificarVacuna(Vacuna* modificar, wchar_t TIPO[100], wchar_t MAR[100], wchar_t PRE[100], wchar_t NDOS[100], wchar_t CVAC[100], wchar_t DESC[100]) {
        if (modificar != NULL) {
            modificar->tipo = fCharToS(TIPO);
            modificar->nombre = fCharToS(MAR);
            modificar->precio = fCharToS(PRE);
            modificar->dosis = fCharToS(NDOS);
            modificar->clabev = fCharToS(CVAC);
            modificar->descripcion = fCharToS(DESC);
            return true;
        }
        return false;
    }
}LISTA_S;

struct LISTAUS {
    NODOSIMPLEU* ORIGEN = NULL;
    NODOSIMPLEU* FIN = NULL;
    void agregarNodoFinal(Usuario* nuevo) {
        if (ORIGEN == NULL) {
            ORIGEN = NODOSIMPLEU::nuevoNodo(nuevo);
            FIN = ORIGEN;
        }
        else {
            FIN->siguiente = NODOSIMPLEU::nuevoNodo(nuevo);
            FIN->siguiente->anterior = FIN;
            FIN = FIN->siguiente;
        }
    }

}LISTA_U;

struct Carnet {
    string RFC;
    string clabev;
    int numeroc;
    Persona* nodopersona;
    Vacuna* nodovacuna;
    void setRFC(string RFC_) {
        RFC = RFC_;
    }
    void setClave(string clave_) {
        clabev = clave_;
    }
    void setNumeroc(string numeroc_) {

        numeroc = stoi(numeroc_);
    }
    static Carnet* nuevoCarnet(string RFC_, string clave_, string numeroc_) {
        Carnet* nuevo = new Carnet;
        nuevo->RFC = RFC_;
        nuevo->clabev = clave_;
        nuevo->numeroc = stoi(numeroc_);
        bool salir = false;
        NODOSIMPLEP* auxiliarp;
        auxiliarp = LISTA_P.ORIGENP;
        if (auxiliarp != NULL) {
            while (salir != true) {
                if (auxiliarp->person->RFC == RFC_) {
                    nuevo->nodopersona = auxiliarp->person;
                    salir = true;
                }
                auxiliarp = auxiliarp->siguiente;
            }
        }
        salir = false;
        NODOSIMPLE* auxiliarv;
        auxiliarv = LISTA_S.ORIGEN;
        if (auxiliarv != NULL) {
            while (salir != true) {
                if (auxiliarv->vacuna->clabev == clave_) {
                    nuevo->nodovacuna = auxiliarv->vacuna;
                    salir = true;
                }
                auxiliarv = auxiliarv->siguiente;
            }
        }
        salir = false;
        return nuevo;
    }
    static Carnet* nuevoCarnet(string RFC_, string clave_, int numeroc_) {
        Carnet* nuevo = new Carnet;
        nuevo->RFC = RFC_;
        nuevo->clabev = clave_;
        nuevo->numeroc = numeroc_;
        bool salir = false;
        NODOSIMPLEP* auxiliarp;
        auxiliarp = LISTA_P.ORIGENP;
        if (auxiliarp != NULL) {
            while (salir != true) {
                if (auxiliarp->person->RFC == RFC_) {
                    nuevo->nodopersona = auxiliarp->person;
                    salir = true;
                }
                auxiliarp = auxiliarp->siguiente;
            }
        }
        salir = false;
        NODOSIMPLE* auxiliarv;
        auxiliarv = LISTA_S.ORIGEN;
        if (auxiliarv != NULL) {
            while (salir != true) {
                if (auxiliarv->vacuna->clabev == clave_) {
                    nuevo->nodovacuna = auxiliarv->vacuna;
                    salir = true;
                }
                auxiliarv = auxiliarv->siguiente;
            }
        }
        salir = false;
        return nuevo;
    }
};

struct NODOSIMPLEC {
    Carnet* carnet = NULL;
    NODOSIMPLEC* siguiente = NULL;
    NODOSIMPLEC* anterior = NULL;
    static NODOSIMPLEC* nuevoNodo(Carnet* dato) {
        NODOSIMPLEC* nuevo = new NODOSIMPLEC;
        if (nuevo == NULL) return NULL;
        nuevo->siguiente = NULL;
        nuevo->carnet = dato;
        nuevo->anterior = NULL;
        return nuevo;
    }
};

struct LISTACARNET {
    NODOSIMPLEC* ORIGEN = NULL;
    NODOSIMPLEC* FIN = NULL;
    void agregarNodoFinal(Carnet* nuevo) {
        if (ORIGEN == NULL) {
            ORIGEN = NODOSIMPLEC::nuevoNodo(nuevo);
            FIN = ORIGEN;
        }
        else {
            FIN->siguiente = NODOSIMPLEC::nuevoNodo(nuevo);
            FIN->siguiente->anterior = FIN;
            FIN = FIN->siguiente;
        }
    }
    NODOSIMPLEC* buscarNodoCarnet(string numero) {
        NODOSIMPLEC* indice = ORIGEN;
        while (indice != NULL) {
            if (numero == to_string(indice->carnet->numeroc))
                return indice;
            indice = indice->siguiente;
        }
        return indice;
    }
    Carnet* eliminarCarnet(string numeroc) {
        NODOSIMPLEC* carnet = buscarNodoCarnet(numeroc);
        Carnet* p = NULL;
        if (carnet != NULL) {
            if (carnet->anterior == NULL) {
                ORIGEN = carnet->siguiente;
                if (carnet == FIN) FIN = NULL;
                else ORIGEN->anterior = NULL;
                p = carnet->carnet;
                delete carnet;
            }
            else if (carnet->siguiente == NULL) {
                FIN = carnet->anterior;
                if (FIN != NULL)
                    FIN->siguiente = NULL;
                p = carnet->carnet;
                delete carnet;
            }
            else {
                NODOSIMPLEC* anterior = carnet->anterior,
                    * siguiente = carnet->siguiente;
                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;
                p = carnet->carnet;
                delete carnet;
            }
            return p;
        }
        return p;
    }
    bool modificarCarnet(Carnet* modificar, string RFC, string CLAVEV, int carnet, Persona* persona, Vacuna* vacuna) {
        if (modificar != NULL) {
            modificar->RFC = RFC;
            modificar->clabev = CLAVEV;
            modificar->numeroc = carnet;
            modificar->nodopersona = persona;
            modificar->nodovacuna = vacuna;
            return true;
        }
        return false;
    }

}LISTA_C;

struct NODOARBOLCARNET {
    NODOARBOLCARNET* PADRE = NULL;
    NODOARBOLCARNET* IZQUIERDO = NULL;
    NODOARBOLCARNET* DERECHO = NULL;
    Carnet* carnet = NULL;
    int balance = 0;
    static NODOARBOLCARNET* nuevoNodo(struct Carnet* info) {
        NODOARBOLCARNET* nuevo = new NODOARBOLCARNET;
        if (nuevo == NULL)
            exit(-1);
        nuevo->carnet = info;
        nuevo->PADRE = NULL;
        nuevo->IZQUIERDO = NULL;
        nuevo->DERECHO = NULL;
        return nuevo;
    }
};

struct ARBOLCARNET {
    NODOARBOLCARNET* RAIZ = NULL;
    bool balanceo = false;
    NODOARBOLCARNET* rotacionIzquierda(NODOARBOLCARNET* t) {
        NODOARBOLCARNET* temp, * padre = t->PADRE;
        int x, y;
        temp = t;
        t = t->DERECHO;
        temp->DERECHO = t->IZQUIERDO;
        t->IZQUIERDO = temp;
        //Recalcula factores de balance de los dos nodos
        x = temp->balance; 
        y = t->balance;
        temp->balance = x - 1 - max(y, 0);
        t->balance = min(x - 2 + min(y, 0), y - 1);

        return t;
    }
    NODOARBOLCARNET* rotacionDerecha(NODOARBOLCARNET* t) {
        NODOARBOLCARNET* temp = t, * padre = t->PADRE;
        int x, y;
        t = t->IZQUIERDO;
        temp->IZQUIERDO = t->DERECHO;
        t->DERECHO = temp;
        x = temp->balance;
        y = t->balance;
        temp->balance = x + 1 - min(y, 0);
        t->balance = max(x + 2 + max(y, 0), y + 1);
        return t;
    }
    int calcularEquilibrios(NODOARBOLCARNET* t) {
        if (t == NULL)
            return 0;
        int eIzquierdo = calcularEquilibrios(t->IZQUIERDO) + 1;
        int eDerecho = calcularEquilibrios(t->DERECHO) + 1;
        t->balance = eDerecho - eIzquierdo;
        return eIzquierdo > eDerecho ? eIzquierdo : eDerecho;
    }
    NODOARBOLCARNET* buscarNodo(NODOARBOLCARNET* nodo, Carnet* persona) {
        if (nodo == NULL)
            return NULL;
        if (nodo->carnet->numeroc > persona->numeroc)
            return buscarNodo(nodo->IZQUIERDO, persona);
        else if (nodo->carnet->numeroc < persona->numeroc)
            return buscarNodo(nodo->DERECHO, persona);
        return nodo;
    }
    NODOARBOLCARNET* buscarPersona(Carnet* persona) {
        return buscarNodo(RAIZ, persona);
    }
    NODOARBOLCARNET* buscarPersona(int idCarnet) {
        Carnet personaVacia;
        personaVacia.numeroc = idCarnet;
        return buscarNodo(RAIZ, &personaVacia);
    }
    void eliminarNodo(NODOARBOLCARNET** nodo, NODOARBOLCARNET* padre, NODOARBOLCARNET* eliminar) {
        NODOARBOLCARNET* elemento = *nodo;
        if (elemento == NULL) {
            this->balanceo = false;
        }
        else if (elemento->carnet->numeroc < eliminar->carnet->numeroc) {
            eliminarNodo(&(elemento->DERECHO), elemento, eliminar);
            elemento->balance -= 1;
        }
        else if (elemento->carnet->numeroc > eliminar->carnet->numeroc) {
            eliminarNodo(&(elemento->IZQUIERDO), elemento, eliminar);
            elemento->balance += 1;
        }
        else {
            if (elemento->IZQUIERDO == NULL) {
                NODOARBOLCARNET* tmp = elemento;
                (*nodo) = tmp->DERECHO;
                delete tmp;
                this->balanceo = true;
                return;
            }
            else if (elemento->DERECHO == NULL) {
                NODOARBOLCARNET* tmp = elemento;
                (*nodo) = tmp->IZQUIERDO;
                delete tmp;
                this->balanceo = true;
                return;
            }
            else   /* Tiene dos hijos */ {
                if (elemento->balance < 0) {
                    /* Si cargado a la izquierda, elimina mayor descendiente hijo izq */
                    NODOARBOLCARNET* tmp = elemento;
                    tmp = (*nodo)->IZQUIERDO;
                    while (tmp->DERECHO != NULL) tmp = tmp->DERECHO;
                    (*nodo)->carnet = tmp->carnet;
                    eliminarNodo(&((*nodo)->DERECHO), (*nodo), tmp);
                    elemento = (*nodo);
                    elemento->balance += 1;
                }
                else {
                    NODOARBOLCARNET* tmp = elemento;
                    tmp = (*nodo)->IZQUIERDO;
                    while (tmp->IZQUIERDO != NULL) tmp = tmp->IZQUIERDO;
                    (*nodo)->carnet = tmp->carnet;
                    eliminarNodo(&((*nodo)->IZQUIERDO), (*nodo), tmp);
                    elemento = (*nodo);
                    elemento->balance -= 1;
                }
            }
        }
        if (this->balanceo == true) {
            if (elemento->balance < -1)   {
                if (elemento->IZQUIERDO->balance > 0)  {
                    elemento->IZQUIERDO = rotacionIzquierda(elemento->IZQUIERDO);
                    this->balanceo = true; 
                }
                else if (elemento->IZQUIERDO->balance == 0)
                    this->balanceo = false; 
                else
                    this->balanceo = true;
                (*nodo) = rotacionDerecha(*nodo);
            }
            else if (elemento->balance > 1)   {
                if (elemento->DERECHO->balance < 0) {
                    
                    (*nodo)->DERECHO = rotacionDerecha((*nodo)->DERECHO);
                    this->balanceo = true; 
                }
                else if (elemento->DERECHO->balance == 0)
                    this->balanceo = false; 
                else 
                    this->balanceo = true;
                (*nodo) = rotacionIzquierda(*nodo);
            }
            else if (elemento->balance == 0) 
                this->balanceo = true; 
            else 
                this->balanceo = false; 
        }
    }
    void borrarNodo(Carnet* eliminar) {
        NODOARBOLCARNET* nodo = buscarPersona(eliminar);
        if (nodo != NULL) {
            calcularEquilibrios(RAIZ);
            eliminarNodo(&RAIZ, NULL, nodo);
        }
    }        
    void insertarNodo(NODOARBOLCARNET** nodo, NODOARBOLCARNET* padre, NODOARBOLCARNET* nuevo) {
        NODOARBOLCARNET* elemento = *nodo;
        if (elemento == NULL) {
            *nodo = nuevo;
            elemento = nuevo;
            nuevo->PADRE = padre;
            nuevo->balance = 0;
            balanceo = true;
            return;
        }
        else {
            if (elemento->carnet->numeroc > nuevo->carnet->numeroc) {
                insertarNodo(&(elemento->IZQUIERDO), elemento, nuevo);
                elemento->balance -= 1;
            }
            else {
                insertarNodo(&(elemento->DERECHO), elemento, nuevo);
                elemento->balance += 1;
            }
        }
        if (this->balanceo == true) {
            if (elemento->balance < -1) {
                if (elemento->IZQUIERDO->balance > 0) {
                    elemento->IZQUIERDO = rotacionIzquierda(elemento->IZQUIERDO);
                    elemento->IZQUIERDO->PADRE = elemento;
                    if (elemento->IZQUIERDO->DERECHO != NULL)
                        elemento->IZQUIERDO->DERECHO->PADRE = elemento->IZQUIERDO;
                    if (elemento->IZQUIERDO->IZQUIERDO != NULL)
                        elemento->IZQUIERDO->IZQUIERDO->PADRE = elemento->IZQUIERDO;
                }
                *nodo = rotacionDerecha(elemento);
                this->balanceo = false;
                (*nodo)->PADRE = padre;
                if ((*nodo)->IZQUIERDO != NULL)
                    (*nodo)->IZQUIERDO->PADRE = (*nodo);
                if ((*nodo)->DERECHO != NULL)
                    (*nodo)->DERECHO->PADRE = (*nodo);
            }
            else if (elemento->balance > 1) {
                if (elemento->DERECHO->balance < 0) {
                    elemento->DERECHO = rotacionDerecha(elemento->DERECHO);
                    elemento->DERECHO->PADRE = elemento;
                    if (elemento->DERECHO->IZQUIERDO != NULL)
                        elemento->DERECHO->IZQUIERDO->PADRE = elemento->DERECHO;
                    if (elemento->DERECHO->DERECHO != NULL)
                        elemento->DERECHO->DERECHO->PADRE = elemento->DERECHO;
                }
                *nodo = rotacionIzquierda(elemento); 
                this->balanceo = false;
                (*nodo)->PADRE = padre;
                if ((*nodo)->IZQUIERDO != NULL)
                    (*nodo)->IZQUIERDO->PADRE = (*nodo);
                if ((*nodo)->DERECHO != NULL)
                    (*nodo)->DERECHO->PADRE = (*nodo);
            }
            else if (elemento->balance == 0)
                this->balanceo = false;
            else
                this->balanceo = true; 
        }
    }
    void agregarNodo(Carnet* info) {
        NODOARBOLCARNET* nuevo = NODOARBOLCARNET::nuevoNodo(info);
        insertarNodo(&RAIZ, NULL, nuevo);
        calcularEquilibrios(RAIZ);
    }
    void lista2Arbol(NODOSIMPLEC* listaDoble) {
        eliminarArbol();
        NODOSIMPLEC* carnet = listaDoble;
        while (carnet != NULL) {
            agregarNodo(carnet->carnet);
            carnet = carnet->siguiente;
        }
    }
    void eliminarArbolNodos(NODOARBOLCARNET* nodo) {
        if (nodo == NULL) {
            return;
        }
        else {
            eliminarArbolNodos(nodo->IZQUIERDO);
            eliminarArbolNodos(nodo->DERECHO);
            delete(nodo);
        }
    }
    void eliminarArbol() {
        eliminarArbolNodos(RAIZ);
        RAIZ = NULL;
    }
} arbolCarnets;

Persona* auxiliarc = NULL;
Persona* auxiliarc3 = NULL;
Carnet* auxiliarc2 = NULL;
Carnet* auxiliarc4 = NULL;
Vacuna* auxiliarv = NULL;
Vacuna* auxiliarv2 = NULL;
NODOARBOLCARNET* AUX;
void RegistroP(wchar_t AP[100], wchar_t AMA[100], wchar_t NOM[100], wchar_t CURP[100], wchar_t RFC[100], string sfecha, wchar_t CALLE[100], wchar_t COL[100], wchar_t CIU[100], wchar_t EST[100], wchar_t ESC[100], wchar_t TEL[100], wchar_t S[100], wchar_t GO[100], wchar_t PR[100], wchar_t DirFoto[100]) {
    string _AP, _AMA, _NOM, _CURP, _RFC, _CALLE, _COL, _CIU, _EST, _ESC, _TEL, _S, _GO, _PR, _DirFoto;
    _AP = fCharToS(AP);
    _AMA = fCharToS(AMA);
    _NOM = fCharToS(NOM);
    _CURP = fCharToS(CURP);
    _RFC = fCharToS(RFC);
    _CALLE = fCharToS(CALLE);
    _COL = fCharToS(COL);
    _CIU = fCharToS(CIU);
    _EST = fCharToS(EST);
    _ESC = fCharToS(ESC);
    _TEL = fCharToS(TEL);
    _S = fCharToS(S);
    _GO = fCharToS(GO);
    _PR = fCharToS(PR);
    _DirFoto = fCharToS(DirFoto);
    LISTA_P.agregarNodoFinal(Persona::nuevaPersona(_AP, _AMA, _NOM, _CURP, sfecha, _RFC, _CALLE, _COL, _CIU, _EST, _ESC, _TEL, _S, _GO, _PR, _DirFoto));
}
void RegistroV(wchar_t TIPO[100], wchar_t MAR[100], wchar_t PRE[100], wchar_t NDOS[100], wchar_t CVAC[100], wchar_t DESC[100]) {
    string _TIPO, _MAR, _PRE, _NDOS, _CVAC, _DESC;
    _TIPO = fCharToS(TIPO);
    _MAR = fCharToS(MAR);
    _PRE = fCharToS(PRE);
    _NDOS = fCharToS(NDOS);
    _CVAC = fCharToS(CVAC);
    _DESC = fCharToS(DESC);
    LISTA_S.agregarNodoFinal(Vacuna::nuevaVacuna(_TIPO, _MAR, _NDOS, _CVAC, _DESC, _PRE));
}
void RegistroC(string rfc, string cvac, int numero) {
    LISTA_C.agregarNodoFinal(Carnet::nuevoCarnet(rfc, cvac, numero));
}
void CASDialog(HWND hwnd, int iDDialog, DLGPROC callback) {
    HWND hVentana = CreateDialogW(GlobalhInstance, MAKEINTRESOURCE(iDDialog), NULL, callback);
    ShowWindow(hVentana, SW_SHOW);
    DestroyWindow(hwnd);
}

void hMenu(HWND hwnd, WPARAM wparam) {
    switch (LOWORD(wparam)) {
    case ID_REGISTRAR_PERSONA:
        CASDialog(hwnd, IDD_RP, fRP);
        break;
    case ID_REGISTRAR_VACUNA:
        CASDialog(hwnd, IDD_RV, fRV);
        break;
    case ID_SALIR_CERRARSESION:
        CASDialog(hwnd, IDD_IS, fInicioS);
        break;
    case ID_SALIR_SALIR:
        PostQuitMessage(0);
        DestroyWindow(hwnd);
        break;
    case ID_REGISTRAR_CARNET:
        CASDialog(hwnd, IDD_RC, fRC);
        break;
    case ID_MODIFICAR_VACUNA:
        CASDialog(hwnd, IDD_MV, fMV);
        break;
    case ID_MODIFICAR_PERSONA:
        CASDialog(hwnd, IDD_MP, fMP);
        break;
    case ID_MODIFICAR_CARNET:
        CASDialog(hwnd, IDD_MC, fMC);
        break;
    case ID_BAJA_VACUNA:
        CASDialog(hwnd, IDD_EV, fEV);
        break;
    case ID_BAJA_PERSONA:
        CASDialog(hwnd, IDD_EP, fEP);
        break;
    case ID_BAJA_CARNET:
        CASDialog(hwnd, IDD_EC, fEC);
        break;
    }

}

void fEliminarNA(Carnet* eliminar) {
    NODOSIMPLEC* ARBOL;
    ARBOL = LISTA_C.ORIGEN;
    while (ARBOL != NULL) {
        if ((ARBOL->carnet->numeroc) == (eliminar->numeroc)) {
            arbolCarnets.borrarNodo(eliminar);
        }
        ARBOL = ARBOL->siguiente;
    }
}

void fEliminarNAV(Carnet* eliminar) {
    NODOSIMPLEC* ARBOL;
    ARBOL = LISTA_C.ORIGEN;
    while (ARBOL != NULL) {
        if ((ARBOL->carnet->clabev) == (eliminar->clabev)) {
            arbolCarnets.borrarNodo(eliminar);
        }
        ARBOL = ARBOL->siguiente;
    }
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {

    fLeerP();
    leerArchivo();
    fLeerU();
    fLeerC();
    fHacerA();

    GlobalhInstance = hInstance;

    HWND hVentanaInicio = CreateDialogW(hInstance, MAKEINTRESOURCE(IDD_IS), NULL, fInicioS);

    ShowWindow(hVentanaInicio, SW_SHOW);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

INT_PTR CALLBACK fInicioS(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        hUS = GetDlgItem(hwnd, IDC_US);
        hCON = GetDlgItem(hwnd, IDC_CON);
    }
                      break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDOK: {
            GetWindowText(hUS, US, 100);
            GetWindowText(hCON, CON, 100);
            string us, con;
            us = fCharToS(US);
            con = fCharToS(CON);
            NODOSIMPLEU* auxiliar;
            auxiliar = LISTA_U.ORIGEN;
            bool salir = false;
            if (auxiliar != NULL) {
                while (salir != true) {

                    if ((auxiliar->usuario->usuario == us) && (auxiliar->usuario->contrasena == con)) {
                        MessageBox(hwnd, L"INICIO DE SESION CORRECTO", L"CORRECTO", MB_ICONINFORMATION);
                        CASDialog(hwnd, IDD_RP, fRP);
                    }
                    else if ((auxiliar->usuario->usuario == us) && (auxiliar->usuario->contrasena != con)) {
                        MessageBox(hwnd, L"CONTRASEÑA INCORRECTA", L"ERROR", MB_ICONEXCLAMATION);
                    }
                    else if (auxiliar->usuario->usuario != us && auxiliar->siguiente == NULL) {
                        MessageBox(hwnd, L"USUARIO NO ENCONTRADO", L"USUARIO NO ENCONTRADO", MB_ICONEXCLAMATION);
                    }
                    if (auxiliar->siguiente == NULL) {
                        salir = true;
                    }
                    else {
                        auxiliar = auxiliar->siguiente;
                    }
                }
            }
            else {
                MessageBox(hwnd, L"NO EXISTEN USUARIOS REGISTRADOS", L"ERROR", MB_ICONEXCLAMATION);
            }
            LISTA_U.ORIGEN;
        }
                 break;
        case IDC_REG: {
            CASDialog(hwnd, IDD_REG, fREG);
        }
                    break;
        case IDCANCEL: {
            PostQuitMessage(0);
            DestroyWindow(hwnd);
        }
        }
    }
    return false;
}

INT_PTR CALLBACK fRP(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);
        hAP = GetDlgItem(hwnd, IDC_AP);
        hAM = GetDlgItem(hwnd, IDC_AM);
        hNOM = GetDlgItem(hwnd, IDC_NOM);
        hCURP = GetDlgItem(hwnd, IDC_CURP);
        hRFC = GetDlgItem(hwnd, IDC_RFC);
        hDATIP = GetDlgItem(hwnd, IDC_DATETIMEPICKER1);
        hCALLE = GetDlgItem(hwnd, IDC_CALLE);
        hCOL = GetDlgItem(hwnd, IDC_COL);
        hCIU = GetDlgItem(hwnd, IDC_CIU);
        hEST = GetDlgItem(hwnd, IDC_EST);
        hESC = GetDlgItem(hwnd, IDC_ESC);
        hTEL = GetDlgItem(hwnd, IDC_TEL);
        hS = GetDlgItem(hwnd, IDC_S);
        hGO = GetDlgItem(hwnd, IDC_GO);
        hPR = GetDlgItem(hwnd, IDC_PR);
        string es1 = "Soltero(a)";
        string es2 = "Casado(a)";
        string es4 = "Separado(a)";
        string es5 = "Viudo(a)";
        string es6 = "Otros";
        string s1 = "Masculino";
        string s2 = "Femenino";
        string s3 = "Otro";
        wchar_t* solt1 = fStoW(es1);
        wchar_t* solt2 = fStoW(es2);
        wchar_t* solt4 = fStoW(es4);
        wchar_t* solt5 = fStoW(es5);
        wchar_t* solt6 = fStoW(es6);
        wchar_t* sw1 = fStoW(s1);
        wchar_t* sw2 = fStoW(s2);
        wchar_t* sw3 = fStoW(s3);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt1);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt2);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt4);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt5);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt6);
        SendMessage(hS, CB_ADDSTRING, 0, (LPARAM)sw1);
        SendMessage(hS, CB_ADDSTRING, 0, (LPARAM)sw2);
        SendMessage(hS, CB_ADDSTRING, 0, (LPARAM)sw3);
        if (fotov == true) {
            fCBMP2(hwnd, auxiliarfoto);
        }
    }
                      break;
    case WM_COMMAND: {
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {
        case IDOK: {
            SYSTEMTIME fecha;
            string sfecha;
            GetWindowText(hAP, AP, 100);
            GetWindowText(hAM, AMA, 100);
            GetWindowText(hNOM, NOM, 100);
            GetWindowText(hCURP, CURP, 100);
            GetWindowText(hRFC, RFC, 100);
            DateTime_GetSystemtime(hDATIP, &fecha);                          
            GetWindowText(hCALLE, CALLE, 100);
            GetWindowText(hCOL, COL, 100);
            GetWindowText(hCIU, CIU, 100);
            GetWindowText(hEST, EST, 100);
            GetWindowText(hESC, ESC, 100);             
            GetWindowText(hTEL, TEL, 100);
            GetWindowText(hS, S, 100);                 
            GetWindowText(hGO, GO, 100);
            GetWindowText(hPR, PR, 100);
            sfecha = to_string(fecha.wDay);
            sfecha.append("/");
            sfecha.append(to_string(fecha.wMonth));
            sfecha.append("/");
            sfecha.append(to_string(fecha.wYear));
            if ((AP[0] != 0) && (AMA[0] != 0) && (NOM[0] != 0) && (CURP[0] != 0) && (RFC[0] != 0) && (CALLE[0] != 0) && (COL[0] != 0) && (CIU[0] != 0) && (EST[0] != 0) && (ESC[0] != 0) && (TEL[0] != 0) && (S[0] != 0) && (GO[0] != 0) && (PR[0] != 0) && fotov == true) {
                string CURPC;
                CURPC = fCharToS(CURP);
                if (fComprobarS(CURPC) == true) {
                    string RFCC;
                    RFCC = fCharToS(RFC);
                    if (fComprobarS(RFCC) == true) {
                        if (LISTA_P.ORIGENP != NULL) {
                            NODOSIMPLEP* auxiliar;
                            auxiliar = LISTA_P.ORIGENP;
                            bool salir = false;
                            while (salir != true) {
                                if (auxiliar->person->CURP == CURPC) {
                                    MessageBox(hwnd, L"El CURP ya esta registrado en el sistema", L"Error en registro", MB_ICONINFORMATION);
                                    salir = true;
                                }
                                else if (auxiliar->person->RFC == RFCC) {
                                    MessageBox(hwnd, L"El RFC ya esta registrado en el sistema", L"Error en registro", MB_ICONINFORMATION);
                                    salir = true;
                                }
                                else if (auxiliar->siguiente == NULL) {
                                    salir = true;
                                }
                                else {
                                    auxiliar = auxiliar->siguiente;
                                }
                            }
                            if (auxiliar->siguiente == NULL && auxiliar->person->CURP != CURPC && auxiliar->person->RFC != RFCC) {
                                RegistroP(AP, AMA, NOM, CURP, RFC, sfecha, CALLE, COL, CIU, EST, ESC, TEL, S, GO, PR, auxiliarfoto);
                                fEscribirP();
                                MessageBox(hwnd, L"Persona registrada correctamente", L"Registro de persona exitoso", MB_ICONINFORMATION);
                                fotov = false;
                                CASDialog(hwnd, IDD_RP, fRP);
                            }
                        }
                        else {
                            RegistroP(AP, AMA, NOM, CURP, RFC, sfecha, CALLE, COL, CIU, EST, ESC, TEL, S, GO, PR, auxiliarfoto);
                            fEscribirP();
                            MessageBox(hwnd, L"Persona registrada correctamente", L"Registro de persona exitoso", MB_ICONINFORMATION);
                            fotov = false;
                            CASDialog(hwnd, IDD_RP, fRP);
                        }
                    }
                    else {
                        MessageBox(hwnd, L"No se aceptan espacios en el RFC", L"RFC CON ESPACIOS", MB_ICONINFORMATION);
                    }
                }
                else {
                    MessageBox(hwnd, L"No se aceptan espacios en el CURP", L"CURP CON ESPACIOS", MB_ICONINFORMATION);
                }
            }
            else {
                MessageBox(hwnd, L"Por favor llene todos los datos", L"FALTA INFORMACION", MB_ICONINFORMATION);
            }
        }
                 break;
        case IDCANCEL:

            break;
        case IDC_SF: {
            auxiliarfoto = fExpBMP(hwnd, auxiliarfoto);
            if (auxiliarfoto[0] != 0) {
                MessageBox(hwnd, L"Foto cargada con exito", L"Hecho", MB_ICONASTERISK);
                fotov = true;
            }
        }

                   break;
        }
    }
                   break;
    }

    return false;
}

INT_PTR CALLBACK fRV(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);
        hTIPO = GetDlgItem(hwnd, IDC_TIPO);
        hMAR = GetDlgItem(hwnd, IDC_MAR);
        hPRE = GetDlgItem(hwnd, IDC_PRE);
        hNDOS = GetDlgItem(hwnd, IDC_NDOS);
        hCVAC = GetDlgItem(hwnd, IDC_CVAC);
        hDESC = GetDlgItem(hwnd, IDC_DESC);
    }
                      break;
    case WM_COMMAND: {
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {
        case IDC_ACEPTAR:

            GetWindowText(hTIPO, TIPO, 100);
            GetWindowText(hMAR, MAR, 100);
            GetWindowText(hPRE, PRE, 100);
            GetWindowText(hNDOS, NDOS, 100);
            GetWindowText(hCVAC, CVAC, 100);
            GetWindowText(hDESC, DESC, 100);
            if ((TIPO[0] != 0) && (MAR[0] != 0) && (PRE[0] != 0) && (NDOS[0] != 0) && (CVAC[0] != 0) && (DESC[0] != 0)) {
                string comprobar = fCharToS(PRE);
                string comprobarcv = fCharToS(CVAC);
                if (fComprobarD(comprobar) == true) {
                    if (LISTA_S.ORIGEN != NULL) {
                        NODOSIMPLE* auxiliar;
                        auxiliar = LISTA_S.ORIGEN;
                        bool salir = false;
                        while (salir != true) {
                            if (auxiliar->vacuna->clabev == comprobarcv) {
                                MessageBox(hwnd, L"La clave de vacuna ya esta registrada en el sistema", L"Clave no valida", MB_ICONINFORMATION);
                                salir = true;
                            }
                            else if (auxiliar->siguiente == NULL) {
                                salir = true;
                            }
                            else {
                                auxiliar = auxiliar->siguiente;
                            }

                        }
                        if (auxiliar->siguiente == NULL && auxiliar->vacuna->clabev != comprobarcv) {
                            RegistroV(TIPO, MAR, PRE, NDOS, CVAC, DESC);
                            fEscribirV();
                            MessageBox(hwnd, L"VACUNA REGISTRADA CON EXITO", L"REGISTRO CORRECTO", MB_ICONEXCLAMATION);
                            CASDialog(hwnd, IDD_RV, fRV);
                        }
                    }
                    else {
                        RegistroV(TIPO, MAR, PRE, NDOS, CVAC, DESC);
                        fEscribirV();
                        MessageBox(hwnd, L"VACUNA REGISTRADA CON EXITO", L"REGISTRO CORRECTO", MB_ICONEXCLAMATION);
                        CASDialog(hwnd, IDD_RV, fRV);
                    }
                }
                else {
                    MessageBox(hwnd, L"EL PRECIO SOLO ACEPTA NUMEROS ENTEROS Y DECIMALES", L"ERROR EN PRECIO", MB_ICONINFORMATION);
                }
            }
            else {
                MessageBox(hwnd, L"Por favor llene todos los datos", L"Datos faltantes", MB_ICONINFORMATION);
            }

            break;
        }


    }
                   break;

    }
    return false;
}

INT_PTR CALLBACK fREG(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_INITDIALOG:
        hRUS = GetDlgItem(hwnd, IDC_US);
        hRCON = GetDlgItem(hwnd, IDC_PASS1);
        hRCON2 = GetDlgItem(hwnd, IDC_PASS2);
        hRNOM = GetDlgItem(hwnd, IDC_RNOM);
        hRAP = GetDlgItem(hwnd, IDC_RAP);
        hRAM = GetDlgItem(hwnd, IDC_RAM);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDOK: {
            GetWindowText(hRUS, RUS, 100);
            GetWindowText(hRCON, RCON, 100);
            GetWindowText(hRCON2, RCON2, 100);
            GetWindowText(hRNOM, RNOM, 100);
            GetWindowText(hRAP, RAP, 100);
            GetWindowText(hRAM, RAM, 100);
            string rus, rcon, rcon2, rnom, rap, ram;
            rus = fCharToS(RUS);
            rcon = fCharToS(RCON);
            rcon2 = fCharToS(RCON2);
            rnom = fCharToS(RNOM);
            rap = fCharToS(RAP);
            ram = fCharToS(RAM);
            NODOSIMPLEU* auxiliar;
            auxiliar = LISTA_U.ORIGEN;
            if (auxiliar != NULL) {
                bool salir = false;
                while (salir != true) {
                    if ((auxiliar->usuario->usuario) == rus) {
                        MessageBox(hwnd, L"CLAVE DE USUARIO YA REGISTRADA", L"CLAVE YA REGISTRADA", MB_ICONINFORMATION);
                        salir = true;
                        exit;
                    }
                    if (auxiliar->siguiente == NULL) {
                        salir = true;
                    }
                    else {
                        auxiliar = auxiliar->siguiente;
                    }
                }
                if ((auxiliar->siguiente == NULL) && (auxiliar->usuario->usuario != rus) && (rcon2 == rcon)) {
                    if (fComprobarS(rus) == false) {
                        MessageBox(hwnd, L"La clave de usuario no debe contener espacio", L"Clave con espacio", MB_ICONINFORMATION);
                        exit;
                    }
                    else if ((rnom.length() == 0) || (rap.length() == 0) || (ram.length() == 0)) {
                        MessageBox(hwnd, L"Llene todos los datos del usuario", L"Faltan datos", MB_ICONINFORMATION);
                        exit;
                    }
                    else {
                        LISTA_U.agregarNodoFinal(Usuario::NuevoUsuario(rus, rcon, rnom, rap, ram));
                        fEscribirU();
                        MessageBox(hwnd, L"Usuario registrado con exito", L"Registro exitoso", MB_ICONINFORMATION);
                        CASDialog(hwnd, IDD_IS, fInicioS);
                    }
                }
                else if ((auxiliar->siguiente == NULL) && (auxiliar->usuario->usuario != rus) && (rcon != rcon2)) {
                    MessageBox(hwnd, L"Las contraseñas no coinciden, ingreselas de nuevo", L"Contraseñas no coinciden", MB_ICONINFORMATION);
                }
            }
            else {
                if (rcon2 == rcon) {
                    if (fComprobarS(rus) == false) {
                        MessageBox(hwnd, L"La clave de usuario no debe contener espacio", L"Clave con espacio", MB_ICONINFORMATION);
                        exit;
                    }
                    else if ((rnom.length() == 0) || (rap.length() == 0) || (ram.length() == 0)) {
                        MessageBox(hwnd, L"Llene todos los datos del usuario", L"Faltan datos", MB_ICONINFORMATION);
                        exit;
                    }
                    else {
                        LISTA_U.agregarNodoFinal(Usuario::NuevoUsuario(rus, rcon, rnom, rap, ram));
                        fEscribirU();
                        MessageBox(hwnd, L"Usuario registrado con exito", L"Registro exitoso", MB_ICONINFORMATION);
                        CASDialog(hwnd, IDD_IS, fInicioS);
                    }
                }
                else if (rcon != rcon2) {
                    MessageBox(hwnd, L"Las contraseñas no coinciden, ingreselas de nuevo", L"Contraseñas no coinciden", MB_ICONINFORMATION);
                }
            }
        }
                 break;
        case IDCANCEL: {
            CASDialog(hwnd, IDD_IS, fInicioS);
        }
                     break;
        }
        break;
    }
    return false;
}

INT_PTR CALLBACK fRC(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);
        HWND hlbPer = GetDlgItem(hwnd, IDC_LIST);
        if (busqueda.size() != 0) {
            NODOSIMPLEP* auxiliar;
            auxiliar = LISTA_P.ORIGENP;
            while (auxiliar != NULL) {
                if (auxiliar->person->N == busqueda) {
                    int index = SendMessage(hlbPer, LB_INSERTSTRING, 0, (LPARAM)(fStoW(auxiliar->person->N)));
                    SendMessage(hlbPer, LB_SETITEMDATA, index, (LPARAM)auxiliar);
                }
                auxiliar = auxiliar->siguiente;
            }
        }
        fListaVacuna(hwnd);

        hBusqueda = GetDlgItem(hwnd, IDC_P);
        hNumero = GetDlgItem(hwnd, IDC_NUM);
        hInfo2 = GetDlgItem(hwnd, IDC_EDIT1);

        if (vacunaauxil.size() != 0) {
            SetWindowText(hInfo2, fStoW(vacunaauxil));
        }

        if (fotov2 == true) {
            fCBMP2(hwnd, auxiliarfoto);
            hInfo = GetDlgItem(hwnd, IDC_INFO);
            string informacion, informacion2, numero;
            numero = to_string(carnet + 1);
            informacion2 = "Nombre: ";
            informacion2.append(auxiliarc->N);
            informacion2.append(" ");
            informacion2.append(auxiliarc->AP);
            informacion2.append(" ");
            informacion2.append(auxiliarc->AM);
            informacion2.append(" Sexo: ");
            informacion2.append(auxiliarc->se);
            informacion2.append(" CURP: ");
            informacion2.append(auxiliarc->CURP);
            informacion2.append(" RFC: ");
            informacion2.append(auxiliarc->RFC);
            informacion2.append(" Grupo : ");
            informacion2.append(auxiliarc->GPO);
            informacion2.append(" Perfil de riesgo: ");
            informacion2.append(auxiliarc->PR);
            informacion2.append(" Telefono: ");
            informacion2.append(auxiliarc->tel);
            informacion2.append(" Direccion: ");
            informacion2.append(auxiliarc->DCA);
            informacion2.append(" ");
            informacion2.append(auxiliarc->DCO);
            informacion2.append(" ");
            informacion2.append(auxiliarc->DCI);
            informacion2.append(" ");
            informacion2.append(auxiliarc->DE);
            SetWindowText(hInfo, fStoW(informacion2));
            SetWindowText(hNumero, fStoW(numero));
        }
        EnableWindow(hNumero, FALSE);
    }
                      break;
    case WM_COMMAND: {
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {
        case IDC_LIST:
            switch (HIWORD(wparam)) {
            case LBN_SELCHANGE: {
                int index = SendDlgItemMessage(hwnd, IDC_LIST, LB_GETCURSEL, NULL, NULL);
                NODOSIMPLEP* select = (NODOSIMPLEP*)SendDlgItemMessage(hwnd, IDC_LIST, LB_GETITEMDATA, index, NULL);

                auxiliarc = select->person;
                auxiliarfoto = fStoW(select->person->DirFoto);
                fotov2 = true;
                CASDialog(hwnd, IDD_RC, fRC);
            }
                              break;
            }

            break;
        case IDC_VAC:
            switch (HIWORD(wparam)) {
            case LBN_SELCHANGE: {
                int index2 = SendDlgItemMessage(hwnd, IDC_VAC, LB_GETCURSEL, NULL, NULL);
                NODOSIMPLE* selectv = (NODOSIMPLE*)SendDlgItemMessage(hwnd, IDC_VAC, LB_GETITEMDATA, index2, NULL);
                bvac = selectv->vacuna->clabev;
                vacunaauxil = "Nombre: ";
                vacunaauxil.append(selectv->vacuna->nombre);
                vacunaauxil.append(" Clave: ");
                vacunaauxil.append(selectv->vacuna->clabev);
                vacunaauxil.append(" Descripcion: ");
                vacunaauxil.append(selectv->vacuna->descripcion);
                CASDialog(hwnd, IDD_RC, fRC);
            }
                              break;
            }
            break;
        case IDC_BP: {
            GetWindowText(hBusqueda, BUS, 100);
            busqueda = fCharToS(BUS);
            CASDialog(hwnd, IDD_RC, fRC);
        }
                   break;
        case IDOK: {
            if (bvac.size() != 0 && fotov2 == true) {
                carnet += 1;
                RegistroC(auxiliarc->RFC, bvac, carnet);
                bvac = "";
                MessageBox(hwnd, L"REGISTRO EXITOSO", L"REGISTRO CORRECTO", MB_ICONEXCLAMATION);
                fEscribirC();
                fHacerA();
                fotov2 = false;
                busqueda = "";
                vacunaauxil = "";
                CASDialog(hwnd, IDD_RC, fRC);
            }
            else {
                MessageBox(hwnd, L"SELECCIONE UNA VACUNA Y UNA PERSONA", L"LLENE TODOS LOS CAMPOS", MB_ICONEXCLAMATION);
            }
        }
                 break;
        case IDCANCEL: {

        }
                     break;
        }
        break;
    }
    }
    return false;
}

INT_PTR CALLBACK fEV(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);
        fListaVacuna(hwnd);
        if (listabv == true) {
            hInfoV = GetDlgItem(hwnd, IDC_EDIT1);
            string descripcion;
            descripcion = auxiliarv->descripcion;
            SetWindowText(hInfoV, fStoW(descripcion));
        }
    }
                      break;
    case WM_COMMAND:
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {
        case IDC_VAC:
            switch (HIWORD(wparam)) {
            case LBN_SELCHANGE: {
                int index2 = SendDlgItemMessage(hwnd, IDC_VAC, LB_GETCURSEL, NULL, NULL);
                NODOSIMPLE* selectv = (NODOSIMPLE*)SendDlgItemMessage(hwnd, IDC_VAC, LB_GETITEMDATA, index2, NULL);
                bvac = selectv->vacuna->clabev;
                auxiliarv = selectv->vacuna;
                listabv = true;
                CASDialog(hwnd, IDD_EV, fEV);
            }
                              break;
            }
            break;
        case IDOK: {
            if (bvac.size() != 0) {
                if (LISTA_C.ORIGEN != NULL) {
                    NODOSIMPLEC* aux;
                    aux = LISTA_C.ORIGEN;
                    while ((aux->carnet->clabev) != bvac) {
                        aux = aux->siguiente;
                    }
                    fEliminarNAV(aux->carnet);
                    aux = LISTA_C.ORIGEN;
                    while (aux != NULL) {
                        if (aux->carnet->clabev != bvac || ((aux->carnet->numeroc == LISTA_C.FIN->carnet->numeroc) && (aux->carnet->clabev != bvac))) {
                            aux = aux->siguiente;
                        }
                        if (aux != NULL) {
                            if (aux->carnet->clabev == bvac) {
                                LISTA_C.eliminarCarnet(to_string(aux->carnet->numeroc));
                                aux = LISTA_C.ORIGEN;
                            }
                        }
                    }
                    fEscribirC();
                    fLeerC();
                    fHacerA();

                }
                LISTA_S.eliminarVacuna(bvac);
                fEscribirV();
                bvac = "";
                fEscribirV();
                MessageBox(hwnd, L"Vacuna eliminada con exito", L"Vacuna eliminada", MB_ICONEXCLAMATION);
                listabv = false;
                auxiliarv = NULL;
                CASDialog(hwnd, IDD_EV, fEV);
            }
        }
                 break;
        }
        break;
    }
    return false;
}

INT_PTR CALLBACK fEP(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);

    }
                      break;
    case WM_COMMAND:
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {

        }
        break;
    }
    return false;
}

INT_PTR CALLBACK fEC(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);
        hBusqueda = GetDlgItem(hwnd, IDC_P);
        if (auxiliarc4 != NULL) {
            fCBMP2(hwnd, fStoW(auxiliarc4->nodopersona->DirFoto));
            hInfo = GetDlgItem(hwnd, IDC_INFO);
            string informacion, informacion2, numero, informacion3;
            numero = to_string(carnet + 1);
            informacion = "Nombre: ";
            informacion.append(auxiliarc4->nodopersona->N);
            informacion.append(" ");
            informacion.append(auxiliarc4->nodopersona->AP);
            informacion.append(" ");
            informacion.append(auxiliarc4->nodopersona->AM);
            informacion.append(" Sexo: ");
            informacion.append(auxiliarc4->nodopersona->se);
            informacion.append(" CURP: ");
            informacion.append(auxiliarc4->nodopersona->CURP);
            informacion.append(" RFC: ");
            informacion.append(auxiliarc4->nodopersona->RFC);
            informacion.append(" Grupo : ");
            informacion.append(auxiliarc4->nodopersona->GPO);
            informacion.append(" Perfil de riesgo: ");
            informacion.append(auxiliarc4->nodopersona->PR);
            informacion.append(" Telefono: ");
            informacion.append(auxiliarc4->nodopersona->tel);
            informacion.append(" Direccion: ");
            informacion.append(auxiliarc4->nodopersona->DCA);
            informacion.append(" ");
            informacion.append(auxiliarc4->nodopersona->DCO);
            informacion.append(" ");
            informacion.append(auxiliarc4->nodopersona->DCI);
            informacion.append(" ");
            informacion.append(auxiliarc4->nodopersona->DE);
            informacion.append(" Vacuna: ");
            informacion.append(auxiliarc4->nodovacuna->nombre);
            informacion.append(" Dosis: ");
            informacion.append(auxiliarc4->nodovacuna->dosis);
            informacion.append(" Clave de Vacuna: ");
            informacion.append(auxiliarc4->nodovacuna->clabev);
            SetWindowText(hInfo, fStoW(informacion));
        }
    }
                      break;
    case WM_COMMAND:
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {
        case IDC_BCB:
        {
            fotov3 = false;
            auxiliarc4 = NULL;
            GetWindowText(hBusqueda, BCAR, 100);
            if (BCAR[0] != 0) {
                for (int i = 0; i < (fCharToS(BCAR).length()); i++) {
                    if (!isdigit(BCAR[i])) {
                        validacion = false;
                    }
                }
                if (validacion == true) {
                    int numerobus = stoi(fCharToS(BCAR));
                    AUX = arbolCarnets.buscarPersona(numerobus);
                    if (AUX != NULL) {
                        auxiliarc4 = AUX->carnet;
                    }
                }
                else {
                    MessageBox(hwnd, L"USANDO BUSQUEDA SECUENCIAL", L"BUSQUEDA SECUENCIAL", MB_ICONASTERISK);
                    NODOSIMPLEC* AUXBUSC;
                    AUXBUSC = LISTA_C.ORIGEN;
                    while (AUXBUSC != NULL) {
                        if (AUXBUSC->carnet->nodopersona->N == fCharToS(BCAR)) {
                            auxiliarc4 = AUXBUSC->carnet;
                        }
                        AUXBUSC = AUXBUSC->siguiente;
                    }
                    validacion = true;
                }

                if (auxiliarc4 != NULL) {
                    fotov3 = true;
                    CASDialog(hwnd, IDD_EC, fEC);
                }
                else {
                    MessageBox(hwnd, L"Carnet no encontrado", L"Ingrese un numero valido", MB_ICONEXCLAMATION);
                    validacion = true;
                    for (int i = 0; i < (fCharToS(BCAR).length()); i++) {
                        BCAR[i] = NULL;
                    }
                    CASDialog(hwnd, IDD_EC, fEC);
                }

            }
            else {
                MessageBox(hwnd, L"Ingrese un numero de carnet para iniciar la busqueda", L"Ingrese un numero", MB_ICONEXCLAMATION);
            }
        }
        break;
        case IDOK: {
            if (fotov3 == true) {
                LISTA_C.eliminarCarnet(to_string(auxiliarc4->numeroc));
                arbolCarnets.eliminarArbol();
                fHacerA();
                fEscribirC();
                fotov3 = false;
                for (int i = 0; i < (fCharToS(BCAR).length()); i++) {
                    BCAR[i] = NULL;
                }
                AUX = NULL;
                auxiliarc4 = NULL;
                MessageBox(hwnd, L"Carnet Eliminado", L"Carnet Eliminado", MB_ICONEXCLAMATION);
                CASDialog(hwnd, IDD_EC, fEC);
            }
            else {
                MessageBox(hwnd, L"Primero ingrese un numero de carnet para buscar y eliminar", L"Ingrese un numero", MB_ICONEXCLAMATION);
            }
        }
                 break;
        }
        break;
    }
    return false;
}

INT_PTR CALLBACK fMV(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);
        fListaVacuna(hwnd);
        if (auxiliarv2 != NULL) {
            hTIPO = GetDlgItem(hwnd, IDC_TIPO);
            hMAR = GetDlgItem(hwnd, IDC_MAR);
            hPRE = GetDlgItem(hwnd, IDC_PRE);
            hNDOS = GetDlgItem(hwnd, IDC_NDOS);
            hCVAC = GetDlgItem(hwnd, IDC_CVAC);
            hDESC = GetDlgItem(hwnd, IDC_DESC);
            SetWindowText(hTIPO, fStoW(auxiliarv2->tipo));
            SetWindowText(hMAR, fStoW(auxiliarv2->nombre));
            SetWindowText(hPRE, fStoW(auxiliarv2->precio));
            SetWindowText(hNDOS, fStoW(auxiliarv2->dosis));
            SetWindowText(hCVAC, fStoW(auxiliarv2->clabev));
            SetWindowText(hDESC, fStoW(auxiliarv2->descripcion));
        }
    }
                      break;
    case WM_COMMAND:
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {
        case IDC_VAC:
            switch (HIWORD(wparam)) {
            case LBN_SELCHANGE: {
                int index2 = SendDlgItemMessage(hwnd, IDC_VAC, LB_GETCURSEL, NULL, NULL);
                NODOSIMPLE* selectv = (NODOSIMPLE*)SendDlgItemMessage(hwnd, IDC_VAC, LB_GETITEMDATA, index2, NULL);
                bvac = selectv->vacuna->clabev;
                auxiliarv2 = selectv->vacuna;
                listabv = true;
                CASDialog(hwnd, IDD_MV, fMV);
            }
                              break;
            }
            break;
        case IDC_ACEPTAR: {
            GetWindowText(hTIPO, TIPO, 100);
            GetWindowText(hMAR, MAR, 100);
            GetWindowText(hPRE, PRE, 100);
            GetWindowText(hNDOS, NDOS, 100);
            GetWindowText(hCVAC, CVAC, 100);
            GetWindowText(hDESC, DESC, 100);
            if ((TIPO[0] != 0) && (MAR[0] != 0) && (PRE[0] != 0) && (NDOS[0] != 0) && (CVAC[0] != 0) && (DESC[0] != 0)) {
                string comprobar = fCharToS(PRE);
                string comprobarcv = fCharToS(CVAC);
                if (fComprobarD(comprobar) == true) {
                    LISTA_S.modificarVacuna(auxiliarv2, TIPO, MAR, PRE, NDOS, CVAC, DESC);
                    NODOSIMPLEC* ayuda = LISTA_C.ORIGEN;
                    while (ayuda != NULL) {
                        if (ayuda->carnet->nodovacuna == auxiliarv2) {
                            LISTA_C.modificarCarnet(ayuda->carnet, ayuda->carnet->RFC, auxiliarv2->clabev, ayuda->carnet->numeroc, ayuda->carnet->nodopersona, auxiliarv2);
                        }
                        ayuda = ayuda->siguiente;
                    }
                    fEscribirP();

                    fEscribirV();
                    auxiliarv2 = NULL;
                    MessageBox(hwnd, L"LA VACUNA FUE MODIFICADA", L"MODIFICACION EXITOSA", MB_ICONINFORMATION);
                    CASDialog(hwnd, IDD_MV, fMV);
                }
                else {
                    MessageBox(hwnd, L"EL PRECIO SOLO ACEPTA NUMEROS ENTEROS Y DECIMALES", L"ERROR EN PRECIO", MB_ICONINFORMATION);
                }
            }
            else {
                MessageBox(hwnd, L"Por favor llene todos los datos", L"Datos faltantes", MB_ICONINFORMATION);
            }
        }
                        break;
        }
        break;
    }
    return false;
}

INT_PTR CALLBACK fMP(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);
        hAP = GetDlgItem(hwnd, IDC_AP);
        hAM = GetDlgItem(hwnd, IDC_AM);
        hNOM = GetDlgItem(hwnd, IDC_NOM);
        hCURP = GetDlgItem(hwnd, IDC_CURP);
        hRFC = GetDlgItem(hwnd, IDC_RFC);
        hDATIP = GetDlgItem(hwnd, IDC_DATETIMEPICKER1);
        hCALLE = GetDlgItem(hwnd, IDC_CALLE);
        hCOL = GetDlgItem(hwnd, IDC_COL);
        hCIU = GetDlgItem(hwnd, IDC_CIU);
        hEST = GetDlgItem(hwnd, IDC_EST);
        hESC = GetDlgItem(hwnd, IDC_ESC);
        hTEL = GetDlgItem(hwnd, IDC_TEL);
        hS = GetDlgItem(hwnd, IDC_S);
        hGO = GetDlgItem(hwnd, IDC_GO);
        hPR = GetDlgItem(hwnd, IDC_PR);
        hBusqueda = GetDlgItem(hwnd, IDC_P);
        string es1 = "Soltero";
        string es2 = "Casado";
        string es3 = "Separado";
        string es5 = "Viudo";
        string es6 = "Otro";
        string s1 = "Masculino";
        string s2 = "Femenino";
        string s3 = "Otros";
        wchar_t* solt1 = fStoW(es1);
        wchar_t* solt2 = fStoW(es2);
        wchar_t* solt4 = fStoW(es3);
        wchar_t* solt5 = fStoW(es5);
        wchar_t* solt6 = fStoW(es6);
        wchar_t* sw1 = fStoW(s1);
        wchar_t* sw2 = fStoW(s2);
        wchar_t* sw3 = fStoW(s3);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt1);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt2);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt4);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt5);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt6);
        SendMessage(hS, CB_ADDSTRING, 0, (LPARAM)sw1);
        SendMessage(hS, CB_ADDSTRING, 0, (LPARAM)sw2);
        SendMessage(hS, CB_ADDSTRING, 0, (LPARAM)sw3);
        HWND hlbPer = GetDlgItem(hwnd, IDC_LIST);
        if (busquedap.size() != 0) {
            NODOSIMPLEP* auxiliar;
            auxiliar = LISTA_P.ORIGENP;
            while (auxiliar != NULL) {
                if (auxiliar->person->N == busquedap) {
                    int index = SendMessage(hlbPer, LB_INSERTSTRING, 0, (LPARAM)(fStoW(auxiliar->person->N)));
                    SendMessage(hlbPer, LB_SETITEMDATA, index, (LPARAM)auxiliar);
                }
                auxiliar = auxiliar->siguiente;
            }
        }
        if (fotov2 == true) {
            fCBMP2(hwnd, auxiliarfoto);
            SetWindowText(hAP, fStoW(auxiliarc->AP));
            SetWindowText(hAM, fStoW(auxiliarc->AM));
            SetWindowText(hNOM, fStoW(auxiliarc->N));
            SetWindowText(hCURP, fStoW(auxiliarc->CURP));
            SetWindowText(hRFC, fStoW(auxiliarc->RFC));
            SetWindowText(hDATIP, fStoW(auxiliarc->nacimiento));
            SetWindowText(hCALLE, fStoW(auxiliarc->DCA));
            SetWindowText(hCOL, fStoW(auxiliarc->DCO));
            SetWindowText(hCIU, fStoW(auxiliarc->DCI));
            SetWindowText(hEST, fStoW(auxiliarc->DE));
            SetWindowText(hESC, fStoW(auxiliarc->DEC));
            SetWindowText(hTEL, fStoW(auxiliarc->tel));
            SetWindowText(hS, fStoW(auxiliarc->se));
            SetWindowText(hGO, fStoW(auxiliarc->GPO));
            SetWindowText(hPR, fStoW(auxiliarc->PR));
        }
    }
                      break;
    case WM_COMMAND:
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {
        case IDC_LIST:
            switch (HIWORD(wparam)) {
            case LBN_SELCHANGE: {
                int index = SendDlgItemMessage(hwnd, IDC_LIST, LB_GETCURSEL, NULL, NULL);
                NODOSIMPLEP* select = (NODOSIMPLEP*)SendDlgItemMessage(hwnd, IDC_LIST, LB_GETITEMDATA, index, NULL);

                auxiliarc = select->person;
                auxiliarfoto = fStoW(select->person->DirFoto);
                fotov2 = true;
                CASDialog(hwnd, IDD_MP, fMP);
            }
                              break;
            }

            break;
        case IDC_BUTTON1:
            GetWindowText(hBusqueda, BUSP, 100);
            busquedap = fCharToS(BUSP);
            validacionp = true;
            CASDialog(hwnd, IDD_MP, fMP);
            break;
        case IDOK: {
            SYSTEMTIME fecha;
            string sfecha;
            GetWindowText(hAP, AP, 100);
            GetWindowText(hAM, AMA, 100);
            GetWindowText(hNOM, NOM, 100);
            GetWindowText(hCURP, CURP, 100);
            GetWindowText(hRFC, RFC, 100);
            DateTime_GetSystemtime(hDATIP, &fecha);
            GetWindowText(hCALLE, CALLE, 100);
            GetWindowText(hCOL, COL, 100);
            GetWindowText(hCIU, CIU, 100);
            GetWindowText(hEST, EST, 100);
            GetWindowText(hESC, ESC, 100);
            GetWindowText(hTEL, TEL, 100);
            GetWindowText(hS, S, 100);
            GetWindowText(hGO, GO, 100);
            GetWindowText(hPR, PR, 100);
            sfecha = to_string(fecha.wDay);
            sfecha.append("/");
            sfecha.append(to_string(fecha.wMonth));
            sfecha.append("/");
            sfecha.append(to_string(fecha.wYear));
            if ((AP[0] != 0) && (AMA[0] != 0) && (NOM[0] != 0) && (CURP[0] != 0) && (RFC[0] != 0) && (CALLE[0] != 0) && (COL[0] != 0) && (CIU[0] != 0) && (EST[0] != 0) && (ESC[0] != 0) && (TEL[0] != 0) && (S[0] != 0) && (GO[0] != 0) && (PR[0] != 0)) {
                LISTA_P.modificarPersona(auxiliarc, AP, AMA, NOM, CURP, RFC, sfecha, CALLE, COL, CIU, EST, ESC, TEL, S, GO, PR, auxiliarfoto);
                NODOSIMPLEC* ayuda = LISTA_C.ORIGEN;
                while (ayuda != NULL) {
                    if (ayuda->carnet->nodopersona == auxiliarc) {
                        LISTA_C.modificarCarnet(ayuda->carnet, auxiliarc->RFC, ayuda->carnet->clabev, ayuda->carnet->numeroc, auxiliarc, ayuda->carnet->nodovacuna);
                    }
                    ayuda = ayuda->siguiente;
                }
                fEscribirP();
                auxiliarc = NULL;
                fEscribirC();
                MessageBox(hwnd, L"Persona modificada exitosamente", L"Cambios aplicados", MB_ICONINFORMATION);
            }
            else {
                MessageBox(hwnd, L"Por favor llene todos los datos", L"FALTA INFORMACION", MB_ICONINFORMATION);
            }
        }
                 break;
        case IDC_SDOC:
            auxiliarfoto = fExpBMP(hwnd, auxiliarfoto);
            if (auxiliarfoto[0] != 0) {
                MessageBox(hwnd, L"Foto cargada con exito", L"Hecho", MB_ICONASTERISK);
            }
            break;
        }
        break;
    }
    return false;
}

INT_PTR CALLBACK fMC(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);
        hBusqueda = GetDlgItem(hwnd, IDC_P);
        hBusqueda2 = GetDlgItem(hwnd, IDC_P2);
        hNUM = GetDlgItem(hwnd, IDC_NUM);
        EnableWindow(hNUM, FALSE);
        EnableWindow(hBusqueda2, FALSE);
        if (validacionmc == true) {
            fListaVacuna(hwnd);
            HWND hlbPer = GetDlgItem(hwnd, IDC_LIST);
            if (busqueda.size() != 0) {
                NODOSIMPLEP* auxiliar;
                auxiliar = LISTA_P.ORIGENP;
                while (auxiliar != NULL) {
                    if (auxiliar->person->N == busqueda) {
                        int index = SendMessage(hlbPer, LB_INSERTSTRING, 0, (LPARAM)(fStoW(auxiliar->person->N)));
                        SendMessage(hlbPer, LB_SETITEMDATA, index, (LPARAM)auxiliar);
                    }
                    auxiliar = auxiliar->siguiente;
                }
            }

            if (fotov3 == true) {
                EnableWindow(hBusqueda2, TRUE);

                fCBMP2(hwnd, fStoW(auxiliarc2->nodopersona->DirFoto));
                hInfo = GetDlgItem(hwnd, IDC_INFO2);
                hInfo2 = GetDlgItem(hwnd, IDC_INFO);
                hInfo3 = GetDlgItem(hwnd, IDC_EDIT1);
                string informacion, informacion2, numero, informacion3;
                numero = to_string(carnet + 1);
                informacion = "Nombre: ";
                informacion.append(auxiliarc2->nodopersona->N);
                informacion.append(" ");
                informacion.append(auxiliarc2->nodopersona->AP);
                informacion.append(" ");
                informacion.append(auxiliarc2->nodopersona->AM);
                informacion.append(" Direccion: ");
                informacion.append(auxiliarc2->nodopersona->DCA);
                informacion.append(" ");
                informacion.append(auxiliarc2->nodopersona->DCO);
                informacion.append(" ");
                informacion.append(auxiliarc2->nodopersona->DCI);
                informacion.append(" ");
                informacion.append(auxiliarc2->nodopersona->DE);
                informacion.append(" CURP: ");
                informacion.append(auxiliarc2->nodopersona->CURP);
                informacion.append(" RFC: ");
                informacion.append(auxiliarc2->nodopersona->RFC);
                informacion.append(" Vacuna: ");
                informacion.append(auxiliarc2->nodovacuna->nombre);
                SetWindowText(hInfo, fStoW(informacion));
                SetWindowText(hNUM, fStoW(to_string(auxiliarc2->numeroc)));
                if (fotov2 == true) {
                    informacion2 = "Nombre: ";
                    informacion2.append(auxiliarc2->nodopersona->N);
                    informacion2.append(" ");
                    informacion2.append(auxiliarc2->nodopersona->AP);
                    informacion2.append(" ");
                    informacion2.append(auxiliarc2->nodopersona->AM);
                    informacion2.append(" Direccion: ");
                    informacion2.append(auxiliarc2->nodopersona->DCA);
                    informacion2.append(" ");
                    informacion2.append(auxiliarc2->nodopersona->DCO);
                    informacion2.append(" ");
                    informacion2.append(auxiliarc2->nodopersona->DCI);
                    informacion2.append(" ");
                    informacion2.append(auxiliarc2->nodopersona->DE);
                    informacion2.append(" CURP: ");
                    informacion2.append(auxiliarc2->nodopersona->CURP);
                    informacion2.append(" RFC: ");
                    informacion2.append(auxiliarc2->nodopersona->RFC);
                    SetWindowText(hInfo2, fStoW(informacion2));
                }
                if (bvac.size() != 0) {
                    informacion3 = "Marca: ";
                    informacion3.append(auxiliarc2->nodovacuna->nombre);
                    informacion3.append(" Clave: ");
                    informacion3.append(auxiliarc2->nodovacuna->clabev);
                    informacion3.append(" Descripcion: ");
                    informacion3.append(auxiliarc2->nodovacuna->descripcion);

                    SetWindowText(hInfo3, fStoW(informacion3));
                }
            }
        }
    }
                      break;
    case WM_COMMAND:
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {
        case IDC_LIST:
            switch (HIWORD(wparam)) {
            case LBN_SELCHANGE: {
                int index = SendDlgItemMessage(hwnd, IDC_LIST, LB_GETCURSEL, NULL, NULL);
                NODOSIMPLEP* select = (NODOSIMPLEP*)SendDlgItemMessage(hwnd, IDC_LIST, LB_GETITEMDATA, index, NULL);
                auxiliarc2->nodopersona = select->person;
                auxiliarfoto = fStoW(select->person->DirFoto);
                fotov2 = true;
                CASDialog(hwnd, IDD_MC, fMC);
            }
                              break;
            }

            break;
        case IDC_VAC: {
            switch (HIWORD(wparam)) {
            case LBN_SELCHANGE:
                int index2 = SendDlgItemMessage(hwnd, IDC_VAC, LB_GETCURSEL, NULL, NULL);
                NODOSIMPLE* selectv = (NODOSIMPLE*)SendDlgItemMessage(hwnd, IDC_VAC, LB_GETITEMDATA, index2, NULL);
                auxiliarc2->nodovacuna = selectv->vacuna;
                bvac = selectv->vacuna->clabev;
                CASDialog(hwnd, IDD_MC, fMC);
                break;
            }
        }
                    break;
        case IDC_BCB:
        {
            fotov3 = false;
            auxiliarc2 = NULL;
            GetWindowText(hBusqueda, BCAR, 100);
            if (BCAR[0] != 0) {
                for (int i = 0; i < (fCharToS(BCAR).length()); i++) {
                    if (!isdigit(BCAR[i])) {
                        validacion = false;
                    }
                }
                if (validacion == true) {
                    int numerobus = stoi(fCharToS(BCAR));
                    AUX = arbolCarnets.buscarPersona(numerobus);
                    if (AUX != NULL) {
                        auxiliarc2 = AUX->carnet;
                        validacionmc = true;
                    }
                }
                else {
                    NODOSIMPLEC* AUXBUSC;
                    AUXBUSC = LISTA_C.ORIGEN;
                    while (AUXBUSC != NULL) {
                        if (AUXBUSC->carnet->nodopersona->N == fCharToS(BCAR)) {
                            auxiliarc2 = AUXBUSC->carnet;
                        }
                        AUXBUSC = AUXBUSC->siguiente;
                    }
                    validacion = true;
                    validacionmc = true;
                }

                if (auxiliarc2 != NULL) {
                    fotov3 = true;
                    CASDialog(hwnd, IDD_MC, fMC);
                }
                else {
                    MessageBox(hwnd, L"Carnet no encontrado", L"Ingrese un numero valido", MB_ICONEXCLAMATION);
                    validacion = true;
                    for (int i = 0; i < (fCharToS(BCAR).length()); i++) {
                        BCAR[i] = NULL;
                    }
                    CASDialog(hwnd, IDD_MC, fMC);
                }

            }
            else {
                MessageBox(hwnd, L"Ingrese un numero de carnet para iniciar la busqueda", L"Ingrese un numero", MB_ICONEXCLAMATION);
            }
        }
        break;
        case IDOK: {
            if (bvac.size() != 0 && fotov2 == true) {
                LISTA_C.modificarCarnet(AUX->carnet, auxiliarc2->nodopersona->RFC, auxiliarc2->nodovacuna->clabev, AUX->carnet->numeroc, auxiliarc2->nodopersona, auxiliarc2->nodovacuna);
                MessageBox(hwnd, L"CAMBIOS REALIZADOS CON EXITO", L"CAMBIOS EXITOSOS", MB_ICONEXCLAMATION);
                fEscribirC();
                fotov2 = false;
                fotov3 = false;
                busqueda = "";
                validacionmc = false;
                CASDialog(hwnd, IDD_MC, fMC);
            }
            else {
                MessageBox(hwnd, L"SELECCIONE UNA VACUNA Y UNA PERSONA", L"LLENE TODOS LOS CAMPOS", MB_ICONEXCLAMATION);
            }
        }
                 break;
        case IDC_BP: {
            GetWindowText(hBusqueda2, BUS, 100);
            busqueda = fCharToS(BUS);
            CASDialog(hwnd, IDD_MC, fMC);
        }
                   break;
        }
        break;
    }
    return false;
}

void fEscribirC() {
    NODOSIMPLEC* auxiliar;
    auxiliar = LISTA_C.ORIGEN;
    bool salir = false;
    ofstream archivoc("Carnets.txt");
    if (archivoc.is_open()) {
        if (auxiliar != NULL) {
            while (salir != true) {
                archivoc << auxiliar->carnet->RFC;
                archivoc << ",";
                archivoc << auxiliar->carnet->clabev;
                archivoc << ",";
                archivoc << auxiliar->carnet->numeroc;
                archivoc << "," << endl;
                if (auxiliar->siguiente == NULL) {
                    salir = true;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
        }
    }
    archivoc.close();
}

void fLeerC() {
    ifstream archivo("Carnets.txt");
    if (archivo.is_open()) {
        while (!archivo.eof()) {
            Carnet* nuevo = new Carnet;
            string lineac;
            getline(archivo, lineac);
            if ((lineac.length()) != 0) {
                nuevo->setRFC(lineac.substr(0, lineac.find(",")));
                lineac = lineac.substr(lineac.find(",") + 1);
                nuevo->setClave(lineac.substr(0, lineac.find(",")));
                lineac = lineac.substr(lineac.find(",") + 1);
                nuevo->setNumeroc(lineac.substr(0, lineac.find(",")));
                lineac = lineac.substr(lineac.find(",") + 1);
                LISTA_C.agregarNodoFinal(Carnet::nuevoCarnet(nuevo->RFC, nuevo->clabev, nuevo->numeroc));
            }
            delete nuevo;
        }
    }
    if (LISTA_C.FIN != NULL) {
        carnet = LISTA_C.FIN->carnet->numeroc;
    }
    archivo.close();
}

void fEscribirP() {
    NODOSIMPLEP* auxiliar;
    auxiliar = LISTA_P.ORIGENP;
    bool salir = false;
    ofstream archivop("Personas.txt");
    if (archivop.is_open()) {
        if (auxiliar != NULL) {
            while (salir != true) {
                archivop << auxiliar->person->AP;
                archivop << ",";
                archivop << auxiliar->person->AM;
                archivop << ",";
                archivop << auxiliar->person->N;
                archivop << ",";
                archivop << auxiliar->person->CURP;
                archivop << ",";
                archivop << auxiliar->person->nacimiento;
                archivop << ",";
                archivop << auxiliar->person->RFC;
                archivop << ",";
                archivop << auxiliar->person->DCA;
                archivop << ",";
                archivop << auxiliar->person->DCO;
                archivop << ",";
                archivop << auxiliar->person->DCI;
                archivop << ",";
                archivop << auxiliar->person->DE;
                archivop << ",";
                archivop << auxiliar->person->DEC;
                archivop << ",";
                archivop << auxiliar->person->tel;
                archivop << ",";
                archivop << auxiliar->person->se;
                archivop << ",";
                archivop << auxiliar->person->GPO;
                archivop << ",";
                archivop << auxiliar->person->PR;
                archivop << ",";
                archivop << auxiliar->person->DirFoto;
                archivop << "," << endl;
                if (auxiliar->siguiente == NULL) {
                    salir = true;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
        }
    }
    archivop.close();
}

void fLeerP() {
    ifstream archivo("Personas.txt");
    if (archivo.is_open()) {
        while (!archivo.eof()) {
            Persona* nueva = new Persona;
            string lineap;
            getline(archivo, lineap);
            if ((lineap.length()) != 0) {
                nueva->setAP(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setAM(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setN(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setCURP(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setNacimiento(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setRFC(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDCA(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDCO(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDCI(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDE(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDEC(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setTel(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setSe(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setGPO(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setPR(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDirFoto(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                LISTA_P.agregarNodoFinal(Persona::nuevaPersona(nueva->AP, nueva->AM, nueva->N, nueva->CURP, nueva->nacimiento, nueva->RFC, nueva->DCA, nueva->DCO, nueva->DCI, nueva->DE, nueva->DEC, nueva->tel, nueva->se, nueva->GPO, nueva->PR, nueva->DirFoto));
            }
            delete nueva;
        }
    }
    archivo.close();
}

void fEscribirV() {
    NODOSIMPLE* auxiliar;
    auxiliar = LISTA_S.ORIGEN;
    bool salir = false;
    ofstream archivov("Vacunas.txt");
    if (archivov.is_open()) {
        if (auxiliar != NULL) {
            while (salir != true) {
                archivov << auxiliar->vacuna->tipo;
                archivov << ",";
                archivov << auxiliar->vacuna->nombre;
                archivov << ",";
                archivov << auxiliar->vacuna->dosis;
                archivov << ",";
                archivov << auxiliar->vacuna->clabev;
                archivov << ",";
                archivov << auxiliar->vacuna->descripcion;
                archivov << ",";
                archivov << auxiliar->vacuna->precio;
                archivov << "," << endl;
                if (auxiliar->siguiente == NULL) {
                    salir = true;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
        }
    }
    archivov.close();
}

void leerArchivo() {
    ifstream archivo("Vacunas.txt");
    if (archivo.is_open()) {
        while (!archivo.eof()) {
            Vacuna* nueva = new Vacuna;
            string linea;
            getline(archivo, linea);
            if ((linea.length()) != 0) {
                nueva->setTipo(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                nueva->setNombre(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                nueva->setDosis(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                nueva->setClave(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                nueva->setDescripcion(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                nueva->setPrecio(linea.substr(0, linea.find(",")));
                LISTA_S.agregarNodoFinal(Vacuna::nuevaVacuna(nueva->tipo, nueva->nombre, nueva->dosis, nueva->clabev, nueva->descripcion, nueva->precio));
            }
            delete nueva;
        }
    }
    archivo.close();
}

void fEscribirU() {
    NODOSIMPLEU* auxiliar;
    auxiliar = LISTA_U.ORIGEN;
    bool salir = false;
    ofstream archivou("Usuario.txt");
    if (archivou.is_open()) {
        if (auxiliar != NULL) {
            while (salir != true) {
                archivou << auxiliar->usuario->usuario;
                archivou << ",";
                archivou << auxiliar->usuario->contrasena;
                archivou << ",";
                archivou << auxiliar->usuario->nombre;
                archivou << ",";
                archivou << auxiliar->usuario->ap;
                archivou << ",";
                archivou << auxiliar->usuario->am;
                archivou << "," << endl;
                if (auxiliar->siguiente == NULL) {
                    salir = true;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
        }
    }
    archivou.close();
}

void fLeerU() {
    ifstream archivo("Usuario.txt");
    if (archivo.is_open()) {
        while (!archivo.eof()) {
            Usuario* nuevo = new Usuario;
            string linea;
            getline(archivo, linea); {
                if ((linea.length()) != 0) {
                    nuevo->setUsuario(linea.substr(0, linea.find(",")));
                    linea = linea.substr(linea.find(",") + 1);
                    nuevo->setConstraseña(linea.substr(0, linea.find(",")));
                    linea = linea.substr(linea.find(",") + 1);
                    nuevo->setNombre(linea.substr(0, linea.find(",")));
                    linea = linea.substr(linea.find(",") + 1);
                    nuevo->setAP(linea.substr(0, linea.find(",")));
                    linea = linea.substr(linea.find(",") + 1);
                    nuevo->setAM(linea.substr(0, linea.find(",")));
                    LISTA_U.agregarNodoFinal(Usuario::NuevoUsuario(nuevo->usuario, nuevo->contrasena, nuevo->nombre, nuevo->ap, nuevo->am));
                }
                delete nuevo;
            }
        }
    }
    archivo.close();
}

bool fComprobarS(string comprobar) {
    for (int i = 0; i < comprobar.length(); i++) {
        if (isspace(comprobar[i])) {
            return false;
        }
    }
    return true;
}

bool fComprobarD(string prueba) {
    string punto = ".";
    for (int i = 0; i < prueba.length(); i++) {
        if (!isdigit(prueba[i]) && prueba[i] != punto[0]) {
            return false;
        }
    }
    return true;
}

wchar_t* fExpBMP(HWND hwnd, wchar_t* ubicacion) {
    ubicacion = new wchar_t[250];
    for (int i = 0; i < 250; i++) {
        ubicacion[i] = 0;
    }
    OPENFILENAME ofn;

    ZeroMemory(&ofn, sizeof(OPENFILENAME));

    ofn.hwndOwner = hwnd;
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.lpstrFile = ubicacion;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrDefExt = L"bmp";
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
    ofn.lpstrFilter = L"Bitmap\0*.bmp";

    if (GetOpenFileName(&ofn)) {

        HBITMAP hBitmap = (HBITMAP)LoadImage(
            NULL,
            ubicacion,
            IMAGE_BITMAP,
            100, 100, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
        HWND hPictureControl = GetDlgItem(hwnd, ID_PCIMAGEN1);
        SendMessage(hPictureControl, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
    }
    else {
        MessageBox(hwnd, L"No ha seleccionado ninguna imagen", L"NO CARGAR", MB_ICONASTERISK);
    }
    return ubicacion;
}

void fCBMP2(HWND hwnd, wchar_t* ubicacion) {
    HBITMAP hBitmap = (HBITMAP)LoadImage(
        NULL,
        ubicacion,
        IMAGE_BITMAP,
        100, 100, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
    HWND hPictureControl = GetDlgItem(hwnd, ID_PCIMAGEN1);
    SendMessage(hPictureControl, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
}

void fHacerA() {
    NODOSIMPLEC* ARBOL;
    ARBOL = LISTA_C.ORIGEN;
    while (ARBOL != NULL) {
        arbolCarnets.agregarNodo(ARBOL->carnet);
        ARBOL = ARBOL->siguiente;
    }
}

void fListaVacuna(HWND hwnd) {
    HWND hlbVac = GetDlgItem(hwnd, IDC_VAC);
    if (LISTA_S.ORIGEN != NULL) {
        NODOSIMPLE* auxiliar;
        auxiliar = LISTA_S.ORIGEN;
        while (auxiliar != NULL) {
            int index = SendMessage(hlbVac, LB_INSERTSTRING, 0, (LPARAM)(fStoW(auxiliar->vacuna->nombre)));
            SendMessage(hlbVac, LB_SETITEMDATA, index, (LPARAM)auxiliar);
            auxiliar = auxiliar->siguiente;
        }
    }
}