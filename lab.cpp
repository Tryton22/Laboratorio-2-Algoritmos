#include<iostream>
#include<string>

using namespace std;

class componentesInfo{
    private:
        string componente;
    public:
        componentesInfo(){
            this->componente = "";
        }
        
        void setComponente(string componenteNuevo){
            this->componente = componenteNuevo;
        }

        string getComponente(){
            return componente;
        }
};

class nodoComponente{
    private:
        componentesInfo valor;
        nodoComponente *vec;
    public:
        nodoComponente(){
            this->vec = NULL;
        }

        nodoComponente (componentesInfo componente){
            this->valor.setComponente(componente.getComponente());
            this->vec = NULL;
            
        }
        void setVec(nodoComponente *siguiente){
            this->vec = siguiente;
        }
        nodoComponente *getVec(){
            return (this->vec);
        }
        componentesInfo *getcomponentesInfo(){
            return(&this->valor);
        }
        
};

class pilaComponentes{
    private:
        nodoComponente *primero;

    public:
        void push(nodoComponente *nuevoNodo){
            nuevoNodo->setVec(primero);
            primero = nuevoNodo;
        }

        void pop(){
            if (primero == NULL){
                cout << "Lista Vacia" << endl;
                return;
            }

            nodoComponente *aux;
            aux = primero;
            primero = primero->getVec();
            delete aux;            
        }

        nodoComponente *getNode(){
            return (this->primero);
        }

        bool isEmpty(){
            if (primero == NULL){
                return true;
            }
            return false;
        }

};

int contarOperadores(string ejemplo, string operadorUno, string operadorDos){
    int contador = 0;
    for(int i=0; i < ejemplo.length(); i++){
            string actual = ejemplo.substr(i,1);;
            if (actual == operadorUno || actual == operadorDos){  
                contador++;
            }
        }

    return contador;
};

bool comprobarParentesis(string ejemplo){
    for(int i=0; i < ejemplo.length(); i++){
            string actual = ejemplo.substr(i,1);;

            if (actual == "("){  
                return true;
            }
        }
    return false;
};

string resultado(int numeroUno, int numeroDos, string operador){   
    int resultadoInt = 0;
    string resultado = "";

    if (operador == "+"){
        resultadoInt = numeroUno + numeroDos;
        resultado = to_string(resultadoInt);
        return resultado;
    }
    else if (operador == "-"){
        resultadoInt = numeroUno - numeroDos;
        resultado = to_string(resultadoInt);
        return resultado;
    }
    else if (operador == "/"){
        resultadoInt = numeroUno / numeroDos;
        resultado = to_string(resultadoInt);
        return resultado;
    }
    else if (operador == "*"){
        resultadoInt = numeroUno * numeroDos;
        resultado = to_string(resultadoInt);
        return resultado;
    }
    else{
        return resultado;
    }
};

int main(){

    string ejemplo;
    pilaComponentes numeros;
    pilaComponentes operadores;
    nodoComponente *auxiliar;
    componentesInfo *componente;
    string valor;
    
    
    cout << "Ingrese expresion matematica: ";
    getline(cin, ejemplo);
    
    string arreglo[ejemplo.length()];
    int componentes = 0;  
    string numeroActual = "";

    for(int i=0; i < ejemplo.length(); i++){
        string actual = ejemplo.substr(i,1);;
        
        if (actual == "+" || actual == "-" || actual == "*" || actual == "/"||
                 actual == "(" || actual == ")"){

            if (numeroActual != ""){
            arreglo[componentes] = numeroActual; 
            componentes++;
            }

            arreglo[componentes] = actual;
            componentes++;

            if (numeroActual != ""){
            numeroActual = "";
            }
        }
        else
            numeroActual += actual;      
    }

    if (numeroActual != ""){
        arreglo[componentes] = numeroActual;
        componentes++;
    }
    
    int contadorNumeros = 0;
    int contadorOperadoresMu = contarOperadores(ejemplo, "*", "/");
    int contadorParentesis = 0;
    bool existenParentesis = comprobarParentesis(ejemplo);
    bool existieronParentesis = comprobarParentesis(ejemplo);

    if (existenParentesis == true){
        contadorParentesis = contarOperadores(ejemplo, "(", ")");
    }


    for(int i= 0; i < componentes; i++){
        if (arreglo[i] == "+" || arreglo[i] == "-" || arreglo[i] == "*" ||
            arreglo[i] == "/" || arreglo[i] == "(" || arreglo[i] == ")"){
            
            componentesInfo operador;
            operador.setComponente(arreglo[i]);
            nodoComponente *nuevo = new nodoComponente(operador);
            operadores.push(nuevo);
            valor = operadores.getNode()->getcomponentesInfo()->getComponente();
            
            if (existieronParentesis == true){
                if (valor == "("){
                    contadorParentesis = contadorParentesis - 2;
                }

                 if (valor == ")"){
                    if (contadorParentesis == 0){
                        existenParentesis = false;
                        operadores.pop();
                    }

                    //while (operadores.isEmpty() != true){
                        valor = operadores.getNode()->getcomponentesInfo()->getComponente();
                        if (valor == "*" ||
                            valor == "/"){
                            if (existenParentesis == false){
                                string numeroUno, numeroDos, operador;
                                int unoInt, dosInt;

                                valor = numeros.getNode()->getcomponentesInfo()->getComponente();
                                numeroDos = valor;
                                numeros.pop();

                                valor = numeros.getNode()->getcomponentesInfo()->getComponente();
                                numeroUno = valor;
                                numeros.pop();

                                valor = operadores.getNode()->getcomponentesInfo()->getComponente();
                                operador = valor;
                                operadores.pop();
                                    
                                unoInt = stoi(numeroUno);
                                dosInt = stoi(numeroDos);

                                componentesInfo numero;
                                numero.setComponente(resultado(unoInt, dosInt, operador));
                                nodoComponente *nuevo = new nodoComponente(numero);
                                numeros.push(nuevo);
                                contadorOperadoresMu--;
                            }   
                        }
                                
                        if (valor == "+" ||
                            valor == "-"){
                            if (existenParentesis == false){
                                if (contadorOperadoresMu == 0){
                                    string numeroUno, numeroDos, operador;
                                    int unoInt, dosInt;

                                    valor = numeros.getNode()->getcomponentesInfo()->getComponente();
                                    numeroDos = valor;
                                    numeros.pop();

                                    valor = numeros.getNode()->getcomponentesInfo()->getComponente();
                                    numeroUno = valor;
                                    numeros.pop();

                                    valor = operadores.getNode()->getcomponentesInfo()->getComponente();
                                    operador = valor;
                                    operadores.pop();
                                    
                                    unoInt = stoi(numeroUno);
                                    dosInt = stoi(numeroDos);

                                    componentesInfo numero;
                                    numero.setComponente(resultado(unoInt, dosInt, operador));
                                    nodoComponente *nuevo = new nodoComponente(numero);
                                    numeros.push(nuevo);
                                }   
                            }
                        }
                        if (valor == "("){
                                operadores.pop();
                        }
                    //}
                }
            }
        }

        else{
                componentesInfo numero;
                numero.setComponente(arreglo[i]);
                nodoComponente *nuevo = new nodoComponente(numero);
                numeros.push(nuevo);
                contadorNumeros++;
            }

        if (existieronParentesis == false && contadorNumeros > 2){
            valor = operadores.getNode()->getcomponentesInfo()->getComponente();
            if ((valor == "*" || valor == "/") && contadorNumeros > 1){
                string numeroUno, numeroDos, operador;
                int unoInt, dosInt;

                valor = numeros.getNode()->getcomponentesInfo()->getComponente();
                numeroDos = valor;
                numeros.pop();

                valor = numeros.getNode()->getcomponentesInfo()->getComponente();
                numeroUno = valor;
                numeros.pop();

                valor = operadores.getNode()->getcomponentesInfo()->getComponente();
                operador = valor;
                operadores.pop();
                                        
                unoInt = stoi(numeroUno);
                dosInt = stoi(numeroDos);

                componentesInfo numero;
                numero.setComponente(resultado(unoInt, dosInt, operador));
                nodoComponente *nuevo = new nodoComponente(numero);
                numeros.push(nuevo);
                contadorOperadoresMu--;                                      
            }
                           
            valor = operadores.getNode()->getcomponentesInfo()->getComponente();
            if (valor == "+" || valor == "-"){
                if (contadorOperadoresMu == 0){
                    //while (operadores.isEmpty() == false){ 
                    string numeroUno, numeroDos, operador;
                    int unoInt, dosInt;

                    valor = numeros.getNode()->getcomponentesInfo()->getComponente();
                    numeroDos = valor;
                    numeros.pop();

                    valor = numeros.getNode()->getcomponentesInfo()->getComponente();
                    numeroUno = valor;
                    numeros.pop();

                    valor = operadores.getNode()->getcomponentesInfo()->getComponente();
                    operador = valor;
                    operadores.pop();
                                        
                    unoInt = stoi(numeroUno);
                    dosInt = stoi(numeroDos);

                    componentesInfo numero;
                    numero.setComponente(resultado(unoInt, dosInt, operador));
                    nodoComponente *nuevo = new nodoComponente(numero);
                    numeros.push(nuevo);
                    //}                                                       
                }
            }
            
        }
        
    
    }
    
    valor = numeros.getNode()->getcomponentesInfo()->getComponente();
    cout << "El resultado final es: " << valor << endl;
    return 0;

}