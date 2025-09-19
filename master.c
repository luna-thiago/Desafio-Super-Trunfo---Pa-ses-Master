#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
    float pib_per_capita;
} Carta;

// Função para exibir menu principal de atributos
void exibirMenuAtributos() {
    printf("\n=== ESCOLHA UM ATRIBUTO ===\n");
    printf("1. População\n");
    printf("2. Área (km²)\n");
    printf("3. PIB (bilhões)\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica (hab/km²)\n");
    printf("6. PIB per Capita\n");
    printf("Opção: ");
}

// Função para exibir menu dinâmico (sem o atributo já escolhido)
void exibirMenuDinamico(int atributoEscolhido) {
    printf("\n=== ESCOLHA O SEGUNDO ATRIBUTO ===\n");
    
    if (atributoEscolhido != 1) printf("1. População\n");
    if (atributoEscolhido != 2) printf("2. Área (km²)\n");
    if (atributoEscolhido != 3) printf("3. PIB (bilhões)\n");
    if (atributoEscolhido != 4) printf("4. Pontos Turísticos\n");
    if (atributoEscolhido != 5) printf("5. Densidade Demográfica (hab/km²)\n");
    if (atributoEscolhido != 6) printf("6. PIB per Capita\n");
    
    printf("Opção: ");
}

// Função para obter o nome do atributo
char* obterNomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área (km²)";
        case 3: return "PIB (bilhões)";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica (hab/km²)";
        case 6: return "PIB per Capita";
        default: return "Atributo Inválido";
    }
}

// Função para obter o valor do atributo de uma carta
float obterValorAtributo(Carta carta, int atributo) {
    switch(atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade_demografica;
        case 6: return carta.pib_per_capita;
        default: return 0.0;
    }
}

// Função para validar se o atributo é válido no menu dinâmico
int validarAtributoDinamico(int atributo, int primeiroAtributo) {
    // Verifica se é um atributo válido (1-6) e diferente do primeiro
    return (atributo >= 1 && atributo <= 6 && atributo != primeiroAtributo);
}

// Função para comparar um atributo específico (retorna 1 se carta1 vence, -1 se carta2 vence, 0 se empate)
int compararAtributo(Carta carta1, Carta carta2, int atributo) {
    float valor1 = obterValorAtributo(carta1, atributo);
    float valor2 = obterValorAtributo(carta2, atributo);
    
    // Para densidade demográfica, menor valor vence
    if (atributo == 5) {
        return (valor1 < valor2) ? 1 : (valor1 > valor2) ? -1 : 0;
    }
    // Para outros atributos, maior valor vence
    else {
        return (valor1 > valor2) ? 1 : (valor1 < valor2) ? -1 : 0;
    }
}

// Função para exibir resultado detalhado da comparação
void exibirResultado(Carta carta1, Carta carta2, int atrib1, int atrib2) {
    float valor1_atrib1 = obterValorAtributo(carta1, atrib1);
    float valor1_atrib2 = obterValorAtributo(carta1, atrib2);
    float valor2_atrib1 = obterValorAtributo(carta2, atrib1);
    float valor2_atrib2 = obterValorAtributo(carta2, atrib2);
    
    float soma1 = valor1_atrib1 + valor1_atrib2;
    float soma2 = valor2_atrib1 + valor2_atrib2;
    
    printf("\n" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" " RESULTADO DA BATALHA " "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
    printf("País 1: %s\n", carta1.nome);
    printf("País 2: %s\n", carta2.nome);
    
    printf("\nAtributos comparados:\n");
    printf("• %s\n", obterNomeAtributo(atrib1));
    printf("• %s\n", obterNomeAtributo(atrib2));
    
    printf("\n" "-" "-" "-" " VALORES DOS ATRIBUTOS " "-" "-" "-" "\n");
    printf("%-25s | %-15s | %-15s\n", "País", obterNomeAtributo(atrib1), obterNomeAtributo(atrib2));
    printf("-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "\n");
    
    if (atrib1 == 1 || atrib1 == 4) {
        printf("%-25s | %-15.0f | ", carta1.nome, valor1_atrib1);
    } else {
        printf("%-25s | %-15.2f | ", carta1.nome, valor1_atrib1);
    }
    
    if (atrib2 == 1 || atrib2 == 4) {
        printf("%-15.0f\n", valor1_atrib2);
    } else {
        printf("%-15.2f\n", valor1_atrib2);
    }
    
    if (atrib1 == 1 || atrib1 == 4) {
        printf("%-25s | %-15.0f | ", carta2.nome, valor2_atrib1);
    } else {
        printf("%-25s | %-15.2f | ", carta2.nome, valor2_atrib1);
    }
    
    if (atrib2 == 1 || atrib2 == 4) {
        printf("%-15.0f\n", valor2_atrib2);
    } else {
        printf("%-15.2f\n", valor2_atrib2);
    }
    
    printf("\n" "-" "-" "-" " COMPARAÇÃO POR ATRIBUTO " "-" "-" "-" "\n");
    
    // Comparação do primeiro atributo
    int resultado1 = compararAtributo(carta1, carta2, atrib1);
    printf("%s: ", obterNomeAtributo(atrib1));
    switch(resultado1) {
        case 1:
            printf("%s vence!\n", carta1.nome);
            break;
        case -1:
            printf("%s vence!\n", carta2.nome);
            break;
        case 0:
            printf("Empate!\n");
            break;
    }
    
    // Comparação do segundo atributo
    int resultado2 = compararAtributo(carta1, carta2, atrib2);
    printf("%s: ", obterNomeAtributo(atrib2));
    switch(resultado2) {
        case 1:
            printf("%s vence!\n", carta1.nome);
            break;
        case -1:
            printf("%s vence!\n", carta2.nome);
            break;
        case 0:
            printf("Empate!\n");
            break;
    }
    
    printf("\n" "-" "-" "-" " SOMA DOS ATRIBUTOS " "-" "-" "-" "\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);
    
    printf("\n" "★" "★" "★" " RESULTADO FINAL " "★" "★" "★" "\n");
    
    // Usar operador ternário para determinar o vencedor
    char* vencedor = (soma1 > soma2) ? carta1.nome : 
                    (soma2 > soma1) ? carta2.nome : "EMPATE";
    
    if (strcmp(vencedor, "EMPATE") == 0) {
        printf("🤝 EMPATE! Ambos os países têm a mesma soma de atributos!\n");
    } else {
        printf("🏆 VENCEDOR: %s!\n", vencedor);
        printf("Diferença: %.2f pontos\n", soma1 > soma2 ? soma1 - soma2 : soma2 - soma1);
    }
    
    printf("=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
}

int main() {
    // Cartas pré-cadastradas
    Carta paises[6] = {
        {"Brasil", 215000000, 8515767.0, 2055.0, 12, 25.3, 9574.0},
        {"França", 68000000, 643801.0, 2630.0, 15, 105.6, 38625.0},
        {"Japão", 125000000, 377975.0, 4231.0, 8, 330.8, 33854.0},
        {"Alemanha", 83000000, 357022.0, 3570.0, 10, 232.4, 43028.0},
        {"Canadá", 38000000, 9984670.0, 1644.0, 9, 3.8, 43278.0},
        {"Austrália", 26000000, 7692024.0, 1323.0, 7, 3.4, 50870.0}
    };
    
    int carta1, carta2, atrib1, atrib2;
    int opcaoValida;
    
    printf("🎮 BEM-VINDO AO SUPER TRUNFO - DESAFIO FINAL! 🎮\n");
    printf("Prepare-se para uma batalha épica entre países!\n\n");
    
    // Exibir cartas disponíveis
    printf("=== CARTAS DISPONÍVEIS ===\n");
    for (int i = 0; i < 6; i++) {
        printf("%d. %s\n", i + 1, paises[i].nome);
    }
    
    // Escolher primeira carta
    do {
        printf("\nEscolha a primeira carta (1-6): ");
        scanf("%d", &carta1);
        
        if (carta1 < 1 || carta1 > 6) {
            printf("❌ Opção inválida! Escolha entre 1 e 6.\n");
            opcaoValida = 0;
        } else {
            opcaoValida = 1;
        }
    } while (!opcaoValida);
    
    // Escolher segunda carta
    do {
        printf("Escolha a segunda carta (1-6): ");
        scanf("%d", &carta2);
        
        if (carta2 < 1 || carta2 > 6) {
            printf("❌ Opção inválida! Escolha entre 1 e 6.\n");
            opcaoValida = 0;
        } else if (carta2 == carta1) {
            printf("❌ Você não pode escolher a mesma carta duas vezes!\n");
            opcaoValida = 0;
        } else {
            opcaoValida = 1;
        }
    } while (!opcaoValida);
    
    printf("\n🥊 BATALHA: %s VS %s\n", paises[carta1-1].nome, paises[carta2-1].nome);
    
    // Escolher primeiro atributo
    do {
        exibirMenuAtributos();
        scanf("%d", &atrib1);
        
        switch(atrib1) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                opcaoValida = 1;
                printf("✅ Primeiro atributo selecionado: %s\n", obterNomeAtributo(atrib1));
                break;
            default:
                printf("❌ Opção inválida! Escolha entre 1 e 6.\n");
                opcaoValida = 0;
                break;
        }
    } while (!opcaoValida);
    
    // Escolher segundo atributo (menu dinâmico)
    do {
        exibirMenuDinamico(atrib1);
        scanf("%d", &atrib2);
        
        if (validarAtributoDinamico(atrib2, atrib1)) {
            opcaoValida = 1;
            printf("✅ Segundo atributo selecionado: %s\n", obterNomeAtributo(atrib2));
        } else if (atrib2 == atrib1) {
            printf("❌ Você não pode escolher o mesmo atributo duas vezes!\n");
            opcaoValida = 0;
        } else {
            printf("❌ Opção inválida! Escolha um atributo disponível.\n");
            opcaoValida = 0;
        }
    } while (!opcaoValida);
    
    // Exibir resultado da batalha
    exibirResultado(paises[carta1-1], paises[carta2-1], atrib1, atrib2);
    
    printf("\n🎮 Obrigado por jogar Super Trunfo! 🎮\n");
    
    return 0;
}