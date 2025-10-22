#include <stdio.h>
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

    // Si no se crea, el puntero valdrá NULL
    if(nueva==NULL){
        control = false;
    }
    
    // ¿Pq me pasan el puntero del puntero? Si con el puntero me vale

    // 2 casos: Lista Vacia o Lista con Elementos
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
    bool eliminado = true;
    ptrNode aux = *ptrhead;
    ptrNode ant = NULL; // le meto NULL pq no puedo dejarlo vacio en caso de que ptrhead sea NULL y no se ejecute el bucle de abajo
    ptrNode fut = NULL;

    if (aux==NULL){
        eliminado=false;
    }

    while(aux!=NULL){
        if(data==aux->data){
            if (ant==NULL){
                *ptrhead = aux->next;
            } else{
                ant->next=fut;
            }
            free(aux);
        }
        // CUIDADO PUNTERO COLGANTE ----------------------------
        ant= aux;
        aux = aux->next;
        fut = aux->next;
    }

    return eliminado;
}

/**
 * @brief Destruye la lista enlazada
 * @param ptrhead Puntero al primer nodo de la lista enlazada. Al finalizar la función, ptrhead apuntará a NULL
 */
void destruir(ptrNode *ptrhead)
{
    ;
}

int main(void)
{
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