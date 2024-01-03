//
// Created by frede on 22/12/2023.
//

#ifndef TESTESPROJETOLP_FUNCOES_H
#define TESTESPROJETOLP_FUNCOES_H
// armazena palavras e combinações
struct WORDS_HOLDER {
    char **words1;
    char **words1_ufp6;
    char lastUpdate[20];
    int rows;
    int cols;
};
//para função de combinaçoes
struct combination {
    char *word1;
    char *word2;
    int index1;
    int index2;
};

// armazena elementos do array dinâmico
typedef struct {
    struct WORDS_HOLDER data;
} VAL_AD_WORDS_HOLDER;


//  armazena o array dinâmico
typedef struct {
    int size;    // tamanho do array
    int count;   // nº de elementos ocupados
    VAL_AD_WORDS_HOLDER *array; // apontador para o primeiro elemento
} AD_WORDS_HOLDER;

struct NODE_LL_WORDS_HOLDER{
    struct WORDS_HOLDER *holder;
    char *date;
    struct NODE_LL_WORDS_HOLDER *next;
    struct NODE_LL_WORDS_HOLDER *prev;
};

struct LL_WORDS_HOLDER{
    struct NODE_LL_WORDS_HOLDER *first;
    int used;
};





void clientmatrix();
void clientsortmatrix();
void clientcomparematrix();
void clientsearchmatrix();
void clientremovematrix();
void clientrandommatrix();
void clientfiles();
void clientbinfiles();

//PRIMEIRA FASE
void passufp6(char* str);
char generate_random_char();
void free_matrix(char** matrix, int rows);
void free_words_holder(struct WORDS_HOLDER* wordsHolder);
char **create_matrix(int rows, int cols);
void insert_random_word(char **matrix, int rows, int row, int cols);
void insert_random_words(char **matrix, int rows, int cols);
void list_words(char **matrix, int rows, int cols);
void insert_word(char **matrix, int rows, int row, const char *word, int cols);
int remove_word(char **matrix, int rows, int cols, char *word);
int search(char** matrix, int rows, char* word);
void sort_size(char **matrix, int rows);
void sort_alphabetical(char **matrix, int rows, int cols);
int compare_word_sets(char **matrix1, int rows1, int cols1, char **matrix2, int rows2, int cols2);


//SEGUNDA FASE
AD_WORDS_HOLDER *create_ad_words_holder(int size);
struct WORDS_HOLDER *create_words_holder(int rows, int cols);
void resizeArray(AD_WORDS_HOLDER *arr, int newSize);
void insertElement(AD_WORDS_HOLDER *arr, VAL_AD_WORDS_HOLDER newElement);
void insertElementAt(AD_WORDS_HOLDER *arr, VAL_AD_WORDS_HOLDER newElement, int index);
void deleteElementAt(AD_WORDS_HOLDER *arr, int index);
void printarray(AD_WORDS_HOLDER *arr);



struct LL_WORDS_HOLDER *create_ll_words_holder();
void remove_ll_words_holder_at(struct LL_WORDS_HOLDER *ll_words_holder, int index);
void pesquisa_ll_words_holder(struct LL_WORDS_HOLDER *ll_words_holder, char *word);

//FICHEIROS
void writeToFile(const char* filename, struct WORDS_HOLDER* wordsHolder);
struct WORDS_HOLDER* readFromFile(const char* filename);
void writeBinFile(const char* filename, struct WORDS_HOLDER* wordsHolder);
struct WORDS_HOLDER* readBinFile(const char* filename);

#endif //TESTESPROJETOLP_FUNCOES_H
