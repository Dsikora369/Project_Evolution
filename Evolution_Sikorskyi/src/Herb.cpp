#include "Animal.h"
#include "FitnesFunction.h"
#include "Herb.h"
Herb :: Herb()
    {
    size = 0;
    }
    void  Herb::add(Animal& A)
    {
        Animal* new_herb = new Animal[size + 1];
        for (int i = 0; i < size; i++)
        {
            new_herb[i] = herb[i];
        }
        new_herb[size] = A;
        delete[] herb;
        herb = new_herb;
        size++;

    }
    void Herb:: add(Animal* A, int sizeA)
    {
        Animal* new_herb = new Animal[size + sizeA];
        for (int i = 0; i < size; i++)
        {
            new_herb[i] = herb[i];
        }
        for (int i = 0; i < sizeA; i++)
        {
            new_herb[size + i] = A[i];
        }
        delete[] herb;
        herb = new_herb;
        size+=sizeA;
    }
    void Herb:: selection(int m, FitnesFunction & FF)
    {
        vector<double> Flist(size);
        Animal* selected = new Animal[m];
        int* indexlist = new int[m];
        for (int i = 0; i < size; i++)
        {
            Flist[i] = herb[i].fitness(FF);
        }
        sort(Flist.begin(), Flist.end());
        double edge = Flist[m - 1];
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (herb[i].fitness(FF) < edge)
            {
                indexlist[j] = i;
                j++;
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (j < m)
            {
                {
                    if (herb[i].fitness(FF) == edge)
                    {
                        indexlist[j] = i;
                        j++;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            selected[i] = herb[indexlist[i]];
        }
        delete[] herb;
        herb = selected;
        delete[] indexlist;
        size = m;
    }
    void Herb:: crossover(int m, FitnesFunction& FF)
    {
        vector<double> Flist(size);
        Animal* selected = new Animal[m];
        Animal* selected2 = new Animal[m+size];
        int* indexlist = new int[m];
        for (int i = 0; i < size; i++)
        {
            Flist[i] = herb[i].fitness(FF);
        }
        sort(Flist.begin(), Flist.end());
        double edge = Flist[m - 1];
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (herb[i].fitness(FF) < edge)
            {
                indexlist[j] = i;
                j++;
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (j < m)
            {
                {
                    if (herb[i].fitness(FF) == edge)
                    {
                        indexlist[j] = i;
                        j++;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            selected[i] = herb[indexlist[i]];
        }
        for (int i = 0; i < size; i++)
        {
            selected2[i] = herb[i];
        }
        for (int i = 0; i <  m; i++)
        {
            srand(time(NULL));
            int to_breed = rand() % m;
            while (to_breed == indexlist[i])
            {
                to_breed = rand() % m;
            }
            selected2[size+i] = herb[to_breed].breed(herb[indexlist[i]]);
        }
        delete[] herb;
        herb = selected2;
        size += m;
    }
    void Herb:: output_console()
    {
        for (int i = 0; i < size; i++)
        {
            herb[i].output_console();
        }
    }

