#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para inicializar o tabuleiro com zeros (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Função para verificar se o navio pode ser posicionado horizontalmente
int podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Fora dos limites

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != VALOR_AGUA) return 0; // Já ocupado
    }

    return 1;
}

// Função para verificar se o navio pode ser posicionado verticalmente
int podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Fora dos limites

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != VALOR_AGUA) return 0; // Já ocupado
    }

    return 1;
}

// Função para posicionar navio horizontalmente
void posicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = VALOR_NAVIO;
    }
}

// Função para posicionar navio verticalmente
void posicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = VALOR_NAVIO;
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos navios (definidas diretamente no código)
    int linha_horizontal = 2, coluna_horizontal = 4;
    int linha_vertical = 5, coluna_vertical = 1;

    // Verificação e posicionamento do navio horizontal
    if (podePosicionarHorizontal(tabuleiro, linha_horizontal, coluna_horizontal)) {
        posicionarHorizontal(tabuleiro, linha_horizontal, coluna_horizontal);
    } else {
        printf("Erro: não foi possível posicionar o navio horizontal.\n");
        return 1;
    }

    // Verificação e posicionamento do navio vertical
    if (podePosicionarVertical(tabuleiro, linha_vertical, coluna_vertical)) {
        posicionarVertical(tabuleiro, linha_vertical, coluna_vertical);
    } else {
        printf("Erro: não foi possível posicionar o navio vertical.\n");
        return 1;
    }

    // Exibe o tabuleiro final com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
    #include <stdio.h>

#define TAM 10          // Tamanho do tabuleiro
#define NAVIO 3         // Valor representando parte do navio
#define AGUA 0          // Valor representando água
#define TAM_NAVIO 3     // Tamanho fixo dos navios

// Função para verificar se o espaço está livre para o navio
int pode_colocar(int tabuleiro[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + dx * i;
        int y = coluna + dy * i;

        // Verifica se está fora do tabuleiro
        if (x < 0 || x >= TAM || y < 0 || y >= TAM)
            return 0;

        // Verifica se já tem navio
        if (tabuleiro[x][y] != AGUA)
            return 0;
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void colocar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + dx * i;
        int y = coluna + dy * i;
        tabuleiro[x][y] = NAVIO;
    }
}

// Função para imprimir o tabuleiro no console
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa todas as posições com 0 (água)

    // Posiciona 1 navio horizontal (direita)
    if (pode_colocar(tabuleiro, 2, 1, 0, 1)) {
        colocar_navio(tabuleiro, 2, 1, 0, 1);
    }

    // Posiciona 1 navio vertical (baixo)
    if (pode_colocar(tabuleiro, 5, 5, 1, 0)) {
        colocar_navio(tabuleiro, 5, 5, 1, 0);
    }

    // Posiciona 1 navio diagonal (principal: linha++, coluna++)
    if (pode_colocar(tabuleiro, 0, 0, 1, 1)) {
        colocar_navio(tabuleiro, 0, 0, 1, 1);
    }

    // Posiciona 1 navio diagonal (secundária: linha++, coluna--)
    if (pode_colocar(tabuleiro, 0, 9, 1, -1)) {
        colocar_navio(tabuleiro, 0, 9, 1, -1);
    }

    // Exibe o tabuleiro
    exibir_tabuleiro(tabuleiro);

    return 0;
}