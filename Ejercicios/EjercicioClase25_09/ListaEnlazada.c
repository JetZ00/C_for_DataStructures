#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node* ptrNode; // Alias para un puntero a la estructura
typedef struct Node{
    int data;
    ptrNode next;
} Nodo; // Alias para la estructura

/**
 * @brief Itera y muestra por pantalla la lista enlazada
 * @param head Puntero al primer nodo de la lista enlazada
 */
void iterar(ptrNode head){
    
    ptrNode aux = head;

    while(aux!=NULL){
        printf("%d",aux->data);
        aux = aux->next;
    }
}

/**
 * @brief Inserta un nodo en la lista enlazada
 * @param ptrhead  Puntero al primer nodo de la lista enlazada
 * @param data    Dato a insertar en el nodo
 * @return true si se insertó correctamente, false en caso contrario
 */

bool insertar(ptrNode* ptrhead, int data){

    bool control = true;
    ptrNode nueva = malloc(sizeof(Nodo));

    nueva->data = data;
    nueva->next = NULL;

    if(nueva==NULL){
        control = false;
    }
    
    if (*ptrhead == NULL){
        *ptrhead = nueva;
    } else{

        ptrNode aux = *ptrhead;
        ptrNode ultimo;

        do{
            ultimo = aux;
            aux = aux->next;
        } while(aux!=NULL);
        
        ultimo->next=nueva;
    }

    return control;
}

/**
 * @brief Elimina un nodo de la lista enlazada
 * @param ptrhead Puntero al primer nodo de la lista enlazada
 * @param data  Dato a eliminar del nodo
 * @return true si se eliminó correctamente, false en caso contrario
 */
bool eliminar(ptrNode* ptrhead, int data){
    bool eliminado = false;
    ptrNode aux = *ptrhead;
    ptrNode ant = NULL;

    if (aux==NULL){
        eliminado=false;
    }

    while(aux!=NULL){

        if(data==aux->data){
            if (ant==NULL){
                *ptrhead = aux->next;
            } else{
                ant->next= aux->next;
            }
            free(aux);
            eliminado = true;
            break;
        }

        ant=aux;
        aux=aux->next;
        
    }

    return eliminado;
}


/**
 * @brief Destruye la lista enlazada
 * @param ptrhead Puntero al primer nodo de la lista enlazada. Al finalizar la función, ptrhead apuntará a NULL
 */
void destruir(ptrNode *ptrhead){
    ptrNode aux;
    aux= *ptrhead;

    while(*ptrhead!= NULL){
        *ptrhead=(*ptrhead)->next; // o tmb: *ptrhead=aux->next
        free(aux);
        aux=*ptrhead;
    }
}

bool insertarOrdenado(ptrNode *ptrhead, int data) {

                                        // string data
                                        // strcmp(string1,string2) : Puede ser -1, 0, 1
    ptrNode nuevo;
    ptrNode anterior = NULL;
    ptrNode actual = *ptrhead;

    nuevo = malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        return false; 
    }
    nuevo->data = data;

    while (actual != NULL && actual->data < data) {
        anterior = actual;
        actual = actual->next;
    }

    if (anterior == NULL) { 
        *ptrhead = nuevo;
    } else {
        anterior->next = nuevo;
    }
    nuevo->next = actual;
    
    return true;
}

// HIPOTETICO CASO QUE EN EL NODO: char[TAM] data;
bool insertarOrdenadoString(ptrNode *ptrhead, char data[]) {


    // strlen - Longitud del string
    // strcpy - Copiar string
    // strcmp -> Comparar string (+1 si String1>String2)

    ptrNode nuevo;
    ptrNode anterior = NULL;
    ptrNode actual = *ptrhead;

    nuevo = malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        return false;
    }

    nuevo->data = malloc(strlen(data) + 1); 
    if (nuevo->data == NULL) {
        free(nuevo); // Liberamos el nodo si falla la memoria para el string
        return false;
    }
    strcpy(nuevo->data, data);

    while (actual != NULL && strcmp(actual->data, data) < 0) {
        anterior = actual;
        actual = actual->next;
    }

    if (anterior == NULL) {
        *ptrhead = nuevo;
    } else {
        anterior->next = nuevo;
    }
    nuevo->next = actual;

    return true;
}



int main(void){
    ptrNode head = NULL;

    // Primero probamos a usar las funciones con una lista NULL
    iterar(head);
    assert(eliminar(&head, 1) == false);

    // Insertar un nodo 1 en cabeza
    assert(insertar(&head, 1) == true);

    // Insertar otro nodo 1, la lista acepta duplicados
    assert(insertar(&head, 1) == true);

    // Insertar otro nodo 5 en la cola
    assert(insertar(&head, 5) == true);

    // Insertar otro nodo 4 en la cola
    assert(insertar(&head, 4) == true);

    // Mostramos la lista
    iterar(head);

    // Eliminar un nodo en cabeza, debe dar true
    assert(eliminar(&head, 1) == true);

    // Eliminar un nodo en cola, debe dar true
    assert(eliminar(&head, 5) == true);

    // Eliminar un nodo que no existe, debe dar false
    assert(eliminar(&head, 99) == false);

    // Mostramos la lista
    iterar(head);

    // Destruir la lista enlazada
    destruir(&head);

    assert(head == NULL);

    return 0;
}