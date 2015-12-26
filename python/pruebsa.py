>>> def samesign(a, b):
        return a * b > 0

>>> def bisect(func, low, high):
    'Find root of continuous function where f(low) and f(high) have opposite signs'

    assert not samesign(func(low), func(high))

    for i in range(54):
        midpoint = (low + high) / 2.0
        if samesign(func(low), func(midpoint)):
            low = midpoint
        else:
            high = midpoint

    return midpoint

>>> def f(x):
        return -26 + 85*x - 91*x**2 +44*x**3 -8*x**4 + x**5

>>> x = bisect(f, 0, 1)
>>> print x, f(x)
0.557025516287 3.74700270811e-16
