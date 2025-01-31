<div>
  <h1 style="display: inline-block; margin-right: 10px;">
    Hangman Game in C language 🚩
  </h1>
  <img
    align="middle"
    alt="C"
    title="C"
    width="50px"
    src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg" 
  />
</div>



###  - A "Hangman game" created with C language in Visual Studio Code. Try to change the language of the programm if you want to! The default language in the project is Brazilian Portuguese (you can also delete **`#include <locale.h>`** e **`setlocale(LC_ALL, "Portuguese_Brazil")`** if you not using portuguese words in the project. 

###  - This project was made by me as a activity in **`Alura curso C: avançando na linguagem.`**

<br>

---

## Tradução ✈
###  - Um clássico jogo da forca criado com a linguagem de programação C. 
###  - Esse projeto foi realizado por mim como uma atividade da  **`Alura curso C: avançando na linguagem.`** 
###  - As partes: **`#include <locale.h>`** e **`setlocale(LC_ALL, "Portuguese_Brazil");`** são usadas para deixar as letras e palavras do português de forma correta e coesa no terminal da sua IDE (Caso você programe em C/C++ no Visual Studio Code, pode ser que mesmo colocando os códigos acima, o seu código ainda fique com as palavras e letras diferentes no terminal. Para resolver isso siga os seguintes passos:

- Abra o seu **`arquivo.c`**;
- Inclua os códigos:

```c
#include <stdio.h>
#include <locale.h>

// coloque em qualquer função que desejar para traduzir o conteúdo dos "printf" 
setlocale(LC_ALL, "Portuguese_Brazil");

    
```
  
- Copie seu código contendo as palavras normalmente em português;
- Na barra inferior do Visual Studio Code, selecione UTF-8 (Selecionar codificação) e clique em **`Reabrir com codificação`**;
- Pesquise por **`Western (ISO 8859-1)`** e selecione-a;
- Cole seu código original e prontinho! 🤙🏼
