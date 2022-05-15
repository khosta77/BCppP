#ifndef LIST_H
#define LIST_H

struct spicok{
  int field; // поле данных
  struct spicok *next; // указатель на следующий элемент
  struct spicok *prev; // указатель на предыдущий элемент

};

class list{
private:

public:
    list();
};

#endif // LIST_H
