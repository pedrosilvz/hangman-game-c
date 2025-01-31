#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#include <locale.h>

// variáveis globais
char palavrasecreta [TAMANHO_PALAVRA];
char chutes [26];                             
int chutesDados = 0;


void abertura() {                                        
    printf("\n====================================\n");
    printf("=           JOGO DA FORCA          =\n");
    printf("=  ESCREVA AS LETRAS EM CAPS LOCK  =\n");
    printf("====================================\n\n");

}

void chuta () {             

      printf("\nQual seu chute? ");
      char chute;
      scanf( " %c", &chute);        // o espaço em " %c" é necessário quando você quer ler um char, pois ele desconsidera o ENTER   
      chutes[chutesDados] = chute;    // chutes na [posição tentativas] é igual ao chute que você deu
      chutesDados++;              

      printf("\n_____________________________\n");
      printf("\n       ÚLTIMO CHUTE: %c", chute);

        printf("\n       CHUTES DADOS:\n");
        for (int i = 0; i < chutesDados; i++) {
            printf(" %c ", chutes[i]);
      }
      
      printf("\n_____________________________\n");



      

}

int acertou () {
    for (int i = 0; i < strlen(palavrasecreta); i++) {
        if (!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }
    return 1;
}

int jachutou (char letra) {

    int achou = 0;

     for (int j = 0; j < chutesDados; j++) {          // esse loop serve para varrer se o chute na [posição 0 ou mais] é igual a [posição 0 da array palavrasecreta] e assim por diante
        if (chutes[j] == letra) {                     // se a letra que está no chutes na [posição j] for igual a igual letra que tá na palavrasecreta  [posição i] essa letra foi chutada         
            achou = 1;                               
            break;  
         }                    
      }               // conforme você vai chutando as letras, o número do componente do array chutes vai aumentando (por exemplo, se eu chutar A, a letra vai para a posição 0 no array) 

    return achou;       // devolve o resultado dentro da variável achou
}

void desenhaforca () {

    int erros = chutesErrados();
    printf("\n---------------------\n");
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%C    \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? ' ' : ' '), (erros >= 1 ? ')' : ' '));                                   // if ternário
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 5 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 6 ? '/' : ' '), (erros >= 7 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n---------------------\n");
    printf("\n");

     for (int i = 0; i < strlen(palavrasecreta); i++) {            
        
        int achou  =  jachutou(palavrasecreta[i]);      // passa a função e os parâmetros

         if (achou) {
            printf ("%c ", palavrasecreta[i]);          // Se achou for 1 (verdadeiro) imprime a letra que você chutou no lugar do underline "_"
     } else {
            printf("_ ");                              // Caso a letra que você chutou não estiver na palavra, substitui por um underline "_"
    }         
  }
    printf("\n");
}

void adcionapalavra() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    char quer;

    printf("\nVocê jogador(a), deseja adcionar uma nova palavra no jogo? (S/N): ");
    scanf(" %c", &quer);

    if (quer == 'S') {
        char novapalavra [TAMANHO_PALAVRA];
        printf("\n Qual nova palavra você deseja adcionar? ");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");      //r+ é leitura e escrita
        if (f == NULL) {
            setlocale(LC_ALL, "Portuguese_Brazil");
            printf("\nBanco de dados de palavras não disponível!\n\n");
            exit(1);
        }

        int qtd;                          // pega quantidade de palavras no arquivo
        fscanf(f, "%d", &qtd);
        qtd++;                           

        fseek(f, 0, SEEK_SET);          // Posicionou a cabeça do arquivo pro começo do arquivo    
        fprintf(f, "%d", qtd);          // Imprimiu em cima

        fseek(f, 0, SEEK_END);              // posiciona no fim do arquivo
        fprintf(f,"\n%s", novapalavra);

        fclose(f);

    }
}

void escolhepalavra() {
    // abriu o arquivo contendo as palavras
    FILE* f;                
    f = fopen("palavras.txt", "r");

    if(f == NULL) {
        setlocale(LC_ALL, "Portuguese_Brazil");
        printf("\nBanco de dados de palavras não disponível!\n\n");
        exit(1);                                                            // exit (1) termina o programa
    }
    // descobri a quantidade de palavras que tem nesse arquivo (100 palavras)
    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    // calcula um número randômico de 0 até a quantidade de palavra (0 até 99)
    srand(time(0));
    int randomico = rand() % qtddepalavras;

    // Lê até encontrar a palavra escolhida
    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%19s", palavrasecreta); // Evita estouro de buffer
    }

    fclose(f);
}

int chutesErrados () {
    int erros = 0;

    for (int i = 0; i < chutesDados; i++) {
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++) {
            if (chutes [i] == palavrasecreta[j]) {
                existe = 1;
                break;
        }
     }
     
     if (!existe) erros++;

    }

    return erros;
}

int enforcou () {
    return chutesErrados() >= 7;                  // se o erro for maior ou igual a 7, enforca
}

int main () {
    setlocale(LC_ALL, "Portuguese_Brazil");
    escolhepalavra(palavrasecreta);

    abertura();                                     // invocar a função "abertura"

    do { 

        desenhaforca();
        chuta ();                       


    } while (!acertou() && !enforcou());
     

    if (acertou()) {
        printf("\n=================================================\n");
        printf("\n--> PARABÉNS!  VOCÊ ACERTOU A PALAVRA: %s\n", palavrasecreta);
        printf("\n=================================================\n");
    } else {
        printf("\n=================================================\n");
        printf("\n--> VOCÊ FOI ENFORCADO!! TENTE NOVAMENTE!\n");
        printf("----> A PALAVRA ERA: %s\n", palavrasecreta);
        printf("\n=================================================\n");
    }
    adcionapalavra();
}   
