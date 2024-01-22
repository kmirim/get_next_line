# get_next_line
A function that always returns the next line from a file descriptor.

<h2 align="center" #index> Index </h2>

<p align="center"> • 
  <a href="#Static_variables"> Static variables </a> •
  <a href="#memory">Memory</a> • 
  <a href="#read_function">Read()function</a> •
  <a href="#linked_list">Linked list</a>
</p><br><br>

<div id="Static_variables"/>
<h3 #Static_variables> • ♻️ Static variables </h3>

[Variáveis estáticas](https://www.geeksforgeeks.org/static-variables-in-c/) têm a propriedade de preservar seu valor mesmo depois de saírem de seu escopo! Conseqüentemente, variáveis estáticas preservam seu valor anterior no escopo anterior e não são inicializadas novamente no novo escopo.

As variáveis estáticas são úteis quando você deseja que uma variável mantenha seu valor entre chamadas de função, proporcionando persistência de dados durante toda a execução do programa. Isso pode ser útil em várias situações, como a contagem de chamadas de função, armazenamento de informações globais, etc.

Exemplo: 

```c
int ft_funcao(int count) 
{
	count = 0;
	while (count < 10) 
		count++;
	return count;
}
```

```c
int ft_funcao() {
    static int count = 0;

    if (count > 10) {
        count++;
    }

    return count;
}
```

<div id="memory"/>
<br><h3 #memory> • 🐘 Memory </h3> 

Quando falamos de memória em programação, nos referimos principalmente à RAM (Memória de Acesso Aleatório). Como mostrado no diagrama acima, a RAM é composta de diferentes áreas.

<br><img src="https://github.com/kmirim/get_next_line/assets/132582320/34494edb-c756-47c7-9e91-d553eec96dc2" />

1. **Stack (Pilha):**
    - A pilha é a memória reservada como espaço de rascunho para um thread de execução.
    - A **pilha** é gerenciada automaticamente pelo compilador e é onde a variável local é armazenada. O Stack move-se para baixo.
    - A stack é usada para armazenar dados temporários, como variáveis locais e endereços de retorno de funções.
    - Ela funciona como uma pilha real, onde os dados são empilhados e desempilhados na ordem em que são usados.
    - Na maioria dos sistemas, a stack cresce para baixo na memória. Isso significa que, à medida que você empilha mais dados, a pilha "anda" para posições de endereço menores.
2. **Heap (Monte):**
- O **heap** é gerenciado pelo programador e é onde as variáveis alocadas dinamicamente são armazenadas em um programa C. O monte move-se para
cima.
- O heap é usado para armazenar dados dinâmicos, como objetos alocados dinamicamente em tempo de execução.
- O heap cresce para cima na memória, o que significa que, à medida que você aloca mais espaço no heap, ele "anda" para posições de endereço maiores.

**A alocação de memória em C pode acontecer de duas maneiras diferentes – estaticamente ou dinamicamente:**

- Então, quando uma variável local é declarada e inicializada, ela vai para o bloco de ****************Dynamic Memory Allocation,**************** e como foi dito anteriormente, assim que a função for finalizada esse espaço de memória é liberado. Para variáveis locais, elas existem apenas dentro do bloco ou função em que foram declaradas. Uma vez que a execução do programa sai desse bloco ou função, essas variáveis são destruídas, e seu valor não é mais acessível. Tentar acessar uma variável local fora do seu escopo resultaria em um erro.
- Diferente da variável estática que é inicializada, que embora você também não possa acessar diretamente seu valor fora do escopo em que foram declaradas, elas mantêm seu valor entre as chamadas da função. Isso significa que, embora você não possa modificá-las diretamente fora do escopo, elas retêm informações ao longo do tempo de execução do programa.
    
    A variável estática em C não é alocada na heap, mas sim na **área de dados estáticos**.
    
    **Variáveis Estáticas:**
    
    - **Localização:** Alocadas na seção de dados estáticos.
    - **Vida Útil:** Existem durante toda a execução do programa.
    - **Escopo:** Limitado ao escopo em que são declaradas.
    - **Alocação:** Feita na inicialização do programa.
    - **Exemplo:** **`static int x = 10;`**
1. **Memória de dados estáticos:** 
    
    Em resumo, a memória de dados estáticos em C é usada para armazenar variáveis que mantêm seus valores entre chamadas de função e/ou durante toda a execução do programa. Isso fornece persistência de dados e um escopo controlado pelo programador.

<div id="read_function"/>
<br><h3 #read_function> • 👓 Read()function </h3>
  
**Sintaxe da função Read() em linguagem C**

Biblioteca: `<unistd.h>`

`tamanho_t lido(int fd , void *buf, tamanho_t contagem);`

- **`fd`**: O descritor de arquivo do qual você deseja ler. Pode ser um arquivo, soquete, pipe, etc.
- **`buf`**: Um ponteiro para o buffer onde os dados lidos serão armazenados.
- **`count`**: O número máximo de bytes a serem lidos.

**(Nesse projeto `count` é substituido por `BUFFER_SIZE`)**

**Descrição da função Read() em linguagem C**

Essa função é usada para ler dados de um descritor de arquivo, como um arquivo, soquete ou outro tipo de entrada/saída.

A função read() lê o conteúdo do arquivo aberto que é especificado por seu descritor no argumento de entrada “fd”. Esta função lê e copia o número de contagem de bytes no buffer apontado por buf. O identificador “fd” é um número inteiro que é retornado como resultado da função open() quando o arquivo é aberto.

Se a função read() retornar com sucesso, ela retornará o número de bytes lidos. Um resultado igual a 0 significa que o arquivo foi lido até o fim e -1 significa que ocorreu um erro.

**BUFFER_SIZE:**
(tamanho do buffer)

- **O que é um Buffer?**
    
    Em programação, um buffer é uma área de armazenamento temporário que armazena dados enquanto eles estão sendo transferidos de um lugar para outro. Em outras palavras, é como uma "caixa" temporária para armazenar informações antes de serem processadas ou utilizadas de alguma forma.
    
- **`BUFFER_SIZE`** é uma constante que define o tamanho do buffer, ou seja, quantos elementos (ou bytes) de dados podem ser armazenados temporariamente nesse buffer.
- A escolha do tamanho do buffer pode ter impacto no desempenho e na eficiência de operações de leitura e gravação de dados. Se o buffer for muito pequeno, pode ser necessário realizar operações de leitura/gravação mais frequentes, o que pode ser ineficiente. Se o buffer for muito grande, pode levar a um uso excessivo de memória.

<div id="linked_list"/>
<br><h3 #linked_list> • 🔗 Linked list </h3>

### Entendendo a definição de t_list:

```c
typedef struct
{
	char			*content; // atual
	struct t_list	*next; // próximo
} t_list;
```

- **`t_list`** é um tipo de dado definido pela estrutura **`typedef struct {...} t_list;`**.
- `t_list` possui um ponteiro para char e um ponteiro para o próximo nó da lista.

Então, **`t_list`** é o tipo de dado. Isso é muito comum em C, onde você define tipos de dados com **`struct`** e, em seguida, usa **`typedef`** para criar um nome mais conveniente (**`t_list`** neste caso).

### O que é typedef? 

`typedef` é uma palavra-chave reservada na linguagem de programação C. Ela é utilizada para criar um nome adicional (alias) para outro tipo de dados. Essa prática é frequentemente empregada para simplificar a sintaxe na declaração de estruturas de dados complexas, como é o caso de estruturas e tipos de união, exemplificado no uso de listas encadeadas.

- Normalmente os tipos de dados são sinalizados com `_t`

### O que é struct?

Estruturas são uma maneira de agrupar várias variáveis relacionadas em um só lugar. Cada variável na estrutura é conhecido como a **membro** da estrutura.

Ao contrário de um matriz, uma estrutura pode conter muitos diferentes tipos de dados (int, float, char, etc.).

Nesse caso, a nossa estrutura recebe o nome de t_list e ela guarda dois valores de tipo diferente. Um ponteiro para char *, que guarda o dado e um t_list que guarda o endereço de memória do próximo nó da lista.

<img src="https://github.com/kmirim/get_next_line/assets/132582320/655d9fe5-8be1-43f0-9522-3f5d1355859e" />
