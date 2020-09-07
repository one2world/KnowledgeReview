

#include <cstdio>

#include "linklist.h"



LinkHeader* create_linklist()
{
	LinkHeader* root = (LinkHeader*)malloc(sizeof(LinkHeader));
	return root;
}

int free_linklist(LinkHeader* root, NextLinkDataFunc next_callback)
{
	if(root == NULL || root->size <=0)
		return 0;

	LinkNode* node = root->next;
	for (int i = 0; i < root->size; ++i)
	{

		if(node == NULL)
		{
			return i;
		}

		if(next_callback != NULL && node->data !=NULL)
		{
			nodenext_callback(node->data);
		}

		node = node->next;
		free(node);
	}

	free(root);
	root = NULL;
}


int linklist_addbefore(LinkHeader* root, void* data, int pos)
{
	--pos;
	if(root == NULL)
		return 0;

	if(root->size <= pos || pos <0)
		return 0;



	LinkNode* node = root->next;
	for (int i = 0; i < root->size; ++i)
	{

		if (i < pos)
		{
			if(node == NULL)
			{
				printf("exception: linklist'add, pos %d, size %d, but at %d is NULL\n",pos, root->size, i);
				return 0;
			}
		}
		else if(i == pos)
		{

			LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
			new_node->data = data;
			new_node->next = node->next;
			node->next = new_node;
			++root->size;
			return 1;
		}
	}

	printf("exception2: linklist'add, pos %d, size %d\n",pos, root->size);
	return 0;
}

int linklist_removebefore(LinkHeader* root, void* data, int pos, NextLinkDataFunc next_callback)
{
	if(root == NULL)
		return 0;


	if(root->size < pos || pos <=0)
		return 0;


	--pos;
	LinkNode* node = root->next;
	for (int i = 0; i < root->size; ++i)
	{
		if (i < pos)
		{
			if(node == NULL)
			{
				printf("exception: linklist'remove, pos %d, size %d, but at %d is NULL\n",pos, root->size, i);
				return 0;
			}
		}
		else if(i == pos)
		{
			LinkNode* temp = node->next;
			node->next = temp->next;

			if(next_callback != NULL)
			{
				next_callback(temp->data);
			}
			free(temp);
			temp = NULL;
			--root->size;
			return 1;
		}
	}

	printf("exception2: linklist'remove, pos %d, size %d\n",pos, root->size);
	return 0;
}