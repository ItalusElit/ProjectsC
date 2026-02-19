#include <stdio.h>
#include <string.h>

// aqui eu criei a struct pra não ter que criar um monte de array separado
// conteúdo visto em aula pra organizar melhor os dados
typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

int main() {
    Produto estoque[100]; // por enquanto cabe 100 coisas 
    int qtd_total = 0;
    int escolha = 0;

    printf("=== BEM-VINDO AO MEU PROGRAMA DE ESTOQUE ===\n");
    printf("Feito por: Italo Gabriel\n");

    while(escolha != 3) {
        printf("\nO que voce quer fazer agora?\n");
        printf("1 - Cadastrar algo novo\n");
        printf("2 - Ver o que tem no estoque\n");
        printf("3 - Fechar o programa\n");
        printf("Opcao: ");
        scanf("%d", &escolha);
        getchar(); // Limpando o buffer pro fgets nao pular a leitura do nome

        if (escolha == 1) {
            // Se o estoque estiver cheio ele avisa
            if (qtd_total >= 100) {
                printf("Vixi, o estoque ja esta lotado!\n");
            } else {
                printf("\n--- Cadastrando Produto ---\n");
                estoque[qtd_total].codigo = qtd_total + 1;

                printf("Nome do item: ");
                fgets(estoque[qtd_total].nome, 50, stdin);
                // Tirando aquele \n chato que o fgets coloca no final
                estoque[qtd_total].nome[strcspn(estoque[qtd_total].nome, "\n")] = 0;

                printf("Quanto tem no estoque?: ");
                scanf("%d", &estoque[qtd_total].quantidade);

                printf("Qual o preco unitario?: ");
                scanf("%f", &estoque[qtd_total].preco);

                qtd_total++;
                printf("Beleza! Produto salvo com sucesso.\n");
            }
        } 
        else if (escolha == 2) {
            if (qtd_total == 0) {
                printf("\nAinda nao tem nada cadastrado...\n");
            } else {
                printf("\n--- Listando Tudo ---\n");
                for (int i = 0; i < qtd_total; i++) {
                    printf("[%d] Item: %-15s | Qtd: %-3d | Preco: R$%.2f\n", 
                            estoque[i].codigo, estoque[i].nome, 
                            estoque[i].quantidade, estoque[i].preco);
                }
            }
        }
    }

    printf("\nTchauuU! Saindo do sistema...\n");
    return 0;
}