#pragma once

#include "XMemory.h"


namespace X
{
	//////////////////////////////////////////////////////////////////////////ForwardList
	template < typename Type, GenericAllocator& Allocator = GGenericAllocator> class ForwardList
	{

	public:
		class Node
		{
			friend class ForwardList;
			Node(const Type& value) : m_next(nullptr), m_value(value) {}
			Node* 	m_next;
		public:
			Type		m_value;
			Node* next() const { return m_next; }

			inline void* operator new (size_t x)  { return Allocator.alloc(x);	}
			inline void operator delete (void* x) { Allocator.free(x);			}
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
		Node* push(const Type& value)
		{
			Node* newNode = new Node(value);
			m_pLastNode->m_next = newNode;
			m_pLastNode = newNode;
			return newNode;
		}
		bln deleteNode(Node* node)
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







	//////////////////////////////////////////////////////////////////////////ForwardList, Thread Safe
	template < typename Type> class ForwardListTS
	{

	public:
		class Node
		{
			friend class ForwardListTS;
			Node(const Type& value) : m_next(nullptr), m_value(value) {}
			Node* 	m_next;
		public:
			Type		m_value;
			Node* next() const { return m_next; }

			inline void* operator new (size_t x)  { return GGenericAllocator.alloc(x);	}
			inline void operator delete (void* x) { GGenericAllocator.free(x);			}
		};

	private:
		volatile uintptr	m_nodeHead;
		Node*				m_pLastNode;
		mutable TAC			m_tac;

	public:
		ForwardListTS()
		{
			m_nodeHead = 0;
			m_pLastNode = (Node*)&m_nodeHead;
			m_tac.init();
		}
		ForwardListTS(const ForwardListTS& copy)
		{
			m_tac.init();
			m_nodeHead = 0;
			m_pLastNode = (Node*)&m_nodeHead;
			Node* node = copy.firstNode();
			while (node)
			{
				push(node->m_value);
				node = node->next();
			}
		}
		~ForwardListTS()
		{
			clear();
			m_tac.release();
		}

		ForwardListTS& operator = (const ForwardListTS& copy) 
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

		Node*	firstNode() const	{ return (Node*)m_nodeHead;	}

		Node*	push(const Type& value)		{ return (Node*)_FuncMain(0, (uintptr)&value);	}
		uint	nodeCount() const			{ return (uint)_FuncMain(2, 0);					}
		bln		deleteNode(Node* node)		{ return (bln)_FuncMain(3, (uintptr)node);		}
		void	clear()						{ _FuncMain(4,0);								}		
		Node* operator [] (size_t i) const	{ return (Node*)_FuncMain(1, (uintptr)i);		}

		

		



	private:
		XNOINL uintptr FASTCALL _FuncMain(uintptr i, uintptr data) const
		{
			typedef ForwardListTS<Type> Class;
			typedef uintptr (Class::*MemFunc)(uintptr);
			static const MemFunc lFuncs[] = { &Class::_Push, &Class::_GetNode, &Class::_NodeCount, &Class::_DeleteNode, &Class::_Clear};

			m_tac.lock();
			uintptr ret = (((Class*)this)->*(lFuncs[i]))(data);
			m_tac.unlock();
			return ret;
		}
		
		uintptr _Push(uintptr valuePtr)
		{
			Node* newNode = new Node(*((Type*)valuePtr));
			m_pLastNode->m_next = newNode;
			m_pLastNode = newNode;
			return (uintptr)newNode;
		}
		uintptr _NodeCount(uintptr unused)
		{
			uintptr n = 0;
			Node* iter = firstNode();
			while(iter)
			{
				iter = iter->next();
				n++;
			}
			return n;
		}
		uintptr _GetNode(uintptr index)
		{
			Node* iter = firstNode();
			while (((uintptr)iter) * index)
			{
				iter = iter->next();
				index--;
			}
			return (uintptr)iter;
		}
		uintptr _Clear(uintptr unused)
		{
			Node* iter = firstNode();
			m_nodeHead = 0;
			m_pLastNode = (Node*)&m_nodeHead;
			while (iter)
			{
				Node* tmp = iter;
				iter = iter->next();
				delete tmp;
			}
			return 0;
		}
		uintptr _DeleteNode(uintptr nodePtr)
		{
			const Node* node = (Node*)nodePtr;
			if(node == nullptr) return 0;
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
					return 1;
				}

				iterPre = iter;
				iter = iter->next();
			}
			return 0;
		}
	};
}