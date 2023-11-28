#include <iostream>
#include "s_ln_list_dec.h"

Slist::~Slist() 
{
	while (m_head) {
		Node* temp = m_head;
		m_head = m_head->m_next_ptr;
		delete temp;
	}
}

void Slist::push_front(int data)
{
	Node* new_node = new Node{data, m_head};
    m_head = new_node;
}

void Slist::push_back(int data) 
{
	Node* new_node = new Node{data, nullptr};
    	if (!m_head) {
            m_head = new_node;
            return;
        }

        Node* current = m_head;

        while (current->m_next_ptr) {
            current = current->m_next_ptr;
        }

    current->m_next_ptr = new_node;
}
 
void Slist::pop_front() {
	if (!m_head) {
    	std::cout << "List is empty.in pop_front()" << std::endl;
        return;
    }

    Node* temp = m_head;
    m_head = m_head->m_next_ptr;
    delete temp;
}


 
void Slist::pop_back() {
	if (!m_head) {
    	std::cout << "List is empty. Cannot pop_back()." << std::endl;
   		return;
	}

	if (!m_head->m_next_ptr) {
    	delete m_head;
   		m_head = nullptr;
    	return;
	}

	Node* current = m_head;

		while (current->m_next_ptr->m_next_ptr) {
 	   		current = current->m_next_ptr;
		}

	delete current->m_next_ptr;
	current->m_next_ptr = nullptr;
}

void Slist::print_list() {
	Node* current = m_head;
    
		while (current) {
            std::cout << current->m_data << " ";
            current = current->m_next_ptr;
        }
        std::cout << std::endl;
}	
