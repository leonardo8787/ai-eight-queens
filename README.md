# Autores

 - Leonardo Campos CEFET-MG
 - Pedro Rodrigues CEFET-MG

# Algoritmos das 8 rainhas

O problema das Oito Rainhas também pode ser resolvido usando algoritmos genéticos. Algoritmos genéticos são uma classe de algoritmos de otimização que se baseiam nos processos de seleção natural e reprodução na evolução biológica. No caso das Oito Rainhas, o algoritmo genético começa com uma população inicial de possíveis soluções, chamadas de indivíduos. Cada indivíduo é uma disposição diferente das rainhas no tabuleiro de xadrez. A população inicial é criada aleatoriamente ou com alguma heurística. 

Em seguida, o algoritmo avalia o desempenho de cada indivíduo, dando uma pontuação com base em quantas rainhas estão em posições que não atacam outras rainhas. Essa pontuação é chamada de aptidão ou fitness. Indivíduos com aptidão maior são mais propensos a sobreviver e se reproduzir. A reprodução é simulada por meio de operadores genéticos, como a recombinação e a mutação. A recombinação envolve a troca de material genético entre dois indivíduos, enquanto a mutação envolve a modificação aleatória de um indivíduo. Esses operadores genéticos geram novos indivíduos, que são adicionados à população para a próxima geração.

O processo de avaliação, seleção, reprodução e criação de uma nova população é repetido por várias gerações até que uma solução viável seja encontrada ou um critério de parada seja alcançado (por exemplo, número máximo de gerações). Os algoritmos genéticos são úteis em problemas de otimização onde há muitas soluções possíveis e a busca exaustiva não é prática. Eles podem encontrar soluções viáveis em um espaço de busca muito grande, mas também podem ficar presos em mínimos locais ou falsos positivos se não forem cuidadosamente ajustados e avaliados.

## Organização 

Nosso algoritmo está dividido em três objetos diferentes, os quais são: chess-board, genetic-algorithm e utils. Chess-board é o objeto que trata sobre o preenchimento do tabuleiro de xadrex, o genetic-algoritm trata sobre as funcionalidades do algoritmo genético, como crossovers, gerações e etc. Já o utils trata sobre o método aleatório de escolha de pais para crossover.

## Técnica usada para resolução

Neste algoritmo genético seguimos o seguinte pseudo-código:

![Imagem do WhatsApp de 2023-05-11 à(s) 01 35 47](https://github.com/pedro-rodrigues18/ai-eight-queens-puzzle/assets/78708394/a67b69a2-5d3e-402b-9bb4-801ad42f4356)

### 1° etapa - população

A nossa população é gerada de maneira aleatória com 8 indivíduos, cada indivíduo possui um vector<int> representando a posição onde a rainha se encontra na distribuição do tabuleiro de xadrex. O indivíduo também possui um parâmetro FITNESS, que representa o número de conflitos existentes no tabuleiro de xadrex. 

### 2° etapa - fitness function
  
Esta função é usada para retornar o número de conflitos presentes no tabuleiro para cada indivíduo. 

### 3° etapa - Seleção
  
Nesta etapa foi implementado uma distribuição de probabilidades com resultado dos valores fitness de cada endivíduo. Faz-se necessário para selecionar os melhores indivíduos para o cruzamento(crossover). Por padrão é priorizado indivíduos com menor número de conflitos. A função de seleção retornará o índice dos indivíduos que serão os pais.
  
### 4° etapa - Reprodução(Crossover)
  
Nesta etapa é realizado o cruzamento dos pais e é gerado um novo indivíduo filho. O cruzamento se dá selecionando a primeira metade do primeiro pai com a segunda metade do segundo pai. 
  
### 5° etapa - Mutação 
  
A mutação é feita de forma aleatória, escolhendo um cromossomo para ser mutado, onde sua mutação tem valor aleatório.

### Resultado 
 
![resultado](https://github.com/pedro-rodrigues18/ai-eight-queens-puzzle/assets/78708394/59072799-1858-4b89-add3-c1a24a83c195)
  
Essas iterações são feitas até que se chegue em um resultado ótimo ou próximo ao ótimo.

# Referências 
  
 - Russell, Stuart J. (Stuart Jonathan), 1962 - Inteligência artificial / Stuart Russell, Peter Norvig; tradução Regina Célia Simille. – Rio de Janeiro: Elsevier, 2013.
 

