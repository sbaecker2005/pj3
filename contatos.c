#include "contatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inicializarAgenda(Agenda *agenda) { agenda->numContatos = 0; }

void adicionarContato(Agenda *agenda) {
    if (agenda->numContatos >= MAX_CONTATOS) {
        printf("Agenda cheia, impossivel adicionar mais contatos!\n");
        return;  
    }

    Contato novoContato;

    printf("Nome: ");
    scanf("%49s", novoContato.nome);
    limparBuffer();

    printf("Sobrenome: ");
    scanf("%49s", novoContato.sobrenome);
    limparBuffer();

    printf("Email: ");
    scanf("%49s", novoContato.email);
    limparBuffer();

    printf("Telefone: ");
    scanf("%11s", novoContato.telefone);
    limparBuffer();

    agenda->contatos[agenda->numContatos++] = novoContato;

    printf("Contato adicionado com sucesso!\n");
    salvarAgenda(agenda);
}

void listarContatos(const Agenda *agenda) {
    printf("Listando contatos da sua agenda:\n");

    for (int i = 0; i < agenda->numContatos; i++) {
        Contato contato = agenda->contatos[i];
        printf("%s %s, %s, %s\n", contato.nome, contato.sobrenome, contato.email,
               contato.telefone);

    }
}


void deletarContatos(Agenda *agenda) {
    char telefone[12];
    printf("apos deletar salve para essa açao ser salva\n");
    printf("Telefone do contato para deletar: ");
    scanf("%11s", telefone);
    limparBuffer();


    int encontrado = 0;
    for (int i = 0; i < agenda->numContatos; i++) {
        if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {
            encontrado = 1;
            agenda->numContatos--;
            agenda->contatos[i] = agenda->contatos[agenda->numContatos];
        }
    }
    if (!encontrado) {
        printf("Contato nao encontrado!\n");
    } else {
        printf("Contato deletado com sucesso!\n");
    }
}



void salvarAgenda(const Agenda *agenda) {
    FILE *arquivo = fopen("agenda.bin", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar a agenda!\n");
        return;
    }

    for (int i = 0; i < agenda->numContatos; i++) {
        fprintf(arquivo, "%s %s %s %s\n", agenda->contatos[i].nome,
                agenda->contatos[i].sobrenome, agenda->contatos[i].email,
                agenda->contatos[i].telefone);
    }

    fclose(arquivo);

    printf("Agenda salva com sucesso!\n");
}

void carregarAgenda(Agenda *agenda) {
    FILE *arquivo = fopen("agenda.bin", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para carregar a agenda!\n");
        return;
    }

    inicializarAgenda(agenda);
    for (;;) {
        int rc = fscanf(arquivo, "%49s %49s %49s %11s",
                        agenda->contatos[agenda->numContatos].nome,
                        agenda->contatos[agenda->numContatos].sobrenome,
                        agenda->contatos[agenda->numContatos].email,
                        agenda->contatos[agenda->numContatos].telefone);
        if (rc != 4) {
            break;
        }
        agenda->numContatos++;
        if (agenda->numContatos >= MAX_CONTATOS) {
            printf("Limite de contatos atingido durante a leitura do arquivo.\n");
            break;
        }
    }


    fclose(arquivo);

    printf("Agenda carregada com sucesso!\n");
    printf("Apos carregar salve para ser adcionado ao arquivo"
           " 'agenda.bin'!\n");
}
