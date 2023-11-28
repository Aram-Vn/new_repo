#ifndef S_LN_LIST_DEC_H
#define S_LN_LIST_DEC_H
 
class Slist
{
public:
	~Slist();

	void push_front(int data);
	void push_back(int data);
	void pop_front();
	void pop_back();

	void print_list();

private:
	struct Node
	{
		int m_data;
		Node* m_next_ptr;
	};

	Node* m_head{};
};


#endif //s_ln_list_dec.h
