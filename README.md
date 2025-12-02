# 🚢 Batalha Naval — Implementação em C

Trabalho desenvolvido pelo aluno **Claudemir Adriano de Albuquerque Silva**  
Disciplina: **Programação de Inovação e Fundamentos de Sistemas de Informação (PIFSI 2025.2)**  
Instituição: **CESAR School**  
Orientador: **Prof. João Victor Tinoco**  
E-mail: **caas@cesar.school**

---

## 📘 Sobre o Projeto

Este repositório apresenta uma implementação própria do jogo **Batalha Naval** utilizando a linguagem **C**, executada exclusivamente via **terminal**.  
O desenvolvimento teve como objetivo reforçar conhecimentos fundamentais de programação estruturada, modularização, alocação dinâmica e boas práticas de organização de código.


---

## 🔧 Funcionalidades Desenvolvidas

- **Menu principal completo**, permitindo iniciar partidas, configurar opções e sair do jogo.  
- **Tamanhos de tabuleiro configuráveis**, de **6×6** até **26×26** (padrão: **10×10**).  
- Sistema de posicionamento **manual ou automático** da frota.  
- Exibição de **estatísticas finais**, como precisão, total de jogadas e visualização dos tabuleiros ao fim da partida.

---

## 👤 Equipe de Desenvolvimento

| Aluno | Email | Responsabilidades |
|-------|--------|------------------|
| **Claudemir Adriano de Albuquerque Silva** | **caas@cesar.school** | • Organização geral do projeto<br>• Sistema de menus e configurações<br>• Implementação da lógica principal da partida (`game`)<br>• Rotinas de ataques, validação e verificação de vitória<br>• Criação e gerenciamento dos tabuleiros e frotas (`board`, `fleet`)<br>• Sistema de entrada, tratamento de erros e parsing (`io`)<br>• Módulo de geração aleatória (`rnd`)<br>• Gestão completa da memória<br>• Testes, documentação e revisão final |

**Todo o desenvolvimento foi realizado integralmente pelo autor.**

---

## 🛠 Tecnologias Utilizadas

- **C** (padrão **C99**)  
- **GCC**  
- **Makefile**  
- Bibliotecas padrão:  
  `stdio.h`, `stdlib.h`, `string.h`, `ctype.h`, `time.h`

---

## 🚀 Como Compilar e Executar

O projeto já inclui um `Makefile`.

### 1. Acesse o diretório do projeto
Certifique-se de estar na pasta principal (onde está o `Makefile`).

### 2. Compile e execute com:


Após a compilação, o jogo será iniciado automaticamente.

---

## 🎮 Funcionamento do Jogo

### Menu Principal
- Iniciar nova partida  
- Ajustar configurações (tamanho do tabuleiro e modo de posicionamento)  
- Sair

### Configuração Inicial
- Escolha dos apelidos dos dois jogadores  
- Posicionamento **Manual (M)** ou **Automático (A)**

### Durante o Jogo
- Turnos alternados  
- Jogadas usando coordenadas do tipo `B5`, `H2`, etc.  
- Respostas possíveis: **Água**, **Acerto**, **Navio destruído**

### Encerramento
- Vitória quando toda a frota inimiga for destruída  
- Exibição de estatísticas detalhadas  
- Mostra final dos tabuleiros

---

## 🧩 Arquitetura do Código

O projeto foi dividido em módulos para manter organização e facilitar manutenção:

### Estrutura Modular
- `board` → criação e gerenciamento do tabuleiro  
- `fleet` → controle dos navios e posicionamento  
- `game` → fluxo principal e regras do jogo  
- `io` → entrada, saída e validação  
- `rnd` → geração de números aleatórios  

### Memória Dinâmica
- Uso de `malloc` para criar tabuleiros e frotas no tamanho escolhido  
- Liberação completa da memória ao final da execução  

### Uso de Structs e Ponteiros
- Estruturas `Player` e `Game` organizam os dados da partida  
- Ponteiros reduzem cópias desnecessárias e aumentam eficiência  

### Entrada e Saída Centralizadas
- O módulo `io` concentra toda a leitura e validação de dados digitados  
- Isso deixa a lógica do jogo mais clara e separada


---
