
from operations import*


if __name__ == '__main__':
    print('| x4| x1| x2| x3| d | b | y4| y3| y2| y1|')
    print('| 1 | 1 | 1 | 1 | - | - | - | - | - | - |')
    print('| 0 | 1 | 1 | 1 | - | - | - | - | - | - |')
    print('| 1 | 1 | 1 | 0 | - | - | - | - | - | - |')
    print('| 0 | 1 | 1 | 0 | - | - | - | - | - | - |')
    print('| 1 | 1 | 0 | 1 | - | - | - | - | - | - |')
    print('| 0 | 1 | 0 | 1 | - | - | - | - | - | - |')
    print('| 1 | 1 | 0 | 0 | - | - | 1 | 0 | 1 | 1 |')
    print('| 0 | 1 | 0 | 0 | - | - | 1 | 0 | 1 | 0 |')
    print('| 1 | 0 | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 1 |')
    print('| 0 | 0 | 1 | 1 | 0 | 1 | 1 | 0 | 0 | 0 |')
    print('| 1 | 0 | 1 | 0 | 0 | 1 | 0 | 1 | 1 | 1 |')
    print('| 0 | 0 | 1 | 0 | 1 | 0 | 0 | 1 | 1 | 0 |')
    print('| 1 | 0 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |')
    print('| 0 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 0 | 0 |')
    print('| 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 1 | 1 |')
    print('| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |')
   
    print('-' * 100)
    vector_Xout1 = [[0], [1], [0], [1], [0], [1], [0], [1], [0], [1], [0], [0], [0], [0], [0], [0]]
    vector_Xout2 = [[1], [1], [0], [0], [1], [1], [0], [0], [1], [1], [0], [0], [0], [0], [0], [0]]
    vector_Xout3 = [[0], [0], [1], [1], [1], [1], [0], [0], [0], [0], [0], [0], [0], [0], [0], [0]]
    vector_Xout4 = [[0], [0], [0], [0], [0], [0], [1], [1], [1], [1], [0], [0], [0], [0], [0], [0]]
    custom_operands = ['A', 'B', 'C', 'D']
    print('-' * 100)
    print('Y1 PCNF minimization', minimize_PCNF(vector_Xout1, custom_operands))
    print('-' * 100)
    print('Y2 PCNF minimization', minimize_PCNF(vector_Xout2, custom_operands))
    print('-' * 100)
    print('Y3 PCNF minimization', minimize_PCNF(vector_Xout3, custom_operands))
    print('-' * 100)
    print('Y4 PCNF minimization', minimize_PCNF(vector_Xout4, custom_operands))
    print('-' * 100)

    vector_X3 = [[0], [1], [1], [0], [1], [0], [0], [1]]
    vector_Dnext = [[0], [0], [0], [1], [0], [1], [1], [1]]

    custom_operands = ['A', 'B', 'C']
    print('-' * 100)
    print('PCNF ', build_PCNF(vector_X3, custom_operands))
    print('PCNF minimization', minimize_PCNF(vector_X3, custom_operands))
    print('-' * 100)
    print('PCNF', build_PCNF(vector_Dnext, custom_operands))
    print('PCNF minimization', minimize_PCNF(vector_Dnext, custom_operands))
    print('-' * 100)