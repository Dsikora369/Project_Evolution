#include "Animal.h"
#include "FitnesFunction.h"
char Animal::changeb(char a, int n)
{
    char x;
    if (a & (1 << n))
    {
        a &= ~(1 << n);
    }
    else
    {
        a |= (1 << n);
    }
    x = a;
    return x;

}
bool Animal:: inlist(int a, int* list, int len)
{
    bool res = false;
    for (int i = 0; i < len; i++)
    {
        if (list[i] == a)
        {
            res = true;
        }
    }
    return res;
}
Animal:: Animal()
{
}
Animal:: Animal(int n)
{
    srand(time(NULL));
    genome.resize(n);
    for (int i = 0; i < n; i++)
    {
        
        genome[i] = rand() % 256;
    }
}
Animal:: Animal(vector <char> v)
{
    genome = v;
}
Animal Animal:: mutate_new(int n, int m)
{
    Animal new_animal;
    new_animal.genome = genome;
    if (n > genome.size())
    {
        n = genome.size();
        }
        if (m > 8)
        {
            m = 8;
        }
        int* list_changed = new int[n];
        for (int i = 0; i < n; i++)
        {
            srand(time(NULL));
            int a = rand() % genome.size();
            while (inlist(a, list_changed, n))
            {
                a = rand() % genome.size();
            }
            list_changed[i] = a;
            int am = rand() % (m + 1);
            int* list_num = new int[am];
            for (int i = 0; i < am; i++)
            {
                int change = rand() % 8;
                while (inlist(change, list_num, am))
                {
                    change = rand() % 8;
                }
                list_num[i] = change;
                new_animal.genome[a] = changeb(new_animal.genome[a], change);
            }
        }
        return new_animal;
    }
    void Animal:: mutate_old(int n, int m)
    {
        if (n > genome.size())
        {
            n = genome.size();
        }
        if (m > 8)
        {
            m = 8;
        }
        int* list_changed = new int[n];
        for (int i = 0; i < n; i++)
        {
            srand(time(NULL));
            int a = rand() % genome.size();
            while (inlist(a, list_changed, n))
            {
                a = rand() % genome.size();
            }
            list_changed[i] = a;
            int am = rand() % (m + 1);
            int* list_num = new int[am];
            for (int i = 0; i < am; i++)
            {
                int change = rand() % 8;
                while (inlist(change, list_num, am))
                {
                    change = rand() % 8;
                }
                list_num[i] = change;
                genome[a]=changeb(genome[a], change);
            }
        }
        

    }
    Animal Animal:: breed(Animal& A)
    {
        Animal new_A(A.genome.size());
        for (int i = 0; i < genome.size(); i++)
        {
            new_A.genome[i] = (genome[i] + A.genome[i]) / 2;
        }
        return new_A;

    }
    void Animal:: output_console()
    {
        if (genome.size()==0)
        {
            cout << "Empty vector, nothing to input in console" << endl;
        }
        for (int i = 0; i < genome.size(); i++)
        {
            cout << genome[i] << " ";
        }
        cout << endl;
    }
    double Animal:: fitness(FitnesFunction& FF)
    {
        int n;
        unsigned char* copy_genome = new unsigned char[genome.size()];
        if (FF.n_return() > genome.size())
        {
            n = genome.size();
        }
        else
        {
            n = FF.n_return();
        }
        for (int i = 0; i < n; i++)
        {
            copy_genome[i] = genome[i];
        }
        return FF.fitFun(copy_genome);
        delete[] copy_genome;
    }
    void Animal:: output_file(string name)
    {
        ofstream fout;
        fout.open(name);
        if (genome.size() == 0)
        {
            cout << "Empty vector, nothing to input in file" << endl;
            fout.close();
        }
        else {
            for (int i = 0; i < genome.size(); i++)
            {
                fout << genome[i] << " ";
            }
            fout << endl;
            fout.close();
        }
    }
    void Animal:: input_console()
    {
        string s;
        cout << "Enter vector --> ";
        getline(cin, s);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                genome.push_back(s[i]);
            }
        }
    }
    void Animal:: input_file(string name)
    {
        fstream f;
        f.open(name, ios::in);
        char s = 'f';
        int i = 0;
        while (f)
        {
            f >> s;
            genome.push_back(s);
        }
        genome.pop_back();
        f.close();
    }

