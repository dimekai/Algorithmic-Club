/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    /*
        |====== IDEA DE SOLUCION ======|
        Es ir recorriendo la lista a partir del inicio (head)
        y posteriormente y comparando si el valor del nodo actual 
        es igual al valor del nodo que sigue. Si es asi, entonces
        elimino el nodo redundante, pero no sin antes guardar la direccion
        hacia dicho nodo redundante apunta
    */


    ListNode * actual = A;
    ListNode * aux;

    while( actual->next != NULL ){
        if( actual->val == actual->next->val){  //Verifico si el valor esta repetido
            aux = actual->next;                 //Guardo el nodo que es redundante.
            actual->next = actual->next->next;  //Me muevo al siguiente nodo, del nodo redundante 
            aux->next = NULL;                   //Elimino el nodo redundante
        }else{
            actual = actual->next;
        }
    }
    return A;
}
