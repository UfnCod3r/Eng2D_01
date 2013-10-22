#pragma once

#include "XMemory.h"


namespace X
{
	template < typename T> class ForwardList
	{

	public:
		class Node
		{
			friend class ForwardList;
			Node(const T& value) : m_next(nullptr), m_value(value) {}
			Node* 	m_next;
		public:
			T		m_value;
			Node* next() const { return m_next; }

			inline void* operator new (size_t x)  { return gGenericAllocator.alloc(x);	}
			inline void operator delete (void* x) { gGenericAllocator.free(x);			}
		};

	private:
		uintptr		m_nodeHead;
		Node*		m_pLastNode;


	public:
		ForwardList()
		{
			m_nodeHead = 0;
			m_pLastNode = (Node*)&m_nodeHead;
		}
		ForwardList(const ForwardList& copy)
		{
			m_nodeHead = 0;
			m_pLastNode = (Node*)&m_nodeHead;
			Node* node = copy.firstNode();
			while (node)
			{
				push(node->m_value);
				node = node->next();
			}
		}
		~ForwardList()
		{
			clear();
		}

		ForwardList& operator = (const ForwardList& copy) 
		{
			clear();
			Node* node = copy.firstNode();
			while (node)
			{
				push(node->m_value);
				node = node->next();
			}
			return *this;
		}


		Node*	firstNode() const		{ return (Node*)m_nodeHead;	}
		uint	nodeCount() const
		{
			uint n = 0;
			Node* iter = firstNode();
			while(iter)
			{
				iter = iter->next();
				n++;
			}
			return n;
		}

		void clear()
		{
			Node* iter = firstNode();
			while (iter)
			{
				Node* tmp = iter;
				iter = iter->next();
				delete tmp;
			}
			m_nodeHead = 0;
			m_pLastNode = (Node*)&m_nodeHead;
		}
		Node* push(const T& value)
		{
			Node* newNode = new Node(value);
			m_pLastNode->m_next = newNode;
			m_pLastNode = newNode;
			return newNode;
		}
		bool deleteNode(Node* node)
		{
			if(node == nullptr) return false;

			Node* iter = (Node*)m_nodeHead;
			Node* iterPre = (Node*)&m_nodeHead;
			while (iter)
			{
				if(iter == node)
				{
					if(iter == m_pLastNode)
						m_pLastNode = iterPre;
					iterPre->m_next = iter->m_next;
					delete iter;
					return true;
				}

				iterPre = iter;
				iter = iter->next();
			}
			return false;
		}
		Node* operator [] (size_t i) const
		{
			Node* iter = firstNode();
			while (((uintptr)iter) * i)
			{
				iter = iter->next();
				i--;
			}
			return iter;
		}
	};
}