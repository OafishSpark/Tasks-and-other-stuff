#include <iostream>
#include <vector>


using Matrix = std::vector<std::vector<int>>;

//only square
Matrix transitiveClosure(Matrix& graph) // using Floyd-Warshall Algorithm 
{
    Matrix answer{ graph };
    int n{ int(graph.size()) };
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                answer[i][j] = answer[i][j] | (answer[i][k] & answer[k][j]);
            }
        }
    }
    return answer;
}

//only square
Matrix sumOfRows(Matrix& matrix)
{
    int n{ int(matrix.size()) };
    Matrix answer(n, { 0, 0 });
    for (int i = 0; i < n; ++i)
    {
        answer[i][1] = i;
        for (int j = 0; j < n; ++j)
        {
            answer[i][0] += static_cast<int>(matrix[i][j]);
        }
    }
    return answer;
}

void swapRows(std::vector<int>& a, std::vector<int>& b)
{
    std::vector<int> temp{ a };
    a = b;
    b = temp;
}

//sorting by 0 elem
void columnQuickSorting(Matrix& column, int startIndex, int finishIndex)
{
    //computing dividingElemIndex
    if (finishIndex > startIndex)
    {
        int dividingElem{ 0 }, s{ startIndex }, f{ finishIndex };
        for (int i = startIndex; i < finishIndex; ++i)
        {
            dividingElem += column[i][0];
        }
        dividingElem /= ((finishIndex - startIndex != 0) ? (finishIndex - startIndex) : (1));
        while (s <= f)
        {
            while (column[s][0] > dividingElem)
            {
                ++s;
            }
            while (column[f][0] < dividingElem)
            {
                --f;
            }
            if (f <= s)
            {
                break;
            }
            swap(column[s++], column[f--]);
        }
        columnQuickSorting(column, startIndex, f);
        columnQuickSorting(column, f + 1, finishIndex);
    }
}

// for columns n x 2, where second elem is original index 
Matrix permutationMatrix(Matrix column)
{
    int n{ int(column.size()) };
    Matrix answer(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        answer[i][column[i][1]] = 1;
    }
    return answer;
}

void swapNums(int& a, int& b)
{
    a += b;
    b = a - b;
    a = a - b;
}

//only square
Matrix transpose(Matrix& matrix)
{
    Matrix answer(matrix);
    int n{ int(matrix.size()) }, t{ 1 };
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = t++; j < n; ++j)
        {
            swapNums(answer[i][j], answer[j][i]);
        }
    }
    return answer;
}

Matrix operator*(const Matrix& mtrx1, const Matrix& mtrx2)
{
    int n{ int(mtrx1.size()) }, m{ int(mtrx2[0].size()) };
    Matrix answer(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < mtrx2.size(); ++k)
            {
                answer[i][j] += mtrx1[i][k] * mtrx2[k][j];
            }
        }
    }
    return answer;
}

void printMatrix(Matrix& matrix)
{
    int n{ int(matrix.size()) }, m{ int(matrix[0].size()) };
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool ifMatrixOfOnes(Matrix matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

//only square
Matrix zeroSymetric(Matrix& matrix)
{
    Matrix answer(0);
    int n{ int(matrix.size()) }, t{ 1 };
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = t++; j < n; ++j)
        {
            if ((matrix[j][i] == 0) && (matrix[i][j] == 0))
            {
                answer.push_back({ i, j });
            }
        }
    }
    return answer;
}

int main()
{
    Matrix A{
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    //
    std::cout << "Matrix A is :\n";
    printMatrix(A);
    std::cout << std::endl;
    //
    // 1)
    Matrix T = transitiveClosure(A);
    //
    std::cout << "Matrix T is :\n";
    printMatrix(T);
    std::cout << std::endl;
    //
    // 2)
    if (ifMatrixOfOnes(T))
    {
        std::cout << " Matrix is irreducible\n";
    }
    else
    {
        // 3)
        Matrix S{ sumOfRows(T) };
        columnQuickSorting(S, 0, S.size() - 1);
        Matrix P{ permutationMatrix(S) };
        //
        std::cout << "Matrix P is :\n";
        printMatrix(P);
        std::cout << std::endl;
        //
        Matrix tP{ transpose(P) };
        Matrix F{ P * T * tP };
        //
        std::cout << "Matrix F is :\n";
        printMatrix(F);
        std::cout << std::endl;
        //
        // 4)
        Matrix zeros{ zeroSymetric(F) };
        if (zeros.size() == 0)
        {
            std::cout << " Matrix is associated with unilaterally connected graph\n" << std::endl;
        }
        else
        {
            std::cout << "Matrix has zero symmetric w.r.t. main diagonal in elems with indeces:\n";
            printMatrix(zeros);
            std::cout << std::endl;
        }
        // 5)
        Matrix sA{ P * A * tP };
        //
        std::cout << "Matrix sA is :\n";
        printMatrix(sA);
        std::cout << std::endl;
        //
    }
    //
    std::cout << "The End!\n";
}
