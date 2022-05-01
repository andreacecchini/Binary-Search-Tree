/****************************************************************************
 *
 * bst.c -- Alberi binari di ricerca
 *
 * Copyright (C) 2021, 2022 Moreno Marzolla
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/***
% LabASD - Alberi binari di ricerca
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2022-04-03

![Fonte: <https://www.pinterest.com/pin/binary-tree-funny--547961479663761031/>](binary_tree.png "Un albero binario")

Il file [bst.h](bst.h) contiene la specifica dell'interfaccia di un
albero binario di ricerca (BST, _binary search tree_). Si chiede di
completare l'implementazione realizzando le funzioni indicate. È
possibile definire ulteriori funzioni di supporto che si ritengano
necessarie.

Un BST è definito dalla struttura:

```C
typedef struct {
    BSTNode *root;
    int size;
} BST;
```

dove `root` punta alla radice dell'albero se presente, oppure a `NULL`
se l'albero è vuoto, e `size` è il numero di nodi dell'albero. Il
campo `size` consente di conoscere il numero di nodi dell'albero in
tempo $O(1)$, senza bisogno di contarli ogni volta. Occorre però
mantenere aggiornato tale valore durante le operazioni di inserimento
e cancellazione.

Un nodo di un BST è definito dalla struttura `BSTNode` seguente:

```C
typedef int BSTKey;

typedef struct BSTNode {
    BSTKey key;
    struct BSTNode *parent, *left, *right;
} BSTNode;
```

dove `BSTKey` è il tipo dell'informazione mantenuta in ciascun nodo
(assumiamo che sia intero), mentre `parent`, `left` e `right` sono
rispettivamente puntatori al padre, al figlio sinistro e al figlio
destro del nodo. Nel caso della radice si avrà `parent == NULL`.  Un
esempio è mostrato nella Figura 1.

![Figura 1: Esempio di albero binario di ricerca](bst.png)

Le operazioni di inserimento e ricerca non dovrebbero presentare
difficoltà. La specifica della funzione di inserimento indica che
possono esistere più nodi contenenti la stessa chiave. A tale scopo
ricordiamo la proprietà di ordine dei BST come riportata sul libro di
test:

> **Proprietà di un BST**. Sia $x$ un nodo di un BST. Se $y$ è un nodo
> del sottoalbero sinistro di $x$, allora si avrà $y.\mathit{key} \leq
> x.\mathit{key}$; se $z$ è un nodo del sottoalbero destro di $x$,
> allora si avrà $z.\mathit{key} > x.\mathit{key}$.

Nel caso in cui si vogliano implementare l'inserimento o la ricerca in
modo ricorsivo, potrebbe essere necessario definire ulteriori funzioni
a supporto di quelle previste dall'interfaccia.

L'operazione più complessa è la cancellazione. Nella soluzione
realizzata si è seguito il procedimento descritto nel libro di testo:
se il nodo da cancellare ha due figli, si rimpiazza il suo contenuto
con il valore _minimo_ del sottoalbero _destro_; una soluzione
alternativa, ugualmente corretta, consiste nel rimpiazzare il
contenuto del nodo cancellato con il _massimo_ del sottoalbero
_sinistro_.

La funzione `bst_pretty_print()` (che suggerisco di lasciare per
ultima, dato che è la meno importante) stampa un BST in modo un po'
più leggibile, ruotando di 90 gradi quanto viene stampato.

Ad esempio, la funzione `bst_pretty_print()` potrebbe produrre l'output
seguente:

```
   55
12
      9
   5
      -3
```

che rappresenta l'albero:

```
         12
        /  \
       5    55
      / \
    -3   9
```

Il programma [bst-main.c](bst-main.c) legge una sequenza di comandi da
standard input o da un file il cui nome va specificato come unico
parametro sulla riga di comando. I comandi sono descritti nella
Tabella 1, dove _k_ è una chiave intera.

: Tabella 1: Comandi nel file di input

Comando       Significato
-----------   ----------------------------------------------
`+` _k_       Inserisce la chiave _k_
`-` _k_       Cancella il nodo contenente _k_, se presente
`?` _k_       Verifica se la chiave _k_ è presente
`s`           Stampa il numero di nodi nell'albero
`h`           Stampa l'altezza dell'albero
`p`           Stampa tutto il contenuto dell'albero
-----------   ----------------------------------------------

Un esempio di file di input è [bst.in](bst.in); l'output
corrispondente è [bst.out](bst.out).

Per compilare:

        gcc -std=c90 -Wall -Wpedantic bst.c bst-main.c -o bst-main

Per eseguire:

        ./bst-main < bst.in

oppure

        ./bst-main bst.in

## Per approfondire

- Scrivere una funzione che, dato un intero $n > 0$, inserisca le
  chiavi $\{0, 1, \ldots, n - 1\}$ in un BST inizialmente vuoto in
  modo da ottenere un albero di altezza minima possibile.

- Le procedure di inserimento e ricerca possono essere espresse in
  modo iterativo (come fatto nel libro di testo) oppure ricorsivo. È
  istruttivo provare ad implementarle in entrambi i modi.

- Qual è l'altezza media di un BST in cui vengono inserite $n$ chiavi
  casuali? [È stato
  dimostrato](https://dl.acm.org/doi/10.1145/765568.765571) che
  l'altezza media è $\left(\alpha \ln n - \beta \ln \ln n +
  O(1)\right)$, con $\alpha \approx 4.311$ e $\beta \approx 1.953$.
  Si provi a verificare sperimentalmente questo risultato: si
  consideri un opportuno insieme di valori di $n$, ad esempio $n=1000,
  2000, 3000, \ldots, 20000$. Per ogni $n$ si generino 100 alberi,
  ciascuno contenente $n$ chiavi casuali, e si calcoli l'altezza media
  dei 100 alberi. Alla fine si riporti su un grafico l'altezza media
  in funzione di $n$.

## File

- [bst.c](bst.c)
- [bst.h](bst.h)
- [bst-main.c](bst-main.c)
- [bst.in](bst.in) ([output atteso](bst.out))
- [bst1.in](bst1.in)
- [bst2.in](bst2.in)

***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "bst.h"

BST *bst_create( void )
{
    BST *T = (BST*)malloc(sizeof(*T));
    assert(T != NULL);

    T->root = NULL;
    T->size = 0;
    return T;
}

/* Funzione ausiliaria che libera ricorsivamente la memoria usata dal
   nodo `n` e da tutti i nodi che discendono da esso */
static void bst_clear_rec(BSTNode *n)
{
    if (n != NULL) {
        bst_clear_rec(n->left);
        bst_clear_rec(n->right);
        free(n);
    }
}
/*
 * Esegue lo spostamento dei sottoalberi all'interno del BST.
 * Utile per la cancellazione di un nodo all'interno dell'albero
 * */
static void bst_transplant(BST *T, BSTNode *u , BSTNode *v){
  if(u->parent == NULL) T->root = v;
  else if (u == u->parent->left) u->parent->left = v;
  else u->parent->right = v;
  if(v != NULL) v->parent = u->parent;
}
/* Calcolo ricorsivamente l'altezzza dell'albero binario di ricerca */
static int bst_height_rec(const BSTNode *root){
  
  static int left_height = 0;
  static int right_height = 0;

  if(root == NULL) return 0;
  /*Calcolo ricorsivamente l'altezza del sottoalbero sinistro*/
  left_height = bst_height_rec(root->left);
  /* Calcolo ricorsivamente l'altezza del sottoalbero destro */
  right_height = bst_height_rec(root->right);
  /* Ritorno il massimo tra le due altezze */ 
  return left_height > right_height ? left_height : right_height;
}


BSTNode *bst_minimum(BSTNode *n){
  assert(n != NULL);
  
  while(n->left != NULL) n = n->left;
  return n;
}

BSTNode *bst_maximum(BSTNode *n){
 assert(n != NULL);

  while(n->right != NULL) n = n->right;
  return n;
}


void bst_clear(BST *T)
{
    assert(T != NULL);

    bst_clear_rec(T->root);
    T->root = NULL;
    T->size = 0;
}

void bst_destroy(BST *T)
{
    bst_clear(T);
    free(T);
}


BSTNode *bst_search(const BST *T, BSTKey k)
{
    assert(T != NULL);
  
    BSTNode *tmp = T->root;
    while(tmp != NULL || k == tmp->key){
      if(k < tmp->key) tmp = tmp->left;
      else tmp = tmp->right;
    }
    return tmp;
}

BSTNode *bst_search_rec(BSTNode *root , BSTKey k){
  if(root == NULL || k == root->key) return root;
  if(k < root->key) return bst_search_rec(root->left, k);
  else return bst_search_rec(root->right, k);
}

void bst_insert(BST *T, BSTKey k)
{
    assert(T != NULL);
    BSTNode *new_node = (BSTNode *)calloc(1,sizeof(BSTNode));  
    new_node->key = k;
    BSTNode *y = NULL;
    BSTNode *x = T->root;
    while(x != NULL){
      y = x;
      if(k < x->key) x = x->left;
      else x = x->right;
    }
    new_node->parent = y;
    if(y == NULL) T->root = new_node;
    else if(k < y->key) y->left = new_node;
    else y->right = new_node;
}

void bst_insert_rec( BST *T, BSTNode *n, BSTKey k){
  static BSTNode *y = NULL;
  if(n == NULL){
    /* Alloco in memoria il nuovo elemento */
    BSTNode *new_node = (BSTNode *)calloc(1, sizeof(BSTNode));
    new_node->key = k;
    new_node->parent = y;
    if(y == NULL) T->root = new_node;
    else if(k < y->key) y->left = new_node;
    else y->right = new_node;
  }
  else{
    if(k < n->key) bst_insert_rec(T,n->left, k);
    else bst_insert_rec(T, n->right, k);
  }
}


void bst_delete(BST *T, BSTNode *n)
{
    assert(T != NULL);
    assert(n != NULL);

    BSTNode *tmp = NULL;

    if( n->left == NULL ) bst_transplant(T, n, n->right);

    else if( n->right == NULL ) bst_transplant(T, n, n->left);

    else{
      tmp = bst_minimum(n->right);

      if(tmp->parent != n){
        bst_transplant(T, tmp, tmp->right);
        tmp->right = n->right;
        tmp->right->parent = tmp;
      }

      bst_transplant(T, n, tmp);
      tmp->left = n->left;
      tmp->left->parent = tmp;
    }
}



int bst_height(const BST *T)
{
    assert(T != NULL);
    
    BSTNode *root = T->root;
    /* La chiamata ricorsiva desidera come argomento il nodo radice
     * non la struttura BST.
     * Per semplificazione in cima al file è stata definita una funzione
     * statica ricorsiva per il calcolo dell'altezza.
     * */
    return bst_height_rec(root);
 
}




/* Stampa ricorsivamente il contenuto del sottoalbero radicato nel
   nodo `n`. Il formato della stampa è:

   (root left right)

   dove `root` è il valore presente in `n`, mentre `left` e `right`
   sono il contenuto del sottoalbero sinistro e destro di `n`.  Se `n`
   è vuoto (cioè n == NULL), stampa ()
*/
static void bst_print_rec( const BSTNode *n )
{
    assert(n !=  NULL);

    rintf("(");
    if (n != NULL) {
        printf("%d ", n->key);
        bst_print_rec(n->left);
        printf(" ");
        bst_print_rec(n->right);
    }
    printf(")");
}

/* Nota: la funzione di stampa assume che `BSTKey` sia il tipo
   `int` */
void bst_print( const BST *T )
{
    assert(T != NULL);

    bst_print_rec(T->root);
    printf("\n");
}


void bst_pretty_print( const BST *T )
{
    assert(T != NULL);
    /* [TODO] */
}

int bst_size(const BST *T)
{
    assert(T != NULL);

    return T->size;
}

int bst_is_empty(const BST *T)
{
    assert(T != NULL);

    return (T->root == NULL);
}
