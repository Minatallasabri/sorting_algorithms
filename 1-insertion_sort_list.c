#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list of integers in
* ascending order using the Insertion sort algorithm
* @list: List to order
* Return : Void - No return
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *node_prev = NULL, *node_next = NULL, *temp = NULL;
	int insert = 0;

	if (!list || !*list)
		return;

	temp = *list;

	while (temp)
	{
		if (temp->prev != NULL)
		{
			node = temp;
			insert = 0;
			while (node && node->prev->n > node->n)
			{
				node_prev = node->prev;
				node_next = node->next;

				if (node_prev->prev)
					node_prev->next = node;
				else
				{
					*list = node;
					insert = 1;
				}
				if (node_next)
					node_next->prev = node_prev;

				node->prev = node_prev->prev;
				node->next = node_prev;
				node_prev->prev = node;
				node_prev->next = node_next;
				print_list(*list);
				if (insert)
					break;
			}
		}
		temp = temp->next;
	}
}
