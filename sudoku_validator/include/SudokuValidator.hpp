#ifndef SUDOKUVALIDATOR_HPP
#define SUDOKUVALIDATOR_HPP

#include <vector>

using uint = unsigned int;

class SudokuValidator
{
public:
    SudokuValidator();
    explicit SudokuValidator(const std::vector<std::vector<uint>>& initList);
    ~SudokuValidator() = default;

    SudokuValidator(const SudokuValidator& other) = default;
    SudokuValidator(SudokuValidator&& other) = default;

    SudokuValidator& operator=(const SudokuValidator& other) = default;
    SudokuValidator& operator=(SudokuValidator&& other) = default;

    bool isValidSol() const;

private:
    const size_t _fieldSize;
    std::vector<std::vector<uint>> _field;
};

#endif
