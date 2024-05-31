#include "contatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inicializarAgenda(Agenda *agenda) {
    agenda->numContatos = 0;
}

void adicionarContato(Agenda *agenda) {
    if (agenda->numContatos >= MAX_CONTATOS) {
        printf("Agenda cheia, impossivel adicionar mais contatos!\n");
        return;  
    }

    Contato novoContato;

    printf("Nome: ");
    if (scanf("%49s", novoContato.nome) != 1) {
        printf("Erro ao ler o nome!\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    printf("Sobrenome: ");
    if (scanf("%49s", novoContato.sobrenome) != 1) {
        printf("Erro ao ler o sobrenome!\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    printf("Email: ");
    if (scanf("%49s", novoContato.email) != 1) {
        printf("Erro ao ler o email!\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    printf("Telefone: ");
    if (scanf("%11s", novoContato.telefone) != 1) {
        printf("Erro ao ler o telefone!\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    agenda->contatos[agenda->numContatos++] = novoContato;

    printf("Contato adicionado com sucesso!\n");
    salvarAgenda(agenda);
}

void listarContatos(const Agenda *agenda) {
    printf("Listando contatos da sua agenda:\n");

    for (int i = 0; i < agenda->numContatos; i++) {
        Contato contato = agenda->contatos[i];
        printf("%s %s, %s, %s\n", contato.nome, contato.sobrenome, contato.email, contato.telefone);
    }
}

void deletarContatos(Agenda *agenda) {
    char telefone[12];
    printf("apos deletar salve para essa açao ser salva\n");
    printf("Telefone do contato para deletar: ");
    if (scanf("%11s", telefone) != 1) {
        printf("Erro ao ler o telefone!\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    int encontrado = 0;
    for (int i = 0; i < agenda->numContatos; i++) {
        if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {
            encontrado = 1;
            agenda->numContatos--;
            agenda->contatos[i] = agenda->contatos[agenda->numContatos];
            break;
        }
    }
    if (!encontrado) {
        printf("Contato nao encontrado!\n");
    } else {
        printf("Contato deletado com sucesso!\n");
    }
}

void salvarAgenda(const Agenda *agenda) {
    FILE *arquivo = fopen("agenda.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita!\n");
        return;
    }
    if (fwrite(agenda, sizeof(Agenda), 1, arquivo) != 1) {
        printf("Erro ao salvar a agenda!\n");
    } else {
        printf("Agenda salva com sucesso!\n");
    }
    fclose(arquivo);
}

void carregarAgenda(Agenda *agenda) {
    FILE *arquivo = fopen("agenda.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para leitura!\n");
        return;
    }
    if (fread(agenda, sizeof(Agenda), 1, arquivo) != 1) {
        printf("Erro ao carregar a agenda!\n");
    } else {
        printf("Agenda carregada com sucesso!\n");
    }
    fclose(arquivo);
    printf("Apos carregar salve para ser adcionado ao arquivo \'agenda.bin\'!\n");
}
