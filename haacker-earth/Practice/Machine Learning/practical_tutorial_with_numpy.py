
import numpy as np
# print(np.__version__)

# L = list(range(10))
# print([str(c) for c in L])

# test = np.zeros(10, dtype='int')
# test = np.ones((3, 5), dtype='float')
# test = np.full((3, 5), 1.23)
# test = np.arange(0, 20, 2)
# test = np.linspace(0, 1, 5)
# test = np.random.normal(0, 1, (3, 3))
# test = np.eye(3)
# print(test)
#
# np.random.seed(0)
#
# x1 = np.random.randint(10, size=6)
# x2 = np.random.randint(10, size=(3, 4))
# x3 = np.random.randint(10, size=(3, 4, 5))
# print(x3.ndim, x3.shape, x3.size)
#
# x1 = np.array([4, 3, 4, 4, 8, 4])
# print(x1)
#
# x = np.arange(10)
# print(x[::-1])
#
# x = np.array([1, 2, 3])
# y = np.array([3, 2, 1])
# z = [32]
# print(np.concatenate([x, y, z]))
#
# grid = np.array([[1, 2, 3], [4, 5, 6]])
# print(np.concatenate([grid, grid], axis=1))
#
# x = [3, 4, 5]
# z = [[9], [9]]
# print(np.vstack([grid, x]))
# print(np.hstack([grid, z]))

grid = np.arange(16).reshape((4, 4))
upper, lower = np.vsplit(grid, [2])
print(upper)
print(lower)



