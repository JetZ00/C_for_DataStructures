#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node *ptrNode; // Alias para un puntero a la estructura
typedef struct Node
{
    int data;
    ptrNode next;
} Node; // Alias para la estructura

/**
 * @brief Itera y muestra por pantalla la lista enlazada
 * @param head Puntero al primer nodo de la lista enlazada
 */
void iterar(ptrNode head)
{
    ptrNode aux;
    aux = head;
    while(aux!=NULL){
        printf("%d",aux->data);
        aux->next;
    }
}

/**
 * @brief Inserta un nodo en la lista enlazada
 * @param ptrhead  Puntero al primer nodo de la lista enlazada
 * @param data    Dato a insertar en el nodo
 * @return true si se insertó correctamente, false en caso contrario
 */
bool insertar(ptrNode *ptrhead, int data)
{
    ptrNode aux;
    ptrNode nuevo;

    nuevo =malloc(sizeof(struct Node));
    if(nuevo==NULL){
        return false;
    }
    nuevo->data=data;
    nuevo->next=NULL;
    aux=*ptrhead;

    if(*ptrhead==NULL){
        *ptrhead = nuevo;
    } else{
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux ->next=nuevo;
    }
    return true;
}

/**
 * @brief Elimina un nodo de la lista enlazada
 * @param ptrhead Puntero al primer nodo de la lista enlazada
 * @param data  Dato a eliminar del nodo
 * @return true si se eliminó correctamente, false en caso contrario
 */
bool eliminar(ptrNode *ptrhead, int data)
{
    ptrNode act = *ptrhead;
    ptrNode ant = NULL;
    bool eliminado = false;

    if(*ptrhead!=NULL){ // o "if(act=NULL) return false;"

        while((act != NULL) && (act->data != data) && (!eliminado)) {
            ant = act;
            act = act->next;
    }
        
        if(act!=NULL){
            if(act==*ptrhead){ // ant==NULL
                *ptrhead=act->next; // *ptrhead=(*ptrhead)->next;
            } else{
                ant->next=act->next;
            }
            free(act);
            eliminado = true;
        }
    }

    return eliminado;

}

/**
 * @brief Destruye la lista enlazada
 * @param ptrhead Puntero al primer nodo de la lista enlazada. Al finalizar la función, ptrhead apuntará a NULL
 */
void destruir(ptrNode *ptrhead)
{
    ptrNode aux;
    aux= *ptrhead;

    while(*ptrhead!= NULL){
        *ptrhead=(*ptrhead)->next; // o tmb: *ptrhead=aux->next
        free(aux);
        aux=*ptrhead;
    }
   ;
}

bool insertarOrdenado(ptrNode *ptrhead, int data) {
    ptrNode nuevo;
    ptrNode anterior = NULL;
    ptrNode actual = *ptrhead;

    nuevo = malloc(sizeof(Node));
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