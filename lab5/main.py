
from nanologic import *


if __name__ == '__main__':
    print('| V | q3| q2| q1| h3| h2| h1|q3*|q2*|q1*|')
    print('| 0 | 1 | 1 | 1 | 0 | 0 | 0 | 1 | 1 | 1 |')
    print('| 1 | 1 | 1 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |')
    print('| 0 | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 | 0 |')
    print('| 1 | 1 | 0 | 1 | 0 | 1 | 1 | 1 | 1 | 0 |')
    print('| 0 | 1 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 1 |')
    print('| 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 |')
    print('| 0 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |')
    print('| 1 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 |')
    print('| 0 | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 |')
    print('| 1 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 1 |')
    print('| 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |')
    print('| 1 | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 1 | 0 |')
    print('| 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 1 |')
    print('| 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 |')
    print('| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |')
    print('| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 0 |')
    print('-' * 100)
    h3 = [[1], [0], [0], [0], [0], [0], [0], [0], [1], [0], [0], [0], [0], [0], [0], [0]]
    h2 = [[1], [0], [0], [0], [1], [0], [0], [0], [1], [0], [0], [0], [1], [0], [0], [0]]
    h1 = [[1], [0], [1], [0], [1], [0], [1], [0], [1], [0], [1], [0], [1], [0], [1], [0]]
    q1 = [[1], [0], [0], [1], [1], [0], [0], [1], [1], [0], [0], [1], [1], [0], [0], [1]]
    q2 = [[1], [0], [0], [0], [0], [1], [1], [1], [1], [0], [0], [0], [0], [1], [1], [1]]
    q3 = [[1], [0], [0], [0], [0], [0], [0], [0], [0], [1], [1], [1], [1], [1], [1], [1]]
    q1T = [[0], [0], [1], [1], [0], [0], [1], [1], [0], [0], [1], [1], [0], [0], [1], [1]]
    q2T = [[0], [0], [0], [0], [1], [1], [1], [1], [0], [0], [0], [0], [1], [1], [1], [1]]
    q3T = [[0], [0], [0], [0], [0], [0], [0], [0], [1], [1], [1], [1], [1], [1], [1], [1]]
    custom_operands = ['q3', 'q2', 'q1', 'V']

    print('-' * 100)
    print('PDNF minimization [h1]', minimize_PDNF(h1, custom_operands))
    print('-' * 100)
    print('PDNF minimization [h2]', minimize_PDNF(h2, custom_operands))
    print('-' * 100)
    print('PDNF minimization [h3]', minimize_PDNF(h3, custom_operands))
    print('-' * 100)
    print('-' * 100)
    print('PDNF minimization [q1]', minimize_PDNF(q1, custom_operands))
    print('-' * 100)
    print('PDNF minimization [q2]', minimize_PDNF(q2, custom_operands))
    print('-' * 100)
    print('PDNF minimization [q3]', minimize_PDNF(q3, custom_operands))
    print('-' * 100)
    print('-' * 100)
    print('PDNF minimization [q1*]', minimize_PDNF(q1T, custom_operands))
    print('-' * 100)
    print('PDNF minimization [q2*]', minimize_PDNF(q2T, custom_operands))
    print('-' * 100)
    print('PDNF minimization [q3*]', minimize_PDNF(q3T, custom_operands))
    print('-' * 100)