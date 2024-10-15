/*
   ESTE FOI UM CODIGO PROPOSTO PELO MEU PROFESSOR DE PROGRAMA��O.
   ONDE TEMOS QUE SOLICITAR AO USUARIO O NOME, DUAS NOTAS, APRESENTAR A SOMA E AO FIM 
   APRESENTAR A SITUA��O DESSE ALUNO. COMO APROVADO OU N�O. 
   
   FOI SOLICIDADO O USO DE FUN��ES PARA A MONTAGEM DO CODIGO.
*/

#include <iostream>
using namespace std;

// Declara��o das fun��es ---------------
bool simOuNao(string texto);
char getChar(string texto);
void alerta(string msg);
string nomeDoEstudante();
int primeiraNota(string nomeEstudante);
int segundaNota(string nomeEstudante);
int calculoTotalDasNotas(int notaP1, int notaP2, string nomeEstudante,int notaTotal);
void testeDeAprovacao(int notaTotal, string nomeEstudante);
//---------------------------------------


int main()
{
    setlocale(LC_ALL,"");  // Ativa o uso de acentos
    // -------------------------------

    int opcao, notaP1, notaP2, notaTotal;
    string nomeEstudante;
    bool continuar;
    
    notaP1= 0;
    notaP2= 0;
    notaTotal= 0;
    
    
    continuar = true; // condi��o para o la�o iterar

    do
    {
        system("cls");
        cout << ">>> MENU DE OP��ES <<<\n\n";
        cout << "1  - INFORMAR NOME DO ESTUDANTE\n";
        cout << "2  - NOTA DA 1� AVALIA��O\n";
        cout << "3  - NOTA DA 2� AVALIA��O\n";
        cout << "4  - CALCULAR NOTA TOTAL\n";
        cout << "5  - SITUA��O AP�S NOTA TOTAL\n";
        cout << "0  - FINALIZAR O PROGRAMA\n\n";
        cout << "SUA OP��O --> ";
        cin >> opcao;
        
// AREA DOS CASES        
        switch(opcao)
        {
             case 1: nomeEstudante= nomeDoEstudante();
                          
                     break;
                     // ---------------------------------
             case 2: notaP1= primeiraNota(nomeEstudante);
                    
                     break;
                     // ---------------------------------
             case 3: notaP2= segundaNota(nomeEstudante);
                     break;
                     // ---------------------------------
             case 4: notaTotal= calculoTotalDasNotas(notaP1, notaP2, nomeEstudante,notaTotal);
                    
                     break;
                     // ---------------------------------
             case 5: testeDeAprovacao(notaTotal,nomeEstudante);
                     break;
                     // ---------------------------------
             case 0:
                     if(simOuNao("CONFIRMA FINALIZAR O PROGRAMA?"))
                     {
                         continuar = false;
                     }
                     break;
                     // ---------------------------------
             default: alerta("OP��O INV�LIDA, TENTE NOVAMENTE <Enter>");
        }                
    }while(continuar);
    system("CLS");
    cout << "PROGRAMA FINALIZADO\n";
    // -------------------------------
    system("pause");
    return 0;
}

//AREA DAS FUNCOES-----------------------------------
bool simOuNao(string texto) // Escolhe SIM ou N�0
{
    char  sn;
    cout << texto;
    sn = getChar("\nDigite 's' para SIM ou 'n' para N�O: ");
    cout << "\n";
    if(sn=='s' || sn=='S')
    {
        return true;
    }else{
        return false;
    }
}

char getChar(string texto)  // Recebe um CHAR e retorna essa escolha
{
    char caractere;
    cout << texto;
    cin >> caractere;
    return caractere;
}

void alerta(string msg)  // Apresenta uma mensagem 
{
    cout << "\n" << msg << "\n";
    system("pause>null");
}


                //CASE 01: SOLICITA O NOME DO ALUNO AO USUARIO 
                
string nomeDoEstudante()
{
    string nome;
    
    cout << "Digite o nome do aluno: \n";
    cin >> nome;
    return nome;
}

                //CASE 02: SOLICITA A 1� NOTA AO USUARIO 
                
int primeiraNota(string nomeEstudante)
{
    int primeiraNotaP1;
    cout << "Digite a nota da P1 do " << nomeEstudante << ":\n";
    cin >> primeiraNotaP1;
    return primeiraNotaP1; 
}

                // CASE 03: SOLICITA A 2� NOTA AO USUARIO 

int segundaNota(string nomeEstudante)
{
    int segundaNotaP2;
    cout << "Digite a nota da P2 do " << nomeEstudante << " : \n ";
    cin >> segundaNotaP2;
    return segundaNotaP2;
   
}

                // CASE 04: APRESENTA A SOMA DAS NOTAS P1 E P2.
 
int calculoTotalDasNotas(int notaP1, int notaP2, string nomeEstudante, int notaTotal)
{
    int somaDasNotas;
    notaTotal= notaP1 + notaP2;
    cout << "A nota final do " << nomeEstudante << " foi: " << notaTotal << " pontos." "\n"; 
    system("pause>>null"); 
 
    return notaTotal;
     
}

                // CASE 05: AQUI ONDE � FEITO O TESTE PARA SABER SE  ALUNO ESTA APROVAFO OU N�O. 

void testeDeAprovacao(int notaTotal, string nomeEstudante)
{
    if(notaTotal>= 60){
        cout << "O aluno "<< nomeEstudante <<" se encontra Aprovado. Sua nota final foi: "<< notaTotal << " pontos " "\n";
    }else{
        cout << "O aluno " << nomeEstudante <<" se encontra reprovado. Sua nota final foi abaixo de 60 pontos.";
        
    }
    system("pause>>null");
}
