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
    if(head!=NULL) {
        ptrNode current = head;

        while(current!=NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }

        printf("NULL\n");
    } else {
        printf("La lista esta vacia.\n");
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
    ptrNode new_node = malloc(sizeof(struct Node));
    
    if(new_node != NULL) {//Si hemos podido reservar memoria...
        ptrNode current = *ptrhead;
        bool no_more_elements = false;
        
        if(current!=NULL) {//y la lista NO esta vacia...
            while(no_more_elements==false) { //Mientras haya un elemento...
                if(current->next!=NULL) {//y este tenga otro detras
                    current = current->next;
                } else {//y este no tenga otro detras...
                    current->next = new_node;
                    new_node->data = data;
                    new_node->next = NULL;
                    no_more_elements = true;
                }
            }
            printf("Insertado el nodo %d.\n", new_node->data);
        } else { //y la lista esta vacia...
            *ptrhead = new_node;
            new_node->data = data;
            new_node->next = NULL;
            printf("Primer nodo %d insertado.\n", new_node->data);
        }
    } else {
        printf("No se ha podido reservar memoria.\n");
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
    ptrNode current = *ptrhead;
    ptrNode previous = NULL;
    bool found = false;

    while(current!=NULL && found==false) {
        if(current->data == data) { //Si el dato actual es el que estamos buscando...
            if(previous == NULL) { //y se ha encontrado en el primer nodo de la lista...
                *ptrhead = current->next;
            } else{ //y se ha encontrado en un nodo que no es el primero de la lista...
                previous->next = current->next;
            }
            free(current);
            printf("Nodo %d eliminado.\n", data);
            found = true;
        } else { // Si el dato actual no es el que buscamos...
            previous = current;
            current = current->next;
        }
    }

    if(found==false) {
        printf("El nodo %d no esta en la lista.\n", data);
    }

    return found;
}

/**
 * @brief Destruye la lista enlazada
 * @param ptrhead Puntero al primer nodo de la lista enlazada. Al finalizar la función, ptrhead apuntará a NULL
 */
void destruir(ptrNode *ptrhead)
{
    ptrNode current = *ptrhead;
    ptrNode next_node = NULL;

    while(current!=NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *ptrhead = NULL;

    printf("Lista destruida.\n");
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

    iterar(head);

    assert(head == NULL);

    return 0;
}