#include <stdio.h>
#include <stdlib.h>
//Structs do programa
struct jogador{
    int id;
    char nome[50];
    char role[4];
    int idade;
};
struct jogador Jogadores[10];

struct time{
    char nomeTime[50];
    char nomeCoach[50];
};
struct time Times[2];

struct partida {
    int kill[10];
    int death[10];
    int assist[10];
    int killTime;
    int killInimiga;
    int assistTime;
    int assistInimiga;
    int torresAliadas;
    int torresInimigo;
    int win;
    int pontuacao[10];
    int mvp;
    int quantPartidas;
    int mvpInverso;
};
struct partida Dados[50];
//Declaração das funções
void registraTime (struct jogador * , struct time *);
void listaTime (struct jogador *, struct time *);
void alteraJogador (struct jogador *, struct time *);
void cadastraPartida (struct partida *);
void listaPartida (struct jogador *, struct time *, struct partida *);
void pesquisaJogador (struct jogador *, struct partida *);
void listaMVPInverso (struct jogador *, struct partida *, struct time *);
void listaMVP (struct jogador *, struct partida *, struct time *);
void listaTotalKills (struct time *, struct partida *);
//Código Principal
int main()
{
    int op;
    while (op != 10){
        menu();
        scanf("%i",&op);
        switch (op) {
            case 1:
                registraTime(Jogadores,Times);
                limpaTela();
                break;
            case 2:
                listaTime(&Jogadores, &Times);
                limpaTela();
                break;
            case 3:
                alteraJogador(Jogadores, &Times);
                limpaTela();
                break;
            case 4:
                cadastraPartida(Dados);
                limpaTela();
                break;
            case 5:
                listaPartida(&Jogadores, &Times, &Dados);
                limpaTela();
                break;
            case 6:
                pesquisaJogador(&Jogadores,&Dados);
                limpaTela();
                break;
            case 7:
                listaTotalKills(&Times, &Dados);
                limpaTela();
                break;
            case 8:
                listaMVPInverso (&Jogadores,&Dados,&Times);
                limpaTela();
                break;
            case 9:
                listaMVP(&Jogadores,&Dados,&Times);
                limpaTela();
                break;
            case 10:
                printf("\nVOCE SAIU DO PROGRAMA, OBRIGADO !!!!! \n");
                break;
            default:
                printf("Voce inseriu uma opcao invalida, tente novamente \n");
                limpaTela();
        }
    }
    return 0;
}

//Funções
void menu() {
    printf("1) Cadastrar times\n2) Listar time\n3) Editar time\n4) Cadastrar partida\n5) Listar partidas\n6) Pesquisar jogador\n7) Mostrar numero total de kills e assistencias\n8) Mostrar jogador com menor pontuacao\n9) Mostrar jogador com maior pontuacao\n10) Sair\n");
}

void limpaTela(){
    system("Pause");
    system("cls");
}

void registraTime (struct jogador Jogadores[10], struct time Times[2]){
    int aux;
    printf("Qual time voce deseja registrar ? ");
    scanf("%i",&aux);
    while (aux != 1 && aux !=2){
        printf("Voce inseriu uma opcao invalida, tente novamente: ");
        scanf("%i",&aux);
    }
    //TIME 1
    if (aux == 1){
        printf("--------- TIME 1 ---------\n");
        printf("Escreva o nome do time: ");
        scanf("%s",&Times[0].nomeTime);
        printf("Escreva o nome do coach: ");
        scanf("%s",&Times[0].nomeCoach);
        aux = 0;
        for (int i=0;i<5;i++){
            aux=0;
            printf("---------- JOGADOR %i ----------\n",i+1);
            printf("A ID cadastrada desse jogador sera: %i \n",i+1);
            Jogadores[i].id = i+1;
            printf("Insira o nome do jogador: ");
            scanf("%s",&Jogadores[i].nome);
            //PARTE DAS ROLES
            printf("Insira a role (TOP,JG,MID,ADC,SUP):");
            scanf("%s",&Jogadores[i].role);
             while (aux == 0) {
                if (strcmp(Jogadores[i].role, "TOP")==0)
                    aux = 1;
                if (strcmp(Jogadores[i].role, "JG")==0)
                    aux = 1;
                if (strcmp(Jogadores[i].role, "MID")==0)
                    aux = 1;
                if (strcmp(Jogadores[i].role, "ADC")==0)
                    aux = 1;
                if (strcmp(Jogadores[i].role, "SUP")==0)
                    aux = 1;
                if (aux == 0){
                    printf("Voce inseriu uma role invalida, tente novamente: ");
                    scanf("%s",&Jogadores[i].role);
                }
            }
            //PARTE DAS IDADES
            aux=0;
            while (aux == 0){
            printf("Insira a idade do jogador %i:",i+1);
            scanf("%i",&Jogadores[i].idade);
                if (Jogadores[i].idade >= 1 && Jogadores[i].idade <= 150)
                    aux=1;
                if (aux==0)
                    printf("Voce inseriu uma idade invalida \n");
            }
            printf("\n\n\n\n\n");
        }
        printf("Parabens, voce cadastrou o time 1!!!\n");
    }
    //TIME 2
    if (aux == 2){
        printf("--------- TIME 2 ---------\n");
        printf("Escreva o nome do time: ");
        scanf("%s",&Times[1].nomeTime);
        printf("Escreva o nome do coach: ");
        scanf("%s",&Times[1].nomeCoach);
        for (int i=5;i<10;i++){
            aux=0;
            printf("---------- JOGADOR %i ----------\n",i+1);
            printf("A ID cadastrada desse jogador sera: %i \n",i+1);
            Jogadores[i].id = i+1;
            printf("Insira o nome do jogador: ");
            scanf("%s",&Jogadores[i].nome);
            //PARTE DAS ROLES
            printf("Insira a role (TOP,JG,MID,ADC,SUP):");
            scanf("%s",&Jogadores[i].role);
             while (aux == 0) {
                if (strcmp(Jogadores[i].role, "TOP")==0)
                    aux = 1;
                if (strcmp(Jogadores[i].role, "JG")==0)
                    aux = 1;
                if (strcmp(Jogadores[i].role, "MID")==0)
                    aux = 1;
                if (strcmp(Jogadores[i].role, "ADC")==0)
                    aux = 1;
                if (strcmp(Jogadores[i].role, "SUP")==0)
                    aux = 1;
                if (aux == 0){
                    printf("Voce inseriu uma role invalida, insira novamente: ");
                    scanf("%s",&Jogadores[i].role);
                }
            }
            //PARTE DAS IDADES
            aux=0;
            while (aux == 0){
            printf("Insira a idade do jogador %i:",i+1);
            scanf("%i",&Jogadores[i].idade);
                if (Jogadores[i].idade >= 1 && Jogadores[i].idade <= 150)
                    aux=1;
                if (aux==0)
                    printf("Voce inseriu uma idade invalida\n");
            }
            printf("\n\n\n\n\n");
        }
        printf("Parabens, voce cadastrou o time 2!!!\n");
    }
}

void listaTime (struct jogador Jogadores[10], struct time Times[2]){
    int aux;
    printf("Qual time voce deseja ver? ");
    scanf("%i",&aux);
    while (aux != 1 && aux !=2){
        printf("Voce inseriu uma opcao invalida, tente novamente: ");
        scanf("%i",&aux);
    }
    //TIME 1
    if (aux == 1){
        printf ("----------- TIME 1 -----------\n");
        printf("%s\n",Times[0].nomeTime);
        printf ("----------- COACH -----------\n");
        printf ("%s\n",Times[0].nomeCoach);
        printf ("ID  ---- NOME ---- ROLE\n");
        for (int i=0;i<5;i++){
            printf("%i ---- %s ---- %s\n",Jogadores[i].id,Jogadores[i].nome,Jogadores[i].role);
        }
    }
    //TIME 2
    if (aux == 2){
        printf ("----------- TIME 2 -----------\n");
        printf("%s\n",Times[1].nomeTime);
        printf ("----------- COACH -----------\n");
        printf ("%s\n",Times[1].nomeCoach);
        printf ("ID  ---- NOME ---- ROLE\n");
        for (int i=5;i<10;i++){
            printf("%i ---- %s ---- %s\n",Jogadores[i].id,Jogadores[i].nome,Jogadores[i].role);
        }
    }
}

void alteraJogador (struct jogador Jogadores[10], struct time Times[2]){
    int aux,confirma=0,aux2=0;
    printf("Qual time voce deseja alterar? ");
    scanf ("%i",&aux);
    while (aux != 1 && aux !=2){
        printf("Voce inseriu uma opcao invalida, tente novamente: ");
        scanf("%i",&aux);
    }
    if (aux ==1){
        printf("---- TIME 1 ---- \n");
        for(int i=0;i<5;i++){
            printf("%i ---- %s ---- %s --- %i\n",Jogadores[i].id,Jogadores[i].nome,Jogadores[i].role,Jogadores[i].idade);
        }
        printf("Qual a ID do jogador que voce deseja alterar ? ");
        scanf("%i",&aux);
        while (aux > 5 || aux < 1){
            printf("Voce inseriu uma opcao invalida, tente novamente: ");
            scanf("%i",&aux);
        }
        aux = aux - 1;
        printf("O usuario escolhido foi: %i --- %s --- %s --- %i. Digite 1 para confirmar ou 0 para voltar pro menu: ",Jogadores[aux].id,Jogadores[aux].nome,Jogadores[aux].role,Jogadores[aux].idade);
        scanf("%i",&confirma);
        while(confirma != 1 && confirma !=0){
            printf("Voce inseriu uma opcao invalida, tente novamente: ");
            scanf("%i",&confirma);
        }
        if (confirma == 1){
            printf("Digite o novo nome: ");
            scanf("%s",&Jogadores[aux].nome);
            while (aux2 == 0) {
                printf("Insira a role (TOP,JG,MID,ADC,SUP):");
                scanf("%s",&Jogadores[aux].role);
                if (strcmp(Jogadores[aux].role, "TOP")==0)
                    aux2 = 1;
                if (strcmp(Jogadores[aux].role, "JG")==0)
                    aux2 = 1;
                if (strcmp(Jogadores[aux].role, "MID")==0)
                    aux2 = 1;
                if (strcmp(Jogadores[aux].role, "ADC")==0)
                    aux2 = 1;
                if (strcmp(Jogadores[aux].role, "SUP")==0)
                    aux2= 1;
                if (aux2 == 0)
                printf("Voce inseriu uma role invalida\n");
            }
            aux2=0;
            while (aux2 == 0){
            printf("Insira a nova idade: ");
            scanf("%i",&Jogadores[aux].idade);
                if (Jogadores[aux].idade >= 1 && Jogadores[aux].idade <= 150)
                    aux2=1;
                if (aux2==0)
                    printf("Voce inseriu uma idade invalida\n");
            }
        }
        if (confirma == 0)
            printf("Voce voltou ao menu!!!\n");
    }
    if (aux ==2){
        printf("---- TIME 1 ---- \n");
        for(int i=5;i<10;i++){
            printf("%i ---- %s ---- %s --- %i\n",Jogadores[i].id,Jogadores[i].nome,Jogadores[i].role,Jogadores[i].idade);
        }
        printf("Qual a ID do jogador que voce deseja alterar ? ");
        scanf("%i",&aux);
        while (aux > 10 || aux < 5){
            printf("Voce inseriu uma opcao invalida, tente novamente: ");
            scanf("%i",&aux);
        }
        aux--;
        printf("O usuario escolhido foi: %i --- %s --- %s --- %i. Digite 1 para confirmar ou 0 para voltar pro menu: ",Jogadores[aux].id,Jogadores[aux].nome,Jogadores[aux].role,Jogadores[aux].idade);
        scanf("%i",&confirma);
        while(confirma != 1 && confirma !=0){
            printf("Voce inseriu uma opcao invalida, tente novamente: ");
            scanf("%i",&confirma);
        }
        if (confirma == 1){
            printf("Digite o novo nome: ");
            scanf("%s",&Jogadores[aux].nome);
            while (aux2 == 0) {
                printf("Insira a role (TOP,JG,MID,ADC,SUP):");
                scanf("%s",&Jogadores[aux].role);
                if (strcmp(Jogadores[aux].role, "TOP")==0)
                    aux2 = 1;
                if (strcmp(Jogadores[aux].role, "JG")==0)
                    aux2 = 1;
                if (strcmp(Jogadores[aux].role, "MID")==0)
                    aux2 = 1;
                if (strcmp(Jogadores[aux].role, "ADC")==0)
                    aux2 = 1;
                if (strcmp(Jogadores[aux].role, "SUP")==0)
                    aux2= 1;
                if (aux2 == 0)
                printf("Voce inseriu uma role invalida, todos os caracteres tem que ser maiusculo\n");
            }
            aux2 = 0;
            while (aux2 == 0){
            printf("Insira a nova idade: ");
            scanf("%i",&Jogadores[aux].idade);
                if (Jogadores[aux].idade >= 1 && Jogadores[aux].idade <= 150)
                    aux2=1;
                if (aux2==0)
                    printf("Voce inseriu uma idade invalida\n");
            }
        }
        if (confirma == 0)
            printf("Voce voltou ao menu!!!");
    }
}

void cadastraPartida (struct partida Dados[50]){
    int qPartidas=0,aux=0,aux2=0,maior=0,menor=9999;
    printf("Quantas partidas voce deseja registrar? ");
    scanf("%i",&qPartidas);
    while(qPartidas < 1){
        printf("Voce inseriu uma opcao invalida, tente novamente: ");
        scanf("%i",&qPartidas);
    }
    Dados[0].quantPartidas = qPartidas;
    for (int i=0;i<qPartidas;i++){
        aux=0;
        aux2=0;
        printf("----- PARTIDA %i -----\n",i+1);
        for(int ii=0;ii<5;ii++){
            printf("----- JOGADOR %i -----\n",ii+1);
            printf("Kills: ");
            scanf("%i",&Dados[i].kill[ii]);
            printf("Assists: ");
            scanf("%i",&Dados[i].assist[ii]);
            printf("Deaths: ");
            scanf("%i",&Dados[i].death[ii]);
            printf("\n\n\n");
            //Parte de dados para o programa calcular
            aux = Dados[i].kill[ii] + aux;
            aux2 = Dados[i].death[ii] + aux2;
            Dados[i].pontuacao[ii] = Dados[i].kill[ii]*3 + Dados[i].assist[ii];
            if (Dados[i].pontuacao[ii] > maior)
                maior = Dados[i].pontuacao[ii];
            if (Dados[i].pontuacao[ii] < menor)
                menor = Dados[i].pontuacao[ii];
            Dados[i].assistTime = Dados[i].assistTime + Dados[i].assist[ii];
        }
        printf("Quantas kills o time 1 teve? ");
        scanf("%i",&Dados[i].killTime);
        if (aux != Dados[i].killTime)
            printf("Voce inseriu um valor diferente da soma das kills do time 1 na partida\n");
        printf("Quantas kills teve o time 2? ");
        scanf("%i",&Dados[i].killInimiga);
        if (aux2 != Dados[i].killInimiga)
            printf("Voce inseriu um valor diferente da soma das kills do time 2 na partida\n");
        aux=0;
        aux2=0;
        printf("Qual time ganhou? ");
        scanf("%i",&aux);
        if(aux == 1)
            Dados[i].win = 1;
        if(aux == 2)
            Dados[i].win = 0;
        while(aux != 1 && aux !=2){
            printf("Voce inseriu uma opcao invalida, tente novamente: ");
            scanf("%i",&aux);
        }
        printf("Quantas torres o time 1 levou? ");
        scanf("%i",&Dados[i].torresAliadas);
        while (Dados[i].torresAliadas > 11 || Dados[i].torresAliadas<0){
            printf("Voce inseriu uma opcao invalida, tente novamente: ");
            scanf("%i",&Dados[i].torresAliadas);
        }
        printf("Quantas torres o time 2 levou? ");
        scanf("%i",&Dados[i].torresInimigo);
        while (Dados[i].torresInimigo > 11 || Dados[i].torresInimigo<0){
            printf("Voce inseriu uma opcao invalida, tente novamente: ");
            scanf("%i",&Dados[i].torresInimigo);
        }
        for (int i=0;i<qPartidas;i++){
            for(int ii = 0;ii<5;ii++){
                if (Dados[i].pontuacao[ii] == maior)
                    Dados[i].mvp = ii;
                if(Dados[i].pontuacao[ii] == menor)
                    Dados[i].mvpInverso = ii;
            }
        }
    }
}

void listaPartida (struct jogador Jogadores[10], struct time Times[2], struct partida Dados[50]){
    int aux,aux2;
    aux2 = Dados[0].quantPartidas;
    for (int i=0;i<aux2;i++){
        aux = Dados[i].mvp;
        printf("------------ PARTIDA %i ------------\n",i+1);
        if (Dados[i].win == 1){
            printf("------- W I N (%s) -------\n",Times[0].nomeTime);
            printf("Total de kills do time 1: %i\n",Dados[i].killTime);
            printf("Total de deaths do time 2: %i\n",Dados[i].killInimiga);
            printf("Total de torres que o time 1 levou: %i\n",Dados[i].torresAliadas);
            printf("Total de torres que o time 2 levou: %i\n",Dados[i].torresInimigo);
            printf("M V P        ID: %i ------------ %s\n",Jogadores[aux].id,Jogadores[aux].nome);
            printf("\n\n\n\n");
        }
        if (Dados[i].win == 0){
            printf("------- L O S E (%s) -------\n",Times[0].nomeTime);
            printf("Total de kills do time: %i\n",Dados[i].killTime);
            printf("Total de deaths do time: %i\n",Dados[i].killInimiga);
            printf("Total de torres que o time 1 levou: %i\n",Dados[i].torresAliadas);
            printf("Total de torres que o time 2 levou: %i\n",Dados[i].torresInimigo);
            printf("M V P        ID: %i ------------ %s\n",Jogadores[aux].id,Jogadores[aux].nome);
            printf("\n\n\n\n");
        }
    }
}

void pesquisaJogador (struct jogador Jogadores[10], struct partida Dados[50]){
    int aux=0,aux2=0;
    aux2 = Dados[0].quantPartidas;
    printf("Insira a ID do jogador: ");
    scanf("%i",&aux);
    while (aux <1 || aux > 10) {
        printf("ERROR !!!!!!!!!\nEscreva uma ID valida: ");
        scanf("%i",&aux);
    }
    aux = aux - 1;
    for (int ii=0;ii<aux2;ii++){
        printf(" ------------- P A R T I D A %i -------------\n",ii+1);
        printf("ID ---- NOME ---- IDADE ---- KILLS ---- ASSISTS ---- DEATHS \n");
        printf("%i ---- %s  ---- %i ---- %i ---- %i ---- %i\n",Jogadores[aux].id,Jogadores[aux].nome,Jogadores[aux].idade,Dados[aux2].kill[aux],Dados[aux2].assist[aux],Dados[aux2].death[aux]);
    }
}

void listaTotalKills (struct time Times[2], struct partida Dados[50]){
    int aux=0,aux2=0,totalKill=0, totalAssist=0;
    aux2= Dados[0].quantPartidas;
    for (int i =0;i<aux2;i++){
        totalKill = Dados[i].killTime + totalKill;
        totalAssist = Dados[i].assistTime + totalAssist;
    }
    printf("------------ T I M E %s:  ------------ \n",Times[0].nomeTime);
    printf("TOTAL KILLS: %i\n TOTAL ASSIST: %i\n",totalKill, totalAssist);
}

void listaMVPInverso (struct jogador Jogadores[10], struct partida Dados[50], struct time Times[2]){
    int menor=99999,soma[10],aux=0,time=0;
    for (int i=0;i<Dados[0].quantPartidas;i++){
        for (int ii=0;ii<5;ii++){
            soma[ii]=Dados[i].pontuacao[ii];
            if(soma[ii]<menor)
                menor=soma[ii];
        }
    }
    for (int i=0;i<5;i++){
        if (soma[i]==menor)
            aux = i;
    }
    printf("O MVP INVERSO: ID) %i ---- NOME) %s ---- IDADE) %i ---- ROLE) %s ---- PONTUACAO TOTAL) %i ",Jogadores[aux].id,Jogadores[aux].nome,Jogadores[aux].idade,Jogadores[aux].role,menor);
}

 void listaMVP (struct jogador Jogadores[10], struct partida Dados[50], struct time Times[2]){
    int maior=0,soma[10],aux=0,time=0;
    for (int i=0;i<Dados[0].quantPartidas;i++){
        for (int ii=0;ii<5;ii++){
            soma[ii]=Dados[i].pontuacao[ii];
            if(soma[ii]>maior)
                maior=soma[ii];
        }
    }
    for (int i=0;i<5;i++){
        if (soma[i]==maior)
            aux = i;
    }
        time = 0;
    printf("O MVP EH: ID) %i ---- NOME) %s ---- IDADE) %i ---- ROLE) %s ---- PONTUACAO TOTAL) %i ",Jogadores[aux].id,Jogadores[aux].nome,Jogadores[aux].idade,Jogadores[aux].role,maior);
}
