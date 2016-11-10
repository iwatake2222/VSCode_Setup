# -*- coding: utf-8 -*-
""" main.py
Sample Code
"""
import sub

###
# Main
###
def main():
    """ main function
    """
    print('Hello World')
    var_a = 1
    var_b = 2
    var_c = var_a + var_b
    print(var_c)

    func_a(123)
    sub.func1()
    sub.func2()

    print('Exit')

###
# Sub functions
###
def func_a(value):
    """ func_a function
    Args:
        value (int): The value to be displayed
    Returns:
        str: The return value.
    """
    print('funcA is called with ' + str(value))
    return str(value)


if __name__ == "__main__":
    main()
