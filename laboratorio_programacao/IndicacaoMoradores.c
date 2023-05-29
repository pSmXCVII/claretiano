#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MORADORES 100

typedef struct {
    char nome[50];
    int anosResidencia;
    int idade;
} Morador;

void limparConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void exibirMoradores(Morador moradores[], int numMoradores) {
    int i;

    printf("\n============ Moradores Cadastrados ============\n");
    printf("%-20s %-20s %-20s\n", "Nome", "Anos Resid.", "Idade");
    printf("-----------------------------------------------\n");

    for (i = 0; i < numMoradores; i++) {
        printf("%-20s %-20d %-20d\n", moradores[i].nome, moradores[i].anosResidencia, moradores[i].idade);
    }

    printf("-----------------------------------------------\n");
}

int main() {
    Morador moradores[MAX_MORADORES];
    int numMoradores = 0;
    int opcao;

    printf("=== Programa de Indicação de Moradores ===\n");

    do {
        printf("\nDigite o nome do morador: ");
        scanf("%s", moradores[numMoradores].nome);

        printf("Digite o tempo de residência (em anos): ");
        scanf("%d", &moradores[numMoradores].anosResidencia);

        printf("Digite a idade atual do morador: ");
        scanf("%d", &moradores[numMoradores].idade);

        limparConsole();

        exibirMoradores(moradores, numMoradores + 1);

        printf("\nDeseja adicionar mais um morador?\n");
        printf("1 - Sim\n");
        printf("2 - Não (Finalizar)\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        while (opcao != 1 && opcao != 2) {
            printf("Opção inválida. Digite novamente: ");
            scanf("%d", &opcao);
        }
        limparConsole();
        if (opcao == 1) {
            exibirMoradores(moradores, numMoradores + 1);
        }
        numMoradores++;
    } while (opcao == 1 && numMoradores < MAX_MORADORES);

    printf("\n=== Relatório ===\n");

    if (numMoradores > 0) {
        int i;
        int maiorIdadeIndex = 0;
        int maiorTempoIndex = 0;
        int somaIdades = 0;

        for (i = 1; i < numMoradores; i++) {
            if (moradores[i].idade > moradores[maiorIdadeIndex].idade) {
                maiorIdadeIndex = i;
            }

            if (moradores[i].anosResidencia > moradores[maiorTempoIndex].anosResidencia) {
                maiorTempoIndex = i;
            }

            somaIdades += moradores[i].idade;
        }

        printf("Morador com maior idade: %s (idade: %d)\n", moradores[maiorIdadeIndex].nome, moradores[maiorIdadeIndex].idade);
        printf("Morador que reside a mais tempo no apartamento: %s (anos de residência: %d)\n", moradores[maiorTempoIndex].nome, moradores[maiorTempoIndex].anosResidencia);

        if (numMoradores > 1) {
            float mediaIdades = (float)somaIdades / (numMoradores - 1);
            printf("Média geral de idade dos moradores: %.2f\n", mediaIdades);
        }
        printf("Quantidade geral de moradores cadastrados: %d\n", numMoradores);
        
        exibirMoradores(moradores, numMoradores);
    } else {
        printf("Nenhum morador cadastrado.\n");
    }

    return 0;
}