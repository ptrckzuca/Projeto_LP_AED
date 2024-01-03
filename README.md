# Projeto_LP_AED
Alunos: Patrick Silva;
        Frederico Soliz;
        João Nunes.

Funcionalidades implementadas:
//Primeira Fase

char **create_matrix(int rows, int cols);  (REQ. 1)
void free_matrix(char** matrix, int rows);   (REQ. 1)
void passufp6(char* str);  (REC. 2)
void insert_random_word(char **matrix, int rows, int row, int cols);  (REQ. 2)
void insert_random_words(char **matrix, int rows, int cols);  (REQ. 2)
void insert_word(char **matrix, int rows, int row, const char *word, int cols);  (REQ. 2)
void insert_word(char **matrix, int rows, int row, const char *word, int cols);  (REQ. 2)
int remove_word(char **matrix, int rows, int cols, char *word);  (REQ. 2)
char generate_random_char();  (REQ. 3)
void list_words(char **matrix, int rows, int cols);  (REQ. 3)
int compare_word_sets(char **matrix1, int rows1, int cols1, char **matrix2, int rows2, int cols2);  (REQ. 4)
int search(char** matrix, int rows, char* word);  (REQ. 5)
void sort_size(char **matrix, int rows);  (REQ. 6)
void sort_alphabetical(char **matrix, int rows, int cols);  (REQ. 6)

 
//Segunda Fase

.struct WORDS_HOLDER *create_words_holder(int rows, int cols);  (REQ. 7)
.AD_WORDS_HOLDER *create_ad_words_holder(int size);  (REQ. 8.a)
.void free_words_holder(struct WORDS_HOLDER* wordsHolder);  (REQ. 8.a)
.void resizeArray(AD_WORDS_HOLDER *arr, int newSize);  (REQ. 8.b)
.void insertElement(AD_WORDS_HOLDER *arr, VAL_AD_WORDS_HOLDER newElement); (REQ. 8.b)
.void insertElementAt(AD_WORDS_HOLDER *arr, VAL_AD_WORDS_HOLDER newElement, int index); (REQ. 8.c)
.void deleteElementAt(AD_WORDS_HOLDER *arr, int index); (REQ. 8.d)
int search(char** matrix, int rows, char* word);  (REQ. 8.e)
.void printarray(AD_WORDS_HOLDER *arr);


//Ponto 10 e 11 

.void writeToFile(const char* filename, struct WORDS_HOLDER* wordsHolder);  (REQ. 10)
.struct WORDS_HOLDER* readFromFile(const char* filename);  (REQ. 10)
.void writeBinFile(const char* filename, struct WORDS_HOLDER* wordsHolder);  (REQ. 11)
.struct WORDS_HOLDER* readBinFile(const char* filename);  (REQ. 11)

 
Funcionalidades parcialmente implementadas:

//PONTO 9: Listas ligadas.
.O grupo fez a implementação parcial das listas ligadas no projeto anexado. Porém, o grupo apresentou dificuldades em implentar funções de teste cliente.
