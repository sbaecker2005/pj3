#ifndef TAREFAS_H
#define TAREFAS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 255
#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_TELEFONE 12

typedef struct {
  char nome[MAX_NOME];
  char sobrenome[MAX_NOME];
  char email[MAX_EMAIL];
  char telefone[MAX_TELEFONE];
} Contato;

typedef struct {
  Contato contatos[MAX_CONTATOS];
  int numContatos;
} Agenda;

void limparBuffer();
void inicializarAgenda(Agenda *agenda);
void adicionarContato(Agenda *agenda);
void listarContatos(const Agenda *agenda);
void deletarContatos(Agenda *agenda);
void salvarAgenda(const Agenda *agenda);
void carregarAgenda(Agenda *agenda);

#endif

