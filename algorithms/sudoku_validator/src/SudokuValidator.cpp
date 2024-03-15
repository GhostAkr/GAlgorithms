#include "../include/SudokuValidator.hpp"

SudokuValidator::SudokuValidator()
: _fieldSize(9)
, _field()
{}

SudokuValidator::SudokuValidator(const std::vector<std::vector<uint>>& initList)
: _fieldSize(9)
, _field(initList)
{}

bool SudokuValidator::isValidSol() const
{
    std::vector<int> rowSum(_fieldSize, 0);
    std::vector<int> colSum(_fieldSize, 0);
    std::vector<int> sqSum(_fieldSize, 0);

    for (size_t rowIx = 0; rowIx < _field.size(); ++rowIx)
    {
        for (size_t colIx = 0; colIx < _field[rowIx].size(); ++colIx)
        {
            uint val = _field[rowIx][colIx];
            rowSum[rowIx] += val;
            colSum[colIx] += val;

            const size_t sqInRow = 3;
            const size_t sqSize = 3;
            const size_t squareIx = (rowIx / sqSize) * sqInRow + (colIx / sqSize);
            sqSum[squareIx] += val;
        }
    }

    const int targetSum = 45;
    for (size_t sumIx = 0; sumIx < _fieldSize; ++sumIx)
    {
        if (rowSum[sumIx] != targetSum 
            || colSum[sumIx] != targetSum 
            || sqSum[sumIx] != targetSum
        )
        {
            return false;
        }
    }

    return true;
}
