#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

void imprimirManual();
float calcularMedia(int qtd_valores, float valores[qtd_valores]);
void getModa(int qtd_valores, float valores[qtd_valores]);
float getMediana(int qtd_valores, float valores[qtd_valores]);
float getDesvioPadrao(int qtd_valores, float valores[qtd_valores]);
float getVariancia(int qtd_valores, float valores[qtd_valores]);
int getOpFinal();
void imprimirMenu();

int main() {
    setlocale(LC_ALL, "Portuguese");

    int qtd_valores = 0;
    int op_calculo_1 = 0, flag = 0;
    float media = 0, moda = 0, mediana = 0, variancia = 0, desvio_padrao = 0;

    imprimirManual();

    imprimirMenu();
    scanf("%d", &op_calculo_1);
    fflush(stdin);

    if(op_calculo_1 < 1 || op_calculo_1 > 6) {
        while(op_calculo_1 < 1 || op_calculo_1 > 6) {
            printf("\nOp��o inv�lida. Por favor, digite novamente.\nR: ");
            scanf("%d", &op_calculo_1);
            fflush(stdin);
        }
    }

    if(op_calculo_1 == 6) {
    flag = 1;
    }

    while(flag != 1) {
        printf("\nInsira a quantidade de valores a ser usada: ");
        scanf("%d", &qtd_valores);
        fflush(stdin);

        float valores[qtd_valores];

        printf("\nInsira os valores para o c�lculo:\nOBS: Para que o valor seja confirmado, por favor, tecle ENTER.\n");
        for(int i = 0; i < qtd_valores; i++) {
            scanf("%f", &valores[i]);
            fflush(stdin);
        }

        if(op_calculo_1 == 1) {
            // M�dia
            media = calcularMedia(qtd_valores, valores);
            printf("\nM�dia aritm�tica = %.2f\n", media);
            system("pause");
            system("cls");
        }
        else if(op_calculo_1 == 2) {
            // Moda
            getModa(qtd_valores, valores);
            printf("\n");
            system("pause");
            system("cls");
        }
        else if(op_calculo_1 == 3) {
            // Mediana
            mediana = getMediana(qtd_valores, valores);
            printf("\nMediana = %.2f\n", mediana);
            system("pause");
            system("cls");
        }
        else if(op_calculo_1 == 4) {
            // Vari�ncia
            variancia = getVariancia(qtd_valores, valores);
            printf("\nVari�ncia = %.2f\n", variancia);
            system("pause");
            system("cls");
        }
        else if(op_calculo_1 == 5) {
            // Desvio padr�o
            desvio_padrao = getDesvioPadrao(qtd_valores, valores);
            printf("\nDesvio padr�o = %.2f\n", desvio_padrao);
            system("pause");
            system("cls");
        }

        imprimirMenu();
        scanf("%d", &op_calculo_1);
        fflush(stdin);

        if(op_calculo_1 < 1 || op_calculo_1 > 6) {
            while(op_calculo_1 < 1 || op_calculo_1 > 6) {
                printf("\nOp��o inv�lida. Por favor, digite novamente.\nR: ");
                scanf("%d", &op_calculo_1);
                fflush(stdin);
            }
        }

        if(op_calculo_1 == 6) {
            flag = 1;
        }
    }
}

void imprimirManual() {
    printf("Sistema simples usando os m�todos para c�lculo de m�dia, moda, mediana, vari�ncia e desvio padr�o da estat�stica descritiva.");
    printf("\n\nM�DIA: Coleta todos os valores dispon�veis, adiciona-os obtendo uma soma, que logo em seguida � divida pela quantidade de valores dispon�veis.");
    printf("\n\tExemplo: [2, 4, 7, 9]\n\t-> 2 + 4 + 7 + 9 = 22\n\t-> 22 : 4 = 5,5\n\tA m�dia desse vetor de valores � 5,5.");
    printf("\n\nMODA: Retorna o valor comum (o valor que mais se repete) em um vetor de valores.");
    printf("\n\tExemplo: [1, 7, 2, 7, 3, 0]\n\t-> A moda\" � 7 (valor que mais se repete).");
    printf("\n\tCaso existam DOIS valores mais repetidos no vetor, podemos cham�-lo de bimodal, ou seja, possui DUAS modas.");
    printf("\n\tExemplo: [2, 3, 4, 3, 2, 1]\n\t-> As modas s�o 2 e 3, que se repetem duas vezes.");
    printf("\n\tCaso n�o existam valores repetidos no vetor, podemos cham�-lo de amodal, ou seja, n�o existe moda.");
    printf("\n\nMEDIANA: Retorna o valor central de um vetor de valores colocado em ordem crescente ou decrescente.");
    printf("\n\tExemplo: [2, 7, 1, 3, 6, 4, 5]\n\t-> Ordem crescente = 1, 2, 3, 4, 5, 6, 7\n\t-> Ordem decrescente = 7, 6, 5, 4, 3, 2, 1");
    printf("\n\tA mediana deste vetor de valores � 4.");
    printf("\n\tCaso a quantidade de valores em um vetor seja par, ent�o, o retorno de valor � obtido atrav�s do c�lculo da m�dia entre os dois n�meros centrais.");
    printf("\n\tExemplo: [10, 20, 60, 30]\n\t-> Ordem crescente = 10, 20, 30, 60\n\t-> Ordem decrescente = 60, 30, 20, 10");
    printf("\n\tA mediana � igual a (20 + 30) : 2, que resulta em 25.\n");
    printf("\n\nVARI�NCIA: Retorna a m�dia dos desvios elevados ao quadrado.");
    printf("\n\tExemplo: [5, 4, 9]\n\t-> A m�dia � 6, e os desvios s�o: 6 - 5 = 1; 6 - 4 = 2; 6 - 9 = (-3)");
    printf("\n\tA vari�ncia calcula a m�dia desses valores elevados ao quadrado.\n\t-> [(1 * 1) + (2 * 2) + ((-3) * (-3))] : 3 (neste caso, a divis�o � feita por 3, pelo fato de termos tr�s valores no vetor).");
    printf("\n\tPortanto, a VARI�NCIA � igual a 14 : 3, que resulta em 4,67");
    printf("\nDESVIO PADR�O: Retorna o valor da raiz quadrada da vari�ncia.\n\tExemplo: Vari�ncia = 4, portanto o desvio padr�o � igual a 2, pois 2 � a raiz quadrada do n�mero 4.\n");
}

float calcularMedia(int qtd_valores, float valores[qtd_valores]) {
    float media = 0;

    for(int i = 0; i < qtd_valores; i++) {
        media += valores[i];
    }

    return (media / qtd_valores);
}

void getModa(int qtd_valores, float valores[qtd_valores]) {
    float aux;
    int i = 0, j = 0, n = 0, mais_reps = 0, cont = 0;
    int qtd_reps[qtd_valores];
    float bimodal[2], moda = 0;

    // Ordenar vetor em forma crescente
    for(i = 0; i < qtd_valores; i++) {
        for(j = i+1; j < qtd_valores; j++) {
            if(valores[i] > valores[j]) {
                aux = valores[j];
                valores[j] = valores[i];
                valores[i] = aux;
            }
        }
    }

    // Zerando o novo vetor.
    for(i = 0; i < qtd_valores; i++) {
        qtd_reps[i] = 0;
    }

    for(i = 0; i < qtd_valores; i++) {
        for(j = i+1; j < qtd_valores; j++) {
            if(valores[i] == valores[j]) {
                qtd_reps[i]++;
            }
        }
    }

    for(i = 0; i < qtd_valores; i++) {
        if(qtd_reps[i] > mais_reps) {
            mais_reps = qtd_reps[i];
        }
    }

    for(i = 0; i < qtd_valores; i++) {
        if(qtd_reps[i] == mais_reps) {
            cont++;
            // Se cont = 1, signigfica que s� existe 1 valor que se repete;
            // Se cont = 2, significa que existem 2 valores que se repetem;
            // Se cont > 2, significa que existem mais do que 2 valores que se repetem, ou que, nenhum valor do vetor se repete;
        }
    }

    if(cont == 1) {
        for(i = 0; i < qtd_valores; i++) {
            if(qtd_reps[i] == mais_reps) {
                moda = valores[i];
            }
        }
        printf("\nMODA = %.2f", moda);
    }
    else if(cont == 2) {
        for(i = 0; i < qtd_valores; i++) {
            if(qtd_reps[i] == mais_reps) {
                bimodal[n] = valores[i];
                n++;
            }
        }
        printf("\nMODAS = %.2f e %.2f", bimodal[0], bimodal[1]);
    }
    else {
        printf("\nVetor AMODAL, ou seja, n�o possui moda.");
    }
}

float getMediana(int qtd_valores, float valores[qtd_valores]) {
    // 1� Ordenar os valores em ordem crescente ou decrescente
    int i = 0, j = 0;
    float aux = 0;
    float mediana = 0;
    float divisao = 0;
    int n_central = 0;

    for(i = 0; i < qtd_valores; i++) {
        for(j = i+1; j < qtd_valores; j++) {
            if(valores[i] > valores[j]) {
                aux = valores[j];
                valores[j] = valores[i];
                valores[i] = aux;
            }
        }
    }

    // Quantidade de valores �mpar
    if(qtd_valores %2 != 0) {
        divisao = qtd_valores / 2;
        mediana = valores[(int)divisao];
        return mediana;
    }
    // Quantidade de valores par
    else {
        n_central = (qtd_valores / 2);
        mediana = (valores[(qtd_valores / 2)-1] + valores[n_central]) / 2;
        return mediana;
    }
}

float getVariancia(int qtd_valores, float valores[qtd_valores]) {
    float media = calcularMedia(qtd_valores, valores);
    int i;
    float desvio[qtd_valores], soma = 0, divisao;

    // Calculando o desvio dos valores
    for(i = 0; i < qtd_valores; i++) {
        desvio[i] = media - valores[i];
    }

    // Calculando a vari�ncia
    for(i = 0; i < qtd_valores; i++) {
        soma = soma + (desvio[i] * desvio[i]);
    }

    divisao = soma / qtd_valores;

    return divisao;
}

float getDesvioPadrao(int qtd_valores, float valores[qtd_valores]) {
    float variancia = getVariancia(qtd_valores, valores);

    float raiz = sqrt(variancia);

    return raiz;
}

void imprimirMenu() {
    printf("\nO que voc� quer calcular?");
    printf("\n1 - M�dia aritm�tica\n2 - Moda\n3 - Mediana\n4 - Vari�ncia\n5 - Desvio padr�o\n6 - Sair\nR: ");

}
