#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template <class T>
class Lista {
private:
	struct listEl {
		T content;
		struct listEl* next;
	};
	listEl* head;
	listEl* tail;
	int noEl;

public:
	Lista() {
		head = tail = NULL;
		noEl = 0;
	}

	Lista(const Lista<T>&);

	Lista<T>& operator=(const Lista<T>&);

	virtual ~Lista();

	int velicina() const { return noEl; }

	bool prazno() const { return head == NULL ? 1 : 0; }

	bool dodajElement(int, const T&);

	bool izbrisiElement(int);

	bool izlistaj(int, T&)const;

	void izbrisi();
};


template <class T>
ostream& operator<<(ostream& out, const Lista<T>& rl) {
	out << endl;
	out << "--------" << endl;
	for (int i = 1; i <= rl.velicina(); i++) {
		if (i != 1) out << ", ";
		T res;
		rl.izlistaj(i, res);
		out << res;
	}
	out << endl << "--------" << endl;
	return out;
}

template <class T>
Lista<T>::Lista(const Lista<T>& rl) {
	head = NULL;
	tail = NULL;
	noEl = 0;

	for (int i = 1; i <= rl.noEl; i++) {
		T res;
		if (rl.izlistaj(i, res))
			dodajElement(i, res);
	}
}

template <class T>
Lista<T>& Lista<T>::operator=(const Lista<T>& rl) {
	if (this != &rl) {
		izbrisi();
		head = NULL;
		tail = NULL;
		noEl = 0;

		for (int i = 1; i <= rl.noEl; i++) {
			T res;
			if (rl.izlistaj(i, res))
				dodajElement(i, res);
		}
	}
	return *this;
}

template <class T>
Lista<T>::~Lista() {
	while (!prazno())
		izbrisiElement(1);
}

template <class T>
bool Lista<T>::dodajElement(int n, const T& newContent) {
	if (n < 1 || n > noEl + 1)
		return false;
	else {
		listEl* newEl = new listEl;
		if (newEl == NULL)
			return false;
		else {
			newEl->content = newContent;
			if (n == 1) {
				newEl->next = head;
				head = newEl;
			}
			else if (n == noEl + 1) {
				newEl->next = NULL;
				tail->next = newEl;
			}
			else {
				listEl* temp = head;
				for (int i = 2; i < n; i++)
					temp = temp->next;
				newEl->next = temp->next;
				temp->next = newEl;
			}
			noEl++;
			if (newEl->next == NULL)
				tail = newEl;
			return true;
		}
	}
}

template <class T>
bool Lista<T>::izbrisiElement(int n) {
	if (n < 1 || n > noEl)
		return false;
	else {
		if (n == 1) {
			listEl* del = head;
			head = head->next;
			if (tail == del)
				tail = NULL;
			delete del;
			noEl--;
		}
		else {
			listEl* temp = head;
			for (int i = 2; i < n; i++)
				temp = temp->next;
			listEl* del = temp->next;
			temp->next = del->next;
			if (tail == del)
				tail = temp;
			delete del;
			noEl--;
		}
		return true;
	}
}

template <class T>
bool Lista<T>::izlistaj(int n, T& retVal) const {
	if (n < 1 || n > noEl)
		return false;
	else {
		if (n == 1)
			retVal = head->content;
		else if (n == noEl)
			retVal = tail->content;
		else {
			listEl* temp = head;
			for (int i = 1; i < n; i++)
				temp = temp->next;
			retVal = temp->content;
		}
		return true;
	}
}

template <class T>
void Lista<T>::izbrisi() {
	while (!prazno())
		izbrisiElement(1);
}
#endif
