#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

// função para inicializar o tabuleiro
void inicializarTabuleiro(int tab[TAM][TAM]) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            tab[i][j] = AGUA;
        }
    }
}

// verifica se cabe horizontal
int podeHorizontal(int tab[TAM][TAM], int linha, int coluna) {

    if(coluna + TAM_NAVIO > TAM)
        return 0;

    for(int i = 0; i < TAM_NAVIO; i++) {
        if(tab[linha][coluna + i] != AGUA)
            return 0;
    }
    return 1;
}

// verifica se cabe vertical
int podeVertical(int tab[TAM][TAM], int linha, int coluna) {

    if(linha + TAM_NAVIO > TAM)
        return 0;

    for(int i = 0; i < TAM_NAVIO; i++) {
        if(tab[linha + i][coluna] != AGUA)
            return 0;
    }
    return 1;
}

// posiciona horizontal
void colocarHorizontal(int tab[TAM][TAM], int linha, int coluna) {
    for(int i = 0; i < TAM_NAVIO; i++) {
        tab[linha][coluna + i] = NAVIO;
    }
}

// posiciona vertical
void colocarVertical(int tab[TAM][TAM], int linha, int coluna) {
    for(int i = 0; i < TAM_NAVIO; i++) {
        tab[linha + i][coluna] = NAVIO;
    }
}

// exibir tabuleiro
void mostrarTabuleiro(int tab[TAM][TAM]) {

    printf("\nTABULEIRO:\n\n");

    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro);

    int linha, coluna;

    // --- NAVIO HORIZONTAL ---
    printf("Navio Horizontal\n");
    printf("Digite linha e coluna inicial: ");
    scanf("%d %d", &linha, &coluna);

    if(podeHorizontal(tabuleiro, linha, coluna))
        colocarHorizontal(tabuleiro, linha, coluna);
    else
        printf("Posicao invalida para o navio horizontal!\n");

    // --- NAVIO VERTICAL ---
    printf("\nNavio Vertical\n");
    printf("Digite linha e coluna inicial: ");
    scanf("%d %d", &linha, &coluna);

    if(podeVertical(tabuleiro, linha, coluna))
        colocarVertical(tabuleiro, linha, coluna);
    else
        printf("Posicao invalida para o navio vertical!\n");

    mostrarTabuleiro(tabuleiro);

    return 0;
}