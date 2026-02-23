#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

// inicializa
void inicializarTabuleiro(int tab[TAM][TAM]) {
    for(int i = 0; i < TAM; i++)
        for(int j = 0; j < TAM; j++)
            tab[i][j] = AGUA;
}

// -------- HORIZONTAL --------
int podeHorizontal(int tab[TAM][TAM], int linha, int coluna) {

    if(coluna + TAM_NAVIO > TAM)
        return 0;

    for(int i = 0; i < TAM_NAVIO; i++)
        if(tab[linha][coluna + i] != AGUA)
            return 0;

    return 1;
}

void colocarHorizontal(int tab[TAM][TAM], int linha, int coluna) {
    for(int i = 0; i < TAM_NAVIO; i++)
        tab[linha][coluna + i] = NAVIO;
}

// -------- VERTICAL --------
int podeVertical(int tab[TAM][TAM], int linha, int coluna) {

    if(linha + TAM_NAVIO > TAM)
        return 0;

    for(int i = 0; i < TAM_NAVIO; i++)
        if(tab[linha + i][coluna] != AGUA)
            return 0;

    return 1;
}

void colocarVertical(int tab[TAM][TAM], int linha, int coluna) {
    for(int i = 0; i < TAM_NAVIO; i++)
        tab[linha + i][coluna] = NAVIO;
}

// -------- DIAGONAL DESCENDO (↘) --------
int podeDiagonalDesc(int tab[TAM][TAM], int linha, int coluna) {

    if(linha + TAM_NAVIO > TAM || coluna + TAM_NAVIO > TAM)
        return 0;

    for(int i = 0; i < TAM_NAVIO; i++)
        if(tab[linha + i][coluna + i] != AGUA)
            return 0;

    return 1;
}

void colocarDiagonalDesc(int tab[TAM][TAM], int linha, int coluna) {
    for(int i = 0; i < TAM_NAVIO; i++)
        tab[linha + i][coluna + i] = NAVIO;
}

// -------- DIAGONAL SUBINDO (↗) --------
int podeDiagonalSub(int tab[TAM][TAM], int linha, int coluna) {

    if(linha - (TAM_NAVIO-1) < 0 || coluna + TAM_NAVIO > TAM)
        return 0;

    for(int i = 0; i < TAM_NAVIO; i++)
        if(tab[linha - i][coluna + i] != AGUA)
            return 0;

    return 1;
}

void colocarDiagonalSub(int tab[TAM][TAM], int linha, int coluna) {
    for(int i = 0; i < TAM_NAVIO; i++)
        tab[linha - i][coluna + i] = NAVIO;
}

// mostrar
void mostrarTabuleiro(int tab[TAM][TAM]) {

    printf("\nTABULEIRO:\n\n");

    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }
}

int main() {

    int tabuleiro[TAM][TAM];
    int linha, coluna;

    inicializarTabuleiro(tabuleiro);

    // NAVIO 1 - HORIZONTAL
    printf("Navio Horizontal (linha coluna): ");
    scanf("%d %d", &linha, &coluna);

    if(podeHorizontal(tabuleiro, linha, coluna))
        colocarHorizontal(tabuleiro, linha, coluna);
    else
        printf("Posicao invalida!\n");

    // NAVIO 2 - VERTICAL
    printf("Navio Vertical (linha coluna): ");
    scanf("%d %d", &linha, &coluna);

    if(podeVertical(tabuleiro, linha, coluna))
        colocarVertical(tabuleiro, linha, coluna);
    else
        printf("Posicao invalida!\n");

    // NAVIO 3 - DIAGONAL DESCENDO
    printf("Navio Diagonal Descendo ↘ (linha coluna): ");
    scanf("%d %d", &linha, &coluna);

    if(podeDiagonalDesc(tabuleiro, linha, coluna))
        colocarDiagonalDesc(tabuleiro, linha, coluna);
    else
        printf("Posicao invalida!\n");

    // NAVIO 4 - DIAGONAL SUBINDO
    printf("Navio Diagonal Subindo ↗ (linha coluna): ");
    scanf("%d %d", &linha, &coluna);

    if(podeDiagonalSub(tabuleiro, linha, coluna))
        colocarDiagonalSub(tabuleiro, linha, coluna);
    else
        printf("Posicao invalida!\n");

    mostrarTabuleiro(tabuleiro);

    return 0;
}