#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ufp6.h"
void passufp6(char* str){
    char* str1 = ufp6(str);
    puts(str1);
    free(str1);
}
char generate_random_char() {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int index = rand() % (sizeof(charset) - 1);
    return charset[index];
}

void free_matrix(char** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);  // faz free linha a linha da matriz
    }
    free(matrix);  // faz free do array de apontadores
}
void free_words_holder(struct WORDS_HOLDER* wordsHolder) {
    free_matrix(wordsHolder->words1, wordsHolder->rows);
    free_matrix(wordsHolder->words1_ufp6, wordsHolder->rows);
    free(wordsHolder);
}

void printarray(AD_WORDS_HOLDER *arr){
    for (int i = 0; i < arr->count; i++){
        printf("%s\n", arr->array[i].data.words1);
        printf("%s\n", arr->array[i].data.words1_ufp6);
        printf("%s\n", arr->array[i].data.lastUpdate);
    }
}

char **create_matrix(int rows, int cols){
    char **matrix = (char **) calloc(rows, sizeof(char *));
    if (matrix == NULL){
        return NULL;
    }
    for (int i = 0; i < rows; i++){
        matrix[i] = (char *) calloc(cols, sizeof(char));
        if (matrix[i] == NULL){
            return NULL;
        }
    }
    return matrix;
}

void list_words(char **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols && matrix[i][j] != '\0'; j++) {
            printf("%c", matrix[i][j]);
        }
    printf(" UFP6:");
        passufp6(matrix[i]);
        printf("\n");
        }
}

void insert_random_word(char **matrix, int rows, int row, int cols) { //insere palavra aleatória na matriz

    srand((unsigned int) time(NULL) + row); // adiciona 'row', torna  a semente única para cada linha

    char word[cols];
    for (int i = 0; i < cols - 1; i++) {
        word[i] = generate_random_char();
    }
    word[cols - 1] = '\0';

    insert_word(matrix, rows, row, word, cols);
}

void insert_random_words(char **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        insert_random_word(matrix, rows, i, cols);
    }
}


void insert_word(char **matrix, int rows, int row, const char *word, int cols){
    // ve o comprimento da palavra
    int word_length = strlen(word);

    // ve se a linha e valida
    if (row < 0 || row >= rows){
        printf("error\n");
        return;
    }

    // mete a palavra na linha especificada
    for (int i = 0; i < word_length; i++){
        if (i < cols - 1){
            matrix[row][i] = word[i];
        } else {
            break;
        }
    }
    // /0 para marcar fim da string
    matrix[row][word_length] = '\0';
}

int remove_word(char **matrix, int rows, int cols, char *word) {
    for (int i = 0; i < rows; i++) {
        if (strcmp(matrix[i], word) == 0) {
            memset(matrix[i], 0, cols); // preenche o array a 0 caso strcmp retorne 0
            return 1;
        }
    }
    return 0;
}

int search(char** matrix, int rows, char* word){
    int count = 0;
    for (int i = 0; i < rows; i++){
        if (strstr(matrix[i], word) != NULL){ //pesquisa word na linha i da matriz e retorna valor se encontrar
            count++;
        }
    }
    printf("number of found words: %d\n", count);
    printf("UFP6: ");
    passufp6(word);
    return 0;
}

void sort_size(char **matrix, int rows){//bubble sort
    char *temp;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows-1; j++){ //percorrem a matriz
            if (strlen(matrix[j]) > strlen(matrix[j+1])){ //se strlen > strlen da linha seguinte faz swap
                temp = matrix[j];
                matrix[j] = matrix[j+1];
                matrix[j+1] = temp;
            }
        }
    }
}

void sort_alphabetical(char **matrix, int rows, int cols){//bubble sort
    char *temp;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows-1; j++){
    if (strcmp(matrix[j], matrix[j+1]) > 0){ //se retornar positivo faz swap (nºpositivo = 1ª string > 2ª string)
                temp = matrix[j];
                matrix[j] = matrix[j+1];
                matrix[j+1] = temp;
            }
        }
    }
}


int compare_word_sets(char **matrix1, int rows1, int cols1, char **matrix2, int rows2, int cols2) {

    struct combination combinations[100];//array para armazenar combinações
    int combination_count = 0;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < rows2; j++) {
            //palavras em ufp6
            char *ufp6_1 = ufp6(matrix1[i]);
            char *ufp6_2 = ufp6(matrix2[j]);

            // compara as palavras em ufp6
            if (strcmp(ufp6_1, ufp6_2) == 0) {
                // armazena indices e palavras das combinações
                combinations[combination_count].index1 = i;
                combinations[combination_count].word1 = matrix1[i];
                combinations[combination_count].index2 = j;
                combinations[combination_count].word2 = matrix2[j];
                combination_count++;

                free(ufp6_1);
                free(ufp6_2);
            }
        }
    }
    if (combination_count > 0) {

        for (int k = 0; k < combination_count; k++) {
            printf("Set 1 - Index %d: %s UFP6:", combinations[k].index1, combinations[k].word1);
            passufp6(combinations[k].word1);

            printf("Set 2 - Index %d: %s UFP6:", combinations[k].index2, combinations[k].word2);
            passufp6(combinations[k].word2);
        }
        return 1;
    } else {
        printf("No combinations.\n");
        return 0;
    }
}

struct WORDS_HOLDER *create_words_holder(int rows, int cols) {
    struct WORDS_HOLDER *holder = (struct WORDS_HOLDER *)malloc(sizeof(struct WORDS_HOLDER));
    if (holder == NULL) {
        return NULL;
    }

    holder->words1 = create_matrix(rows, cols);
    if (holder->words1 == NULL) {
        free(holder);
        return NULL;
    }

    holder->words1_ufp6 = create_matrix(rows, cols);
    if (holder->words1_ufp6 == NULL) {
        //free(holder->words1);
        free(holder);
        return NULL;
    }

    // se inicializar lastUpdate com uma string vazia:
    strcpy(holder->lastUpdate, "");

    holder->rows = rows;
    holder->cols = cols;
    return holder;
}

// struct AD_WORDS_HOLDER *create_ad_words_holder(int size) que recebe um inteiro size e retorna um apontador para um AD_WORDS_HOLDER.
AD_WORDS_HOLDER *create_ad_words_holder(int size){
    AD_WORDS_HOLDER *ad_words_holder = (AD_WORDS_HOLDER *) malloc(sizeof(AD_WORDS_HOLDER));
    if (ad_words_holder == NULL){
        return NULL;
    }
    ad_words_holder->size = size;
    ad_words_holder->count = 0;
    ad_words_holder->array = NULL; //pword = primeira posicao do array. Inicialmente não tem nenhuma palavra.
    ad_words_holder->array= (VAL_AD_WORDS_HOLDER *) malloc(sizeof(VAL_AD_WORDS_HOLDER) * size);
    if (ad_words_holder->array == NULL){
        return NULL;
    }
    return ad_words_holder;
}



void insert_word_holder(struct WORDS_HOLDER *holder, int row, const char *word){
    insert_word(holder->words1, holder->rows,  row, word, holder->cols);
    insert_word(holder->words1_ufp6, holder->rows, row, word, holder->cols);
}


int remove_word_holder(struct WORDS_HOLDER *holder, char *word){
    int removed = remove_word(holder->words1, holder->rows, holder->cols, word);
    if (removed == 1){
        remove_word(holder->words1_ufp6, holder->rows, holder->cols, word);
    }
    return removed;
}

int pesquisa_holder(struct WORDS_HOLDER *holder, char *word){
    int count = 0;
    for (int i = 0; i < holder->rows; i++){
        if (strstr(holder->words1[i], word) != NULL){
            count++;
        }
    }
    for (int i = 0; i < holder->rows; i++){
        if (strstr(holder->words1_ufp6[i], word) != NULL){
            count++;
        }
    }
    printf("number of found words: %d\n", count);
    printf("UFP6: ");
    passufp6(word);
}


// redimensiona array
void resizeArray(AD_WORDS_HOLDER *arr, int newSize) {
    arr->array = realloc(arr->array, newSize * sizeof(VAL_AD_WORDS_HOLDER));
    arr->size = newSize;
}

// insere elemento por data de modificação
void insertElement(AD_WORDS_HOLDER *arr, VAL_AD_WORDS_HOLDER newElement) {
    if (arr->count == arr->size) {
        resizeArray(arr, arr->size * 2);  // redimensiona se necessário
    }

    int i = arr->count - 1;
    while (i >= 0 && strcmp(arr->array[i].data.lastUpdate, newElement.data.lastUpdate) > 0) {
        arr->array[i + 1] = arr->array[i];  // desloca elementos maiores para abrir espaço
        i--;
    }

    arr->array[i + 1] = newElement;
    arr->count++;
}

// insere elemento em posição específica
void insertElementAt(AD_WORDS_HOLDER *arr, VAL_AD_WORDS_HOLDER newElement, int index) {
    if (index < 0 || index > arr->count) {
        printf("invalid index\n");
        return;
    }

    if (arr->count == arr->size) {
        resizeArray(arr, arr->size * 2);  // redimensiona se necessário
    }

    for (int i = arr->count - 1; i >= index; i--) {
        arr->array[i + 1] = arr->array[i];  // desloca elementos maiores para abrir espaço
    }

    arr->array[index] = newElement; // insere em index especifico
    arr->count++;
}

// apaga elemento em posição específica
void deleteElementAt(AD_WORDS_HOLDER *arr, int index) {
    if (index < 0 || index >= arr->count) {
        printf("invalid index\n");
        return;
    }

    for (int i = index; i < arr->count - 1; i++) {
        arr->array[i] = arr->array[i + 1];  // desloca elementos maiores para abrir espaço
    }

    arr->count--;

    if (arr->count < arr->size / 2) {
        resizeArray(arr, arr->size / 2);  // redimensiona se necessário
    }
}

//ponto 9
struct LL_WORDS_HOLDER *create_ll_words_holder(){
    struct LL_WORDS_HOLDER *ll_words_holder = (struct LL_WORDS_HOLDER *) malloc(sizeof(struct LL_WORDS_HOLDER));
    if (ll_words_holder == NULL){
        return NULL;
    }
    ll_words_holder->first = NULL;
    ll_words_holder->used = 0;
    return ll_words_holder;
}

void insert_ll_words_holder(struct LL_WORDS_HOLDER *ll_words_holder, struct NODE_LL_WORDS_HOLDER *node_ll_words_holder){
    if (ll_words_holder->first == NULL){
        ll_words_holder->first = node_ll_words_holder;
        ll_words_holder->used++;
        return;
    }
    struct NODE_LL_WORDS_HOLDER *current = ll_words_holder->first;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = node_ll_words_holder;
    node_ll_words_holder->prev = current;
    ll_words_holder->used++;
}

void insert_ll_words_holder_at(struct LL_WORDS_HOLDER *ll_words_holder, struct NODE_LL_WORDS_HOLDER *node_ll_words_holder, int index){
    if (ll_words_holder->first == NULL){
        ll_words_holder->first = node_ll_words_holder;
        ll_words_holder->used++;
        return;
    }
    struct NODE_LL_WORDS_HOLDER *current = ll_words_holder->first;
    for (int i = 0; i < index; i++){
        current = current->next;
    }
    node_ll_words_holder->next = current;
    node_ll_words_holder->prev = current->prev;
    current->prev->next = node_ll_words_holder;
    current->prev = node_ll_words_holder;
    ll_words_holder->used++;
}

void remove_ll_words_holder_at(struct LL_WORDS_HOLDER *ll_words_holder, int index){
    struct NODE_LL_WORDS_HOLDER *current = ll_words_holder->first;
    for (int i = 0; i < index; i++){
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    ll_words_holder->used--;
}

void pesquisa_ll_words_holder(struct LL_WORDS_HOLDER *ll_words_holder, char *word){
    struct NODE_LL_WORDS_HOLDER *current = ll_words_holder->first;
    while (current != NULL){
        pesquisa_holder(current->holder, word);
        current = current->next;
    }
}

void free_ll_words_holder(struct LL_WORDS_HOLDER *ll_words_holder){
    struct NODE_LL_WORDS_HOLDER *current = ll_words_holder->first;
    while (current != NULL){
        free_words_holder(current->holder);
        current = current->next;
    }
    free(ll_words_holder);
}

void writeToFile(const char* filename, struct WORDS_HOLDER* wordsHolder) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("error opening");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d %d\n", wordsHolder->rows, wordsHolder->cols);

    for (int i = 0; i < wordsHolder->rows; i++) {
        // escreve no ficheiro as palavras
        fprintf(file, "%s ", wordsHolder->words1[i]);

        // passa a palavra para ufp6 e escreve
        char* ufp6Code = ufp6(wordsHolder->words1[i]);
        fprintf(file, "%s\n", ufp6Code);
        free(ufp6Code);
    }

    fclose(file);
}

//
struct WORDS_HOLDER* readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("error opening");
        exit(EXIT_FAILURE);
    }

    struct WORDS_HOLDER* wordsHolder = (struct WORDS_HOLDER*)malloc(sizeof(struct WORDS_HOLDER));
    if (wordsHolder == NULL) {
        perror("error allocating memory");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", &(wordsHolder->rows), &(wordsHolder->cols));

    wordsHolder->words1 = create_matrix(wordsHolder->rows, wordsHolder->cols);
    wordsHolder->words1_ufp6 = create_matrix(wordsHolder->rows, wordsHolder->cols);

    for (int i = 0; i < wordsHolder->rows; i++) {
        // le palavras do ficheiro
        fscanf(file, "%s", wordsHolder->words1[i]);

        // passa para ufp6 e le
        fscanf(file, "%s", wordsHolder->words1_ufp6[i]);
    }

    fclose(file);
    return wordsHolder;
}

void writeBinFile(const char* filename, struct WORDS_HOLDER* wordsHolder) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("error opening");
        exit(EXIT_FAILURE);
    }

    fwrite(&(wordsHolder->rows), sizeof(int), 1, file);
    fwrite(&(wordsHolder->cols), sizeof(int), 1, file);

    for (int i = 0; i < wordsHolder->rows; i++) {
        int wordLength = strlen(wordsHolder->words1[i]);
        fwrite(&wordLength, sizeof(int), 1, file);
        fwrite(wordsHolder->words1[i], sizeof(char), wordLength, file);

        int ufp6Length = strlen(wordsHolder->words1_ufp6[i]);
        fwrite(&ufp6Length, sizeof(int), 1, file);
        fwrite(wordsHolder->words1_ufp6[i], sizeof(char), ufp6Length, file);
    }

    fclose(file);
}

struct WORDS_HOLDER* readBinFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("error opening");
        exit(EXIT_FAILURE);
    }

    struct WORDS_HOLDER* wordsHolder = (struct WORDS_HOLDER*)malloc(sizeof(struct WORDS_HOLDER));
    if (wordsHolder == NULL) {
        perror("error allocating");
        exit(EXIT_FAILURE);
    }

    fread(&(wordsHolder->rows), sizeof(int), 1, file);
    fread(&(wordsHolder->cols), sizeof(int), 1, file);

    wordsHolder->words1 = create_matrix(wordsHolder->rows, wordsHolder->cols);
    wordsHolder->words1_ufp6 = create_matrix(wordsHolder->rows, wordsHolder->cols);
    for (int i = 0; i < wordsHolder->rows; i++) {
        int wordLength;
        fread(&wordLength, sizeof(int), 1, file);

        // aloca memória para palavra
        wordsHolder->words1[i] = (char*)malloc(sizeof(char) * (wordLength + 1));
        if (wordsHolder->words1[i] == NULL) {
            perror("error allocating memory");
            exit(EXIT_FAILURE);
        }

        fread(wordsHolder->words1[i], sizeof(char), wordLength, file);
        wordsHolder->words1[i][wordLength] = '\0';  // adiciona \0

        int ufp6Length;
        fread(&ufp6Length, sizeof(int), 1, file);

        // aloca memoria para codigo ufp6
        wordsHolder->words1_ufp6[i] = (char*)malloc(sizeof(char) * (ufp6Length + 1));
        if (wordsHolder->words1_ufp6[i] == NULL) {
            perror("error allocating memory");
            exit(EXIT_FAILURE);
        }

        fread(wordsHolder->words1_ufp6[i], sizeof(char), ufp6Length, file);
        wordsHolder->words1_ufp6[i][ufp6Length] = '\0';  // adiciona \0
    }

    fclose(file);
    return wordsHolder;
}






void clientrandommatrix(){

 int frutarow = 5;
    char **frutas = create_matrix(frutarow, 8);
    insert_random_words(frutas, frutarow, 8);
    list_words(frutas, frutarow, 8);

}

void clientmatrix(){

    int matrix_row_size = 8;
    int max_word_length = 7;

    int rowsfruta=4;
    int colsfrutas=8;
    char **frutas = create_matrix(rowsfruta, colsfrutas);

    insert_word(frutas, matrix_row_size, 0, "a", max_word_length);
    //insert_word(frutas, matrix_row_size, 1, "melao", max_word_length);
    insert_word(frutas, matrix_row_size, 2, "pera", max_word_length);
    insert_word(frutas, matrix_row_size, 3, "banana", max_word_length);
    list_words(frutas, rowsfruta, colsfrutas);

}

void clientsortmatrix(){

    int matrix_row_size = 8;
    int max_word_length = 7;

    char **frutas = create_matrix(5, 8);
    insert_word(frutas, matrix_row_size, 0, "melao", max_word_length);
    insert_word(frutas, matrix_row_size, 1, "pera", max_word_length);
    insert_word(frutas, matrix_row_size, 2, "banana", max_word_length);
    insert_word(frutas, matrix_row_size, 3, "feijao", max_word_length);
    insert_word(frutas, matrix_row_size, 4, "maca", max_word_length);
    sort_alphabetical(frutas, 5, 7);
    list_words(frutas, 5, 8);

    printf("\n");

    sort_size(frutas, 5);
    list_words(frutas, 5, 8);
}

void clientcomparematrix(){

    int matrix_row_size = 8;
    int max_word_length = 7;

    char **frutas = create_matrix(6, 8);
    insert_word(frutas, matrix_row_size, 0, "melao", max_word_length);
    insert_word(frutas, matrix_row_size, 1, "uva", max_word_length);
    insert_word(frutas, matrix_row_size, 2, "banana", max_word_length);
    insert_word(frutas, matrix_row_size, 3, "pera", max_word_length);
    insert_word(frutas, matrix_row_size, 4, "maca", max_word_length);
    insert_word(frutas, matrix_row_size, 5, "lima", max_word_length);


    printf("\n");

    char **cereais = create_matrix(5, 8);
    insert_word(cereais, matrix_row_size, 0, "soja", max_word_length);
    insert_word(cereais, matrix_row_size, 1, "uva", max_word_length);
    insert_word(cereais, matrix_row_size, 2, "uva", max_word_length);
    insert_word(cereais, matrix_row_size, 3, "arroz", max_word_length);
    insert_word(cereais, matrix_row_size, 4, "banana", max_word_length);

    printf("\n");

    compare_word_sets(frutas, 6, 8,cereais,5,8);


}
void clientsearchmatrix(){

    int matrix_row_size = 8;
    int max_word_length = 7;

    char **frutas = create_matrix(3, 8);
    insert_word(frutas, matrix_row_size, 0, "melao", max_word_length);
    insert_word(frutas, matrix_row_size, 1, "pera", max_word_length);
    insert_word(frutas, matrix_row_size, 2, "banana", max_word_length);
    list_words(frutas, 3, 8);
    printf("\n");
    search(frutas, 3, "a");

}

void clientremovematrix(){

    int matrix_row_size = 8;
    int max_word_length = 7;

    char **frutas = create_matrix(6, 8);
    insert_word(frutas, matrix_row_size, 0, "melao", max_word_length);
    insert_word(frutas, matrix_row_size, 1, "pera", max_word_length);
    insert_word(frutas, matrix_row_size, 2, "figo", max_word_length);
    insert_word(frutas, matrix_row_size, 3, "maca", max_word_length);
    insert_word(frutas, matrix_row_size, 4, "limao", max_word_length);
    insert_word(frutas, matrix_row_size, 5, "banana", max_word_length);
    list_words(frutas, 6, 8);
    printf("\n");
    remove_word(frutas, 6, 8, "banana");
    list_words(frutas, 6, 8);

}


void clientfiles(){

         struct WORDS_HOLDER myWordsHolder;
       myWordsHolder.rows = 5;
       myWordsHolder.cols = 7;

       myWordsHolder.words1 = create_matrix(myWordsHolder.rows, myWordsHolder.cols);
       myWordsHolder.words1_ufp6 = create_matrix(myWordsHolder.rows, myWordsHolder.cols);

       insert_word(myWordsHolder.words1, myWordsHolder.rows, 0, "joao", myWordsHolder.cols);
       insert_word(myWordsHolder.words1, myWordsHolder.rows, 1, "fred", myWordsHolder.cols);
       insert_word(myWordsHolder.words1, myWordsHolder.rows, 2, "patric", myWordsHolder.cols);
       insert_word(myWordsHolder.words1, myWordsHolder.rows, 3, "porto", myWordsHolder.cols);
       insert_word(myWordsHolder.words1, myWordsHolder.rows, 4, "UFP6", myWordsHolder.cols);



       writeToFile("projetoLpAed.txt", &myWordsHolder); //chama a função para escrever no ficheiro

       free(myWordsHolder.words1);


    // Usa a função readFromFile para carregar dados do arquivo "input.txt" para a estrutura
    myWordsHolder = *readFromFile("projetoLpAed.txt");

    // Agora, a estrutura myWordsHolder contém os dados lidos do arquivo

    for (int i = 0; i < myWordsHolder.rows; i++) {
        printf("%s", myWordsHolder.words1[i]);
        printf(" UFP6: %s", myWordsHolder.words1_ufp6[i]);
        printf("\n");
    }

    // Não te esqueças de liberar a memória alocada para a estrutura quando não precisares mais dela
    free_matrix(myWordsHolder.words1, myWordsHolder.rows);
    free_matrix(myWordsHolder.words1_ufp6, myWordsHolder.rows);

}




void clientbinfiles(){


/*
    // cria uma estrutura WORDS_HOLDER e preenche com palavras e códigos UFP6
    struct WORDS_HOLDER myWordsHolder;
     myWordsHolder.rows = 3;
     myWordsHolder.cols = 7;
     myWordsHolder.words1 = create_matrix(myWordsHolder.rows, myWordsHolder.cols);
     myWordsHolder.words1_ufp6 = create_matrix(myWordsHolder.rows, myWordsHolder.cols);

     insert_word(myWordsHolder.words1, myWordsHolder.rows, 0, "a", myWordsHolder.cols);
     insert_word(myWordsHolder.words1, myWordsHolder.rows, 1, "bana", myWordsHolder.cols);
  insert_word(myWordsHolder.words1, myWordsHolder.rows, 2, "exame", myWordsHolder.cols);

  for (int i = 0; i < myWordsHolder.rows; i++) {
      myWordsHolder.words1_ufp6[i] = ufp6(myWordsHolder.words1[i]);
  }

  // escrever num ficheiro binário
  writeBinFile("output.bin", &myWordsHolder);


  free_words_holder(&myWordsHolder);

*/

    struct WORDS_HOLDER myWordsHolder = *readBinFile("output.bin");

    // imprime palavras e códigos UFP6
    for (int i = 0; i < myWordsHolder.rows; i++) {
        printf("%s", myWordsHolder.words1[i]);
        printf(" UFP6: %s", myWordsHolder.words1_ufp6[i]);
        printf("\n");
    }

    free_words_holder(&myWordsHolder);

}

/*
void clienttopico8() {

    // cria array dinamico
    AD_WORDS_HOLDER wordsArray;
    wordsArray.size = 8;
    wordsArray.count = 0;
    wordsArray.array = (VAL_AD_WORDS_HOLDER *)malloc(wordsArray.size * sizeof(VAL_AD_WORDS_HOLDER));

    // Cria e insere elementos no array
    VAL_AD_WORDS_HOLDER element1;
    //insert_word(element1.data.words1, 7, 0, "melao", 7);
    insertElement(&wordsArray, element1);
    printarray(&element1);

}
*/
