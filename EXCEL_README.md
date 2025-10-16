# Excel Number Generator

This script creates an Excel file with numbers.

## Requirements

- Python 3.x
- openpyxl library

## Installation

Install the required library:

```bash
pip install openpyxl
```

## Usage

Run the script:

```bash
python3 create_excel.py
```

This will create a file named `numbers.xlsx` in the current directory.

## Output

The generated Excel file contains:
- **Column A**: Numbers from 1 to 100 (with header "Number")
- **Columns C-L**: A 10x10 grid of numbers from 1 to 100 (with header "Grid of Numbers")

## Example

```bash
$ python3 create_excel.py
Excel file 'numbers.xlsx' created successfully!
- Column A contains numbers 1 to 100
- Columns C-L contain a 10x10 grid of numbers 1 to 100
```
