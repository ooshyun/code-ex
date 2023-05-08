import py 
if __name__ == "__main__":
    # py.testBalancedParenthesesinExpression()
    # py.testQueueWithTwoStacks()

    """
    getsizeof() method calls the __sizeof__() method o the object with an additional garbage collector overhead. 
    Hence the size returned by the getsize() method will be more than that returned by the __sizeof()__ method. 
    Refernence. https://www.geeksforgeeks.org/difference-between-__sizeof__-and-getsizeof-method-python/
    """
    import sys
    import numpy as np

    n_list = [i ** 2 for i in range(1000)]
    print(sys.getsizeof(n_list))            # 9016
    n_tuple = (i ** 2 for i in range(1000))
    print(sys.getsizeof(n_tuple))           # 112
    n_tuple = tuple(n_list)
    print(sys.getsizeof(n_tuple))           # 8040
    n_set = set(n_list)                     
    print(sys.getsizeof(n_set))             # 32984
    n_np = np.array(n_list)
    print(sys.getsizeof(n_np))              # 8104
    n_np = np.power(np.arange(1, 1000), 2)
    print(sys.getsizeof(n_np))              # 8096
    
    n_list = [i ** 2 for i in range(1000)]
    print(n_list.__sizeof__())           # 9000
    n_tuple = (i ** 2 for i in range(1000))
    print(n_tuple.__sizeof__())           # 96
    n_tuple = tuple(n_list)
    print(n_tuple.__sizeof__())           # 8024
    n_set = set(n_list)                     
    print(n_set.__sizeof__())             # 32968


    empty_list = list()
    empty_set = set()
    empty_tuple = tuple()

    print(sys.getsizeof(empty_list))        # 56
    print(sys.getsizeof(empty_set))         # 216
    print(sys.getsizeof(empty_tuple))       # 40

    print(empty_list.__sizeof__())          # 40
    print(empty_set.__sizeof__())           # 200
    print(empty_tuple.__sizeof__())         # 24

    