# Sistema de Cadastro de Clientes em C

Projeto desenvolvido em **linguagem C** para praticar conceitos de lógica de programação, estruturas de controle, vetores, `structs` e manipulação de arquivos.

O sistema funciona no terminal e permite cadastrar, listar, pesquisar e excluir clientes. Os registros são armazenados em um arquivo binário para que possam ser recuperados em execuções posteriores.

## Funcionalidades

- **Cadastrar clientes:** registra nome e idade, com capacidade para até 100 clientes.
- **Listar clientes:** exibe os registros cadastrados.
- **Pesquisar cliente:** busca pelo nome completo, com comparação exata (diferencia maiúsculas e minúsculas).
- **Excluir cliente:** remove o primeiro registro que corresponde ao nome informado.
- **Salvar e carregar dados:** usa o arquivo local `clientes.dat` para manter os cadastros entre execuções.
- **Validar entradas:** identifica opções não numéricas no menu e solicita uma idade entre 0 e 120 anos.

## Tecnologias e conceitos

- Linguagem **C**
- Entrada e saída com `stdio.h`
- Manipulação de strings com `string.h` e `strcmp()`
- Estruturas condicionais e de repetição (`switch`, `if`, `for`, `do-while`)
- Vetores de estruturas (`struct`)
- Leitura e gravação de arquivos binários (`fread()` e `fwrite()`)

## Como executar

É necessário ter um compilador C instalado, como o **GCC**.

1. Clone o repositório ou baixe o arquivo `main.c`.
2. Abra um terminal na pasta do projeto.
3. Compile:

   ```bash
   gcc main.c -o cadastro
   ```

4. Execute:

   **Windows:**
   ```powershell
   .\cadastro.exe
   ```

   **Linux/macOS:**
   ```bash
   ./cadastro
   ```

5. Use o menu para cadastrar, listar, pesquisar ou excluir clientes. Escolha **0 - Sair** para gravar as alterações.

> O arquivo `clientes.dat` é criado no diretório de execução e será lido na próxima execução feita nesse mesmo diretório. Ele não é enviado ao GitHub.

## Exemplo do menu

```text
===============================
    SISTEMA DE CADASTRO
===============================
 1 - Cadastrar cliente
 2 - Listar clientes
 3 - Pesquisar cliente
 4 - Excluir cliente
 0 - Sair
Escolha uma opcao:
```

## Limitações atuais

- Armazena até **100 clientes**.
- A busca e a exclusão exigem correspondência exata do nome.
- Em caso de nomes repetidos, a exclusão remove apenas o primeiro registro encontrado.
- Os dados são salvos quando a opção **0 - Sair** é selecionada; um encerramento inesperado pode causar perda de alterações recentes.
- O formato binário do arquivo pode não ser compatível entre diferentes compiladores ou plataformas.

## Objetivo

Este é um projeto de estudo criado para consolidar conhecimentos em **linguagem C** e praticar o desenvolvimento de uma aplicação de terminal, desde a entrada de dados até sua persistência em arquivo.
