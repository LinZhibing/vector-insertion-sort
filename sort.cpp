
#include <cstdio>
#include <cstdlib>
#include "sort.h"
int ivector_length(int* v, int n)
{
    int sum;

    sum = 0;
    for (int i = 0; i < n; i++)
        sum += (v[i] < 0) ? -v[i] : v[i];

    return sum;
}

/*
 * insertion sort
 */
void insertion_sort(int** A, int n, int l, int r)
{
    int i;
    int* key;

    for (int j = l+1; j <= r; j++)
    {
        key = A[j];
        i = j - 1;

        while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n)))
        {
            A[i+1] = A[i];
            i = i - 1;
        }

        A[i+1] = key;
    }
}

/*
*   TO IMPLEMENT: Improved Insertion Sort for problem 1.
*/
void insertion_sort_im(int** A, int n, int l, int r)
{

    int* key;
    int left;
    int right;
    int pivot;

    for (int j = l+1; j <= r; j++)
    {
        key = A[j];

        left = l;
        right = j;
        if (ivector_length(A[j], n) < ivector_length(A[j - 1], n)){
            A[j] = A[j - 1];
            while (left <= right)
            {
                pivot = left - (left - right) / 2;


                if (ivector_length(A[pivot], n) > ivector_length(key, n)){
                    right = pivot - 1;
                }
                else {
                    left = pivot + 1;
                }

            }

            for (int i = j - 1; i >= right + 1; i--){

                A[i] = A[i - 1];

            }
            A[right + 1] = key;
        }

    }


}




/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is
 *    greater than the i-th element.
 */
bool check_sorted(int** A, int n, int l, int r)
{
    for (int i = l+1; i <= r; i++)
        if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
            return false;
    return true;
}


/*
 * generate sorted/reverse/random arrays of type hw1type
 */
int** create_ivector(int n, int m)
{
    int** iv_array;

    iv_array = new int*[m];
    for (int i = 0; i < m; i++)
        iv_array[i] = new int[n];

    return iv_array;
}

void remove_ivector(int** iv_array, int m)
{
    for (int i = 0; i < m; i++)
        delete[] iv_array[i];
    delete[] iv_array;
}

int** create_sorted_ivector(int n, int m)
{
    int** iv_array;

    iv_array = create_ivector(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            iv_array[i][j] = (i+j)/n;

    return iv_array;
}

int** create_reverse_sorted_ivector(int n, int m)
{
    int** iv_array;

    iv_array = create_ivector(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            iv_array[i][j] = ((m-i)+j)/n;

    return iv_array;
}

int** create_random_ivector(int n, int m, bool small)
{
    random_generator rg;
    int** iv_array;

    iv_array = create_ivector(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            rg >> iv_array[i][j];
            if (small)
                iv_array[i][j] %= 100;
            else
                iv_array[i][j] %= 65536;
        }

    return iv_array;
}
