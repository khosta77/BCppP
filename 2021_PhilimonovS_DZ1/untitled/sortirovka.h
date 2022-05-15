#ifndef SORTIROVKA_H
#define SORTIROVKA_H


class sortirovka
{
private:
    int N =100000;
public:  
    sortirovka();

    int pyzirek(int N);

    int vstavka(int N);

    int vstqsortRecursiveavka(int N);
    void qsortRecursive(int *mas, int size);

    int vibor(int N);

    int sorto(int N);

    int Gnome_sort(int N);

    ~sortirovka();
};

#endif // SORTIROVKA_H
