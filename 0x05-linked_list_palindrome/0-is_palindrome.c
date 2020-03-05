#include "lists.h"

/**
 * is_palindrome - determines if linked list is a palindrome
 * @head: address of pointer to head node
 * Return: 1 if palindrome else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *tail;
	int result = 1;

	if (!head || !*head || !(*head)->next)
		return (1);

	slow = fast = *head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = tail = reverse_list(slow);
	slow = *head;
	while (fast)
	{
		if (fast->n != slow->n)
		{
			result = 0;
			break;
		}
		fast = fast->next;
		slow = slow->next;
	}
	reverse_list(tail);
	return (result);
}

/**
 * reverse_list - reverses a linked list
 * @curr: pointer to head
 * Return: address of new head
 */
listint_t *reverse_list(listint_t *curr)
{
	listint_t *prev = NULL, *next;

	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return (prev);
}
