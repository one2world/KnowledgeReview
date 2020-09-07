#ifndef __linklist_H__
#define __linklist_H__
#endif

#define NULL  0
//#define size_t  int

typedef struct link_list_node
{
	void* data;
	LinkNode* next;
}LinkNode;

typedef struct link_list_head
{
	int size;  // 外部不能修改
	LinkNode* next;
}LinkHeader;


typedef  void (*NextLinkDataFunc)(void*);

LinkHeader* create_linklist();
int free_linklist(LinkHeader* root, NextLinkDataFunc next_callback);
int linklist_addbefore(LinkNode* root, void* data, int pos);
int linklist_removebefore(LinkNode* root, void* data, int pos, NextLinkDataFunc next_callback);